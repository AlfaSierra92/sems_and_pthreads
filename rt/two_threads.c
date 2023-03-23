/*
Esempio 2 threads
Siano A e B le procedure che un insieme di processi P1, P2,
..., PN possono invocare e che devono essere eseguite rispettando i
seguenti vincoli di sincronizzazione:

- le due procedure vengano eseguite in maniera alternata e mutuamente esclusiva (A-B-A-B-A-B-...);
- possibile risoluzione dell'eventuale starvation.
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NOBODY 0
#define EXEC_A 1
#define EXEC_B 2

struct gestore_t {
    sem_t mymutex;
    sem_t semA, semB, sync;
    int stato;
    int nA, nB;
} gestore;

void init_gestore(struct gestore_t *g){
    sem_init(&g->mymutex, 0, 1);
    sem_init(&g->semA, 0, 0);
    sem_init(&g->semB, 0, 0);
    sem_init(&g->sync, 0, 1);
    g->stato = NOBODY;
    g->nA = 0;
    g->nB = 0;
}

void still(void){ //unused
  struct timespec t;
  t.tv_sec = 0;
  t.tv_nsec = (rand()%10+1)*1000000;
  nanosleep(&t,NULL);
}

void startA(struct gestore_t *g){
    if (g->stato != NOBODY) sem_wait(&g->semA); //al primo avvio non fa la wait
    else g->stato = EXEC_A;
    sem_wait(&g->mymutex);
    g->nA++;
    sem_post(&g->mymutex);
    if (g->nA == 1 ) sem_wait(&g->sync);
}

void endA(struct gestore_t *g){
    sem_wait(&g->mymutex);
    g->nA--;
    sem_post(&g->mymutex);
    sem_post(&g->sync);
    sem_post(&g->semB);
    g->stato = EXEC_B;
}

void startB(struct gestore_t *g){
    sem_wait(&g->semB);
    sem_wait(&g->mymutex);
    g->nB++;
    sem_post(&g->mymutex);
    if (g->nB == 1 ) sem_wait(&g->sync);
}

void endB(struct gestore_t *g){
    sem_wait(&g->mymutex);
    g->nB--;
    sem_post(&g->mymutex);
    sem_post(&g->sync);
    still();
    sem_post(&g->semA);
}

void *A(void *arg){
    for(;;){
        startA(&gestore);
        putchar(*(char *) arg);
        endA(&gestore);
        //still();
    }
}

void *B(void *arg){
    for(;;){
        startB(&gestore);
        putchar(*(char *) arg);
        endB(&gestore);
        //still();
    }
}

int main(void){
    pthread_attr_t a;
    pthread_t p;

    init_gestore(&gestore);

    pthread_attr_init(&a);
    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    pthread_create(&p, &a, A, (void *)"A");
    pthread_create(&p, &a, A, (void *)"a");
    pthread_create(&p, &a, B, (void *)"B");
    pthread_create(&p, &a, B, (void *)"b");

    pthread_attr_destroy(&a);
    sleep(10);
    return 0;

}