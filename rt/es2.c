/*
In un sistema organizzato secondo il modello a memoria comune viene definita una risorsa astratta R
sulla quale si puo` operare mediante tre procedure identificate, rispettivamente, da ProcA, ProcB e Reset.
Le due procedure ProcA e ProcB, operano su variabili diverse della risorsa R e pertanto possono essere
eseguite concorrentemente tra loro senza generare interferenze. La procedura Reset opera su tutte le
variabili di R e quindi deve essere eseguita in modo mutuamente esclusivo sia con ProcA che con ProcB.

1) Se i tre processi PA, PB e PR invocano, rispettivamernte, le operazioni ProcA, ProcB e Reset,
descrivere una tecnica che consente ai processi PA e PB di eseguire le procedure da essi invocate
senza vincoli reciproci di mutua esclusione, garantendo invece la mutua esclusione con
l'esecuzione della procedura Reset invocata da PR. Nel risolvere il problema garantire la priorita`
alle esecuzioni di Reset rispetto a quelle di ProcA e ProcB.

2) Qualora i processi che invocano le procedure ProcA e ProcB siano piu` di due (PA1,......PAn e
PB1,....,PBm) riscrivere la soluzione garantendo anche la mutua esclusione tra due o piu`
attivazioni di ProcA e tra due o piu` attivazioni di ProcB.
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NESSUNO 0
#define STATO_A_O_B 1
#define STATO_RESET 2

struct gestore_t{
    sem_t mutex;
    sem_t semA, semB, semRes;

    int na,nb;
    int ca,cb;
    int stato;
} gestore;

void pausetta(void)
{
  struct timespec t;
  t.tv_sec = 0;
  t.tv_nsec = (rand()%10+1)*1000000;
  nanosleep(&t,NULL);
}

void init_gestore(struct gestore_t *g){
    sem_init(&g->mutex, 0, 1);

    sem_init(&g->semA, 0, 0);
    sem_init(&g->semB, 0, 0);
    sem_init(&g->semRes, 0, 0);

    g->na = g->nb = g->ca = g->cb = 0;
    g->stato = NESSUNO;
}

void StartA(struct gestore_t *g){
    sem_wait(&g->mutex);

    if (g->stato != STATO_RESET && g->na < 3) {
        g->stato = STATO_A_O_B;
        g->na++;
        sem_post(&g->semA);
    } else {
        g->ca++;
    }

    sem_post(&g->mutex);
    sem_wait(&g->semA);
}

void EndA(struct gestore_t *g){
    sem_wait(&g->mutex);
    g->na--;
    //g->stato = NESSUNO;
    if (g->ca > 0) {
        g->ca--;
        g->na++;
        sem_post(&g->semA);
    } else {
        g->stato = NESSUNO;
    }
    sem_post(&g->mutex);
}

void *A(void *arg){
    for (;;) {
        StartA(&gestore);
        putchar(*(char *)arg);
        EndA(&gestore);
        pausetta();
    }
    return 0;
}

void StartB(struct gestore_t *g){
    sem_wait(&g->mutex);

    if (g->stato != STATO_RESET && g->nb < 3) {
        g->stato = STATO_A_O_B;
        g->nb++;
        sem_post(&g->semB);
    } else {
        g->cb++;
    }

    sem_post(&g->mutex);
    sem_wait(&g->semB);
}

void EndB(struct gestore_t *g){
    sem_wait(&g->mutex);
    g->nb--;
    //g->stato = NESSUNO;
    if (g->cb > 0) {
        g->cb--;
        g->nb++;
        sem_post(&g->semB);
    } else {
        g->stato = NESSUNO;
    }
    sem_post(&g->mutex);
}

void *B(void *arg){
    for (;;) {
        StartB(&gestore);
        putchar(*(char *)arg);
        EndB(&gestore);
        pausetta();
    }
    return 0;
}

void StartReset(struct gestore_t *g){
    sem_wait(&g->mutex);
    g->stato = STATO_RESET;
    sem_post(&g->semRes);
    sem_post(&g->mutex);
    sem_wait(&g->semRes);
}

void *Reset(void *arg){
    for (;;) {
        StartA(&gestore);
        putchar(*(char *)arg);
        EndA(&gestore);
        pausetta();
    }
    return 0;
}

void EndReset(struct gestore_t *g){
    sem_wait(&g->mutex);
    //g->stato = NESSUNO;
    //sem_post(&g->semRes);
    if (g->ca != 0){
        g->ca--;
        g->na++;
        g->stato = STATO_A_O_B;
        sem_post(&g->semA);
    } else if (g->cb != 0){
        g->cb--;
        g->nb++;
        g->stato = STATO_A_O_B;
        sem_post(&g->semB);
    } else {
        g->stato = NESSUNO;
    }
    sem_post(&g->mutex);
    //sem_wait(&g->semRes);
}

int main(){
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

    pthread_create(&p, &a, Reset, (void *)"X");
    pthread_create(&p, &a, Reset, (void *)"x");

    pthread_attr_destroy(&a);

    /* aspetto 10 secondi prima di terminare tutti quanti */
    sleep(5);

    return 0;
}