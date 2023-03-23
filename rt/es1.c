/*
 * Copyright (C) 2004 by Paolo Gai
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*

Esercizio 1

Siano A, B, C, D ed E le procedure che un insieme di processi P1, P2,
..., PN possono invocare e che devono essere eseguite rispettando i
seguenti vincoli di sincronizzazione:

Sono possibili solo due sequenze di esecuzioni delle procedure,
sequenze tra loro mutuamente esclusive:

- la prima sequenza prevede che venga eseguita per prima la procedura
         A. a cui puo' seguire esclusivamente l'esecuzione di una o
         piu' attivazioni concorrenti della procedura B;

- la seconda sequenza e' costituita dall'esecuzione della procedura C
          a cui puo' seguire esclusivamente l'esecuzione della
          procedura D, o in alternativa a D della procedura E.

Una volta terminata una delle due sequenze una nuova sequenza puo'
essere di nuovo iniziata.

utilizzando il meccanismo dei semafori, realizzare le funzioni StartA,
EndA, StartB, EndB, .... , StartE, EndE che, invocate dai processi
clienti P1, P2, ..., PN rispettivamente prima e dopo le corrispondenti
procedure, garantiscano il rispetto dei precedenti vincoli. Nel
risolvere il problema non e' richiesta la soluzione ad eventuali
problemi di starvation.

*/


// usare semafori o variabili condition?
//#define USA_MUTEX
#define USA_SEM


#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/* Possibili stati in cui si puo' trovare la risorsa */
#define SEQUENZA_NESSUNO 0
#define SEQUENZA_A       1
#define SEQUENZA_B       2
#define SEQUENZA_C       3
#define SEQUENZA_D       4
#define SEQUENZA_E       5
#define SEQUENZA_D_o_E   6


/* NOTA BENE:

il testo in realtà non impone nessuna priorità tra (A e C) e (D ed
E). ciò vuol dire che in questo caso bastano 3 semafori privati:

- uno per A+C
- uno per B
- uno per D+E

in quanto mi interessa svegliare uno dei bloccati (sia esso A o C)
indipendentemente dal suo tipo.

Notare che, nonostante ci siano solo 3 semafori privati, continuano ad
essere necessari tutti e 5 gli stati.

L'esempio qui riportato propone una soluzione con 5 semafori privati/5
variabili condition, uno per ogni categoria di funzione. In questo
caso avere piu' semafori permette di dare priorità ad A rispetto a C,
e a D rispetto ad E.
*/


#ifdef USA_SEM

/* la struttura condivisa */
struct gestore_t {
  sem_t mutex;

  sem_t sa,sb,sc,sd,se;
  int ca,cb,cc,cd,ce;

  /* stato del sistema */
  int nb;  
  int stato;
} gestore;

/* inizializzazione della struttura condivisa */
void init_gestore(struct gestore_t *g)
{
  /* mutua esclusione */
  sem_init(&g->mutex,0,1);

  /* semafori e contatori privati */
  sem_init(&g->sa,0,0);
  sem_init(&g->sb,0,0);
  sem_init(&g->sc,0,0);
  sem_init(&g->sd,0,0);
  sem_init(&g->se,0,0);

  g->ca = g->cb = g->cc = g->cd = g->ce = 0;

  /* stato del sistema */
  g->nb = 0;
  g->stato = SEQUENZA_NESSUNO;
}

void StartA(struct gestore_t *g)
{
  sem_wait(&g->mutex);
  if (g->stato == SEQUENZA_NESSUNO) {
    /* non mi blocco! */
    g->stato = SEQUENZA_A;
    sem_post(&g->sa);
  }
  else {
    /* mi blocco */
    g->ca++;
  } 
  sem_post(&g->mutex);
  sem_wait(&g->sa);
}

void EndA(struct gestore_t *g)
{
  sem_wait(&g->mutex);

  g->stato = SEQUENZA_B;

  /* devo svegliare tutti i B pendenti */
  while (g->cb) {
    g->cb--;
    g->nb++;
    sem_post(&g->sb);
  }

  sem_post(&g->mutex);
}

void StartB(struct gestore_t *g)
{
  sem_wait(&g->mutex);

  if (g->stato == SEQUENZA_B) {
    /* devo contare i B perchè ce ne possono essere + di 1 */
    g->nb++;
    sem_post(&g->sb);
  }
  else {
    g->cb++;
  }

  sem_post(&g->mutex);
  sem_wait(&g->sb);
}

void sveglia_A_o_C(struct gestore_t *g)
{
  /* chiamata alla fine di B, D o E per controllare se devo svegliare
     qualcuno alla fine di una sequenza */
  if (g->ca) {
    g->ca--;
    g->stato = SEQUENZA_A;
    sem_post(&g->sa);
  } 
  else if (g->cc) {
    g->cc--;
    g->stato = SEQUENZA_C;
    sem_post(&g->sc);
  }
  else
    g->stato = SEQUENZA_NESSUNO;
}

