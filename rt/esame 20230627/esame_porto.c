/*
 * Copyright (C) 2023 by Antonio Solida
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
ANTONIO SOLIDA - Mat. 178507
Esame RTES 27 giugno 2023
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5 //posti porto
#define B 15 //numero barche

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

struct porto_t{
    sem_t mutex; //mutex per sezioni critiche
    sem_t entrata; //coda per l'ingresso nel porto
    sem_t uscita; //coda per l'uscita nel porto

    int coda_in, coda_out, posti_occupati; //rispettivamente, numero di barche in coda per entrare, uscire e posti occupati
    int in_uscita, in_entrata; //conteggia quante barche escono o entrano (al fine di controllare che non transitino più di 2 navi contemporaneamente)
} porto;

void init_porto(struct porto_t *porto){
    sem_init(&porto->mutex, 0, 1);
    sem_init(&porto->entrata, 0, 0);
    sem_init(&porto->uscita, 0, 0);

    porto->coda_in = porto->coda_out = porto->posti_occupati = 0;
    porto->in_uscita = porto->in_entrata = 0;
}

void entrata_richiesta(struct porto_t *porto){
    sem_wait(&porto->mutex);

    //if (porto->posti_occupati < N && porto->in_uscita == 0 && porto->in_entrata <= 2) //è più corretto minore di 2 altrimenti le barche in entrata
                                                                                        //potrebbero essere 3
    if (porto->posti_occupati < N && porto->in_uscita == 0 && porto->in_entrata < 2){ //per entrare, bisogna rispettare 3 condizioni:
        porto->posti_occupati++;                                                        //1. ci siano posti liberi nel porto;
        sem_post(&porto->entrata);                                                      //2. nessuno stia uscendo
        porto->in_entrata++;                                                            //3. ci siano meno di 2 barche in entrata
    } else {
        porto->coda_in++;                                                               //altrimenti si mette in coda per entrare
    }
    sem_post(&porto->mutex);
    sem_wait(&porto->entrata);                                                          //qui il thread si blocca a meno che le condizioni per entrare siano verificate
}

void entrata_ok(struct porto_t *porto){
    sem_wait(&porto->mutex);
    porto->in_entrata--;
    if (porto->coda_out != 0 && porto->in_uscita <= 2){                                 //col transito in porto, faccio uscire una barca in coda, se esiste (causa priorità)
        porto->coda_out--;                                                              //decremento la coda
        porto->in_uscita++;                                                             //segnalo che una barca sta uscendo
        porto->posti_occupati--;                                                        //e ovviamente libero il posto
        sem_post(&porto->uscita);
    }

    if (porto->in_uscita == 0 && porto->coda_in != 0 && porto->in_entrata < 2){         //se nessuno esce, faccio entrare
        if (porto->posti_occupati < N){                                                 //(a patto che ci siano posti liberi)
            porto->coda_in--;                                                           //decremento la coda
            porto->in_entrata++;                                                        //segnalo che una barca sta entrando
            porto->posti_occupati++;                                                    //e ovviamente occupo il posto
            sem_post(&porto->entrata);
        }
    }
    sem_post(&porto->mutex);
}

void uscita_richiesta(struct porto_t *porto){
    sem_wait(&porto->mutex);
    //if (porto->in_entrata == 0 && porto->in_uscita <= 2){                             //è più corretto minore di 2 altrimenti le barche in uscita
                                                                                        //potrebbero essere 3
    if (porto->in_entrata == 0 && porto->in_uscita < 2){                                //per uscire, bisogna rispettare 2 condizioni:
        porto->posti_occupati--;                                                        //1. nessuno stia entrando;
        sem_post(&porto->uscita);                                                       //2. ci siano meno di 2 barche in uscita
        porto->in_uscita++;
    } else {
        porto->coda_out++;                                                              //altrimenti si mette in coda per uscire
    }
    sem_post(&porto->mutex);
    sem_wait(&porto->uscita);                                                           //qui il thread si blocca a meno che le condizioni per uscire siano verificate
}

void uscita_ok(struct porto_t *porto){
    sem_wait(&porto->mutex);
    porto->in_uscita--;
    if (porto->coda_out != 0 && porto->in_uscita <= 2){                                 //stessa e identica logica utilizzata per la funzione entrata_ok(...)
        porto->coda_out--;
        porto->in_uscita++;
        porto->posti_occupati--;
        sem_post(&porto->uscita);
    }

    if (porto->in_uscita == 0 && porto->coda_in != 0 && porto->in_entrata < 2){
        if (porto->posti_occupati < N){
            porto->coda_in--;
            porto->in_entrata++;
            porto->posti_occupati++;
            sem_post(&porto->entrata);
        }
    }
    sem_post(&porto->mutex);
}

void *barca(void *arg){
    int numero_barca = *(int*)arg;
    
    //arriva all'imboccatura del porto
    printf("[%d] arriva all'entrata\n", numero_barca);
    entrata_richiesta(&porto);

    //transito
    printf("[%d] transito ingresso\n", numero_barca);
    entrata_ok(&porto);

    //staziona
    printf("[%d] si ferma al porto\n", numero_barca);
    pausetta(); //giusto per simulare lo stazionamento nel porto

    printf("[%d] arriva all'uscita\n", numero_barca);
    uscita_richiesta(&porto);

    //transito
    printf("[%d] transito uscita\n", numero_barca);
    uscita_ok(&porto);

    //vai altro porto
    printf("[%d] vado altro porto\n\n", numero_barca);

    pthread_exit(0);
}

int main(){
    pthread_attr_t a;
    pthread_t barche[B];
    int id_barche[B];

    init_porto(&porto);
    srand(time(NULL));

    pthread_attr_init(&a);

    for(int i=0;i<B;i++){
        id_barche[i] = i;
        pthread_create(&barche[i], &a, barca, &id_barche[i]);
    }

    for(int i=0;i<B;i++){
        void* ret;
        pthread_join(barche[i], &ret);
    }

    return 0;
}