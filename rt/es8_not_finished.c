/*
Esercizio 8
*/

#define USA_SEM

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/*#define FREE -1
#define BUSY 1
#define NOTIME -1*/

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

#ifdef USA_SEM
struct gestore_t{
    sem_t mutex;
    sem_t risorsa[2]; //denotano se la risorsa è disponibile o meno
    sem_t gestore; //serve per sbloccare il gestore e avviare il processo di allocazione

    //int richiesta_risorsa[4][2]; 
} gestore;

void init_gestore(struct gestore_t *g){
    /*sem_init(&g->mutex, 0, 1);
    sem_init(&g->gestore, 0, 1);

    for(int i=0; i<2; i++) {
        sem_init(&g->risorsa[i], 0, 1);
    }
    //for (int j=0; j<4; j++) g->richiesta_risorsa[j] = -1;
    for(int i=0; i<4; i++){
        //for(int j=0; j<2; j++) g->richiesta_risorsa[i][j] = -1;
        g->richiesta_risorsa[i][0] = FREE;
        g->richiesta_risorsa[i][1] = NOTIME;
    }*/
}

void *gestore_risorse(void *arg){
    /*sem_wait(&gestore.gestore);
    sem_wait(&gestore.mutex);
    for(int i=0; i<4; i++){
        if (gestore.richiesta_risorsa[i][0] == FREE){
            gestore.richiesta_risorsa[i][0] == BUSY;
            sem_wait(&gestore.risorsa[risorsa]);
        }
    }
    sem_post(&gestore.mutex);*/
    
}

#endif

#ifdef USA_PTHREAD
//todo
#endif

void *processo(void *arg){
    int id = *(int *) arg;
    int T = 1000;
    
    /*while(1){ //DEPRECATED
        int risorsa = rand()%2;
        gestore.richiesta_risorsa[id][0] = risorsa;
        gestore.richiesta_risorsa[id][1] = T;
        sem_wait(&gestore.mutex);
        sem_post(&gestore.gestore);
        sem_post(&gestore.mutex);
        sem_wait(&gestore.risorsa[risorsa]);
        sem_wait(&gestore.mutex);
        if(gestore.richiesta_risorsa[id][0] == risorsa) {
            pausetta();
            printf("%d ha ottenuto la risorsa %d.\n", id, risorsa);
            gestore.richiesta_risorsa[id][0] = FREE;
            gestore.richiesta_risorsa[id][1] = NOTIME;
        }
        else printf("%d non ha ottenuto la risorsa %d.\n", id, risorsa);
        sem_post(&gestore.mutex);
        pausetta();
    }*/
    
}