void EndB(struct gestore_t *g)
{
  sem_wait(&g->mutex);

  g->nb--;

  if (g->nb == 0)
    sveglia_A_o_C(g);

  sem_post(&g->mutex);
}

void StartC(struct gestore_t *g)
{
  sem_wait(&g->mutex);
  if (g->stato == SEQUENZA_NESSUNO) {
    g->stato = SEQUENZA_C;
    sem_post(&g->sc);
  }
  else {
    g->cc++;
  } 
  sem_post(&g->mutex);
  sem_wait(&g->sc);
}

void EndC(struct gestore_t *g)
{
  sem_wait(&g->mutex);

  if (g->cd) {
    g->cd--;
    g->stato = SEQUENZA_D;
    sem_post(&g->sd);
  } 
  else if (g->ce) {
    g->ce--;
    g->stato = SEQUENZA_E;
    sem_post(&g->se);
  }
  else
    /* se non c'e' nessuno bloccato, so comunque che potra' entrare
       solo un D o un E */
    g->stato = SEQUENZA_D_o_E;

  sem_post(&g->mutex);
}

void StartD(struct gestore_t *g)
{
  sem_wait(&g->mutex);
  if (g->stato == SEQUENZA_D_o_E) {
    g->stato = SEQUENZA_D;
    sem_post(&g->sd);
  }
  else {
    g->cd++;
  } 
  sem_post(&g->mutex);
  sem_wait(&g->sd);
}

void EndD(struct gestore_t *g)
{
  sem_wait(&g->mutex);

  sveglia_A_o_C(g);

  sem_post(&g->mutex);
}

void StartE(struct gestore_t *g)
{
  sem_wait(&g->mutex);
  if (g->stato == SEQUENZA_D_o_E) {
    g->stato = SEQUENZA_E;
    sem_post(&g->se);
  }
  else {
    g->ce++;
  } 
  sem_post(&g->mutex);
  sem_wait(&g->se);
}

void EndE(struct gestore_t *g)
{
  sem_wait(&g->mutex);

  sveglia_A_o_C(g);

  sem_post(&g->mutex);
}

#endif


/* ------------------------------ */

#ifdef USA_MUTEX

/* questa implementazione ricalca le strutture dati definite nella
   versione con i semafori. anche qui le variabili condition per (A e
   C) e per (D ed E) potrebbero essere unificate. */

/* la struttura condivisa */
struct gestore_t {
  pthread_mutex_t mutex;

  pthread_cond_t sa,sb,sc,sd,se;
  int ca,cb,cc,cd,ce;

  /* stato del sistema */
  int nb;  
  int stato;
} gestore;

/* inizializzazione della struttura condivisa */
void init_gestore(struct gestore_t *g)
{
  pthread_mutexattr_t m_attr;
  pthread_condattr_t c_attr;

  pthread_mutexattr_init(&m_attr);
  pthread_condattr_init(&c_attr);

  pthread_mutex_init(&g->mutex, &m_attr);
  pthread_cond_init(&g->sa, &c_attr);
  pthread_cond_init(&g->sb, &c_attr);
  pthread_cond_init(&g->sc, &c_attr);
  pthread_cond_init(&g->sd, &c_attr);
  pthread_cond_init(&g->se, &c_attr);

  pthread_condattr_destroy(&c_attr);
  pthread_mutexattr_destroy(&m_attr);

  g->ca = g->cb = g->cc = g->cd = g->ce = 0;

  /* stato del sistema */
  g->nb = 0;
  g->stato = SEQUENZA_NESSUNO;
}

void StartA(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);

  while (g->stato != SEQUENZA_NESSUNO) {
    /* mi blocco */
    g->ca++;
    pthread_cond_wait(&g->sa,&g->mutex);
    g->ca--;
  }

  /* non mi blocco! */
  g->stato = SEQUENZA_A;

  pthread_mutex_unlock(&g->mutex);
}

void EndA(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);

  g->stato = SEQUENZA_B;

  /* devo svegliare tutti i B pendenti */
  if (g->cb)
    pthread_cond_broadcast(&g->sb);

  pthread_mutex_unlock(&g->mutex);
}

void StartB(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);

  while (g->stato != SEQUENZA_B) {
    g->cb++;
    pthread_cond_wait(&g->sb,&g->mutex);
    g->cb--;
  }

  /* devo contare i B perchè ce ne possono essere + di 1 */
  g->nb++;

  pthread_mutex_unlock(&g->mutex);
}

void sveglia_A_o_C(struct gestore_t *g)
{
  /* chiamata alla fine di B, D o E per controllare se devo svegliare
     qualcuno alla fine di una sequenza */
  if (g->ca) {
    pthread_cond_signal(&g->sa);
  } 
  else if (g->cc) {
    pthread_cond_signal(&g->sc);
  }

  // Nota: non è nella parte else!!! 
  g->stato = SEQUENZA_NESSUNO;
}

void EndB(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);

  g->nb--;
  if (g->nb == 0)
    sveglia_A_o_C(g);

  pthread_mutex_unlock(&g->mutex);
}

void StartC(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);
  while (g->stato != SEQUENZA_NESSUNO) {
    g->cc++;
    pthread_cond_wait(&g->sc,&g->mutex);
    g->cc--;
  }
  g->stato = SEQUENZA_C;
  pthread_mutex_unlock(&g->mutex);
}

void EndC(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);

  if (g->cd) {
    pthread_cond_signal(&g->sd);
  } 
  else if (g->ce) {
    pthread_cond_signal(&g->se);
  }

  /* a questo punto ho svegliato qualcuno dei thread bloccati, quindi
     mi metto in uno stato di attesa in cui può entrare solo un D o un
     E */
  g->stato = SEQUENZA_D_o_E;

  pthread_mutex_unlock(&g->mutex);
}

void StartD(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);
  while (g->stato != SEQUENZA_D_o_E) {
    g->cd++;
    pthread_cond_wait(&g->sd,&g->mutex);
    g->cd--;
  }

  g->stato = SEQUENZA_D;

  pthread_mutex_unlock(&g->mutex);
}

void EndD(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);

  sveglia_A_o_C(g);

  pthread_mutex_unlock(&g->mutex);
}

void StartE(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);
  while (g->stato != SEQUENZA_D_o_E) {
    g->ce++;
    pthread_cond_wait(&g->se,&g->mutex);
    g->ce--;
  }
  g->stato = SEQUENZA_E;
  pthread_mutex_unlock(&g->mutex);
}

void EndE(struct gestore_t *g)
{
  pthread_mutex_lock(&g->mutex);

  sveglia_A_o_C(g);

  pthread_mutex_unlock(&g->mutex);
}

#endif


/* ------------------------------ */


/* alla fine di ogni ciclo ogni thread aspetta un po'.
   Cosa succede se tolgo questa nanosleep? 
   di fatto solo i thread di tipo B riescono ad entrare --> starvation!!!!
   (provare per credere)
*/
void pausetta(void)
{
  struct timespec t;
  t.tv_sec = 0;
  t.tv_nsec = (rand()%10+1)*1000000;
  nanosleep(&t,NULL);
}




/* i thread */


void *A(void *arg)
{
  for (;;) {
    StartA(&gestore);
    putchar(*(char *)arg);
    EndA(&gestore);
    pausetta();
  }
  return 0;
}

void *B(void *arg)
{
  for (;;) {
    StartB(&gestore);
    putchar(*(char *)arg);
    EndB(&gestore);
    pausetta();
  }
  return 0;
}

void *C(void *arg)
{
  for (;;) {
    StartC(&gestore);
    putchar(*(char *)arg);
    EndC(&gestore);
    pausetta();
  }
  return 0;
}

void *D(void *arg)
{
  for (;;) {
    StartD(&gestore);
    putchar(*(char *)arg);
    EndD(&gestore);
    pausetta();
  }
  return 0;
}

void *E(void *arg)
{
  for (;;) {
    StartE(&gestore);
    putchar(*(char *)arg);
    EndE(&gestore);
    pausetta();
  }
  return 0;
}


/* la creazione dei thread */



int main()
{
  pthread_attr_t a;
  pthread_t p;
  
  /* inizializzo il mio sistema */
  init_gestore(&gestore);

  /* inizializzo i numeri casuali, usati nella funzione pausetta */
  srand(555);

  pthread_attr_init(&a);

  /* non ho voglia di scrivere 10000 volte join! */
  pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

  pthread_create(&p, &a, A, (void *)"a");
  pthread_create(&p, &a, A, (void *)"A");

  pthread_create(&p, &a, B, (void *)"B");
  pthread_create(&p, &a, B, (void *)"b");
  pthread_create(&p, &a, B, (void *)"x");

  pthread_create(&p, &a, C, (void *)"C");
  pthread_create(&p, &a, C, (void *)"c");

  pthread_create(&p, &a, D, (void *)"D");
  pthread_create(&p, &a, D, (void *)"d");

  pthread_create(&p, &a, E, (void *)"E");
  pthread_create(&p, &a, E, (void *)"e");

  pthread_attr_destroy(&a);

  /* aspetto 10 secondi prima di terminare tutti quanti */
  sleep(10);

  return 0;
}


