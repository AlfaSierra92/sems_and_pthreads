#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NESSUNO 0
#define STATO_A_O_B 1
#define STATO_RESET 2

struct gestore_t{
    pthread_mutex_t mutex;
    pthread_cond_t semA, semRes;

    int na,nb,nr;
    int ca,cb,cr;
    int stato;
} gestore;

void init_gestore(struct gestore_t *g){
    pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;

    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);

    pthread_mutex_init(&g->mutex, &m_attr);
    pthread_cond_init(&g->semA, &c_attr); //USO LO STESSO COND PER A SIA PER B
    pthread_cond_init(&g->semRes, &c_attr);

    pthread_condattr_destroy(&c_attr);
    pthread_mutexattr_destroy(&m_attr);

    g->na = g->nb = g->ca = g->cb = g->nr = g->cr = 0;
    g->stato = NESSUNO;
}

void StartA(struct gestore_t *g){
    pthread_mutex_lock(&g->mutex);

    while(g->stato == STATO_RESET || g->na >= 3){
        g->ca++;
        pthread_cond_wait(&g->semA,&g->mutex);
        g->ca--;
    }
    g->stato = STATO_A_O_B;
    g->na++;
    pthread_mutex_unlock(&g->mutex);
}

void EndA(struct gestore_t *g){
    pthread_mutex_lock(&g->mutex);
    g->na--;
    if (g->ca>=0 && g->na<3){
        g->stato = NESSUNO;
        pthread_cond_signal(&g->semA);
    }
    pthread_mutex_unlock(&g->mutex);
}

void StartB(struct gestore_t *g){
    pthread_mutex_lock(&g->mutex);
    while(g->stato == STATO_RESET || g->nb >= 3){
        g->cb++;
        pthread_cond_wait(&g->semA,&g->mutex);
        g->cb--;
    }
    g->stato = STATO_A_O_B;
    g->nb++;

    pthread_mutex_unlock(&g->mutex);
}

void EndB(struct gestore_t *g){
    pthread_mutex_lock(&g->mutex);
    g->nb--;
    if (g->cb>=0 && g->nb<3){
        g->stato = NESSUNO;
        pthread_cond_signal(&g->semA);
    }
    pthread_mutex_unlock(&g->mutex);
}

void StartReset(struct gestore_t *g){
    pthread_mutex_lock(&g->mutex);
    while (/*g->stato == STATO_RESET && */g->nr > 0){
        g->cr++;
        pthread_cond_wait(&g->semRes,&g->mutex);
        g->cr--;
    }
    g->stato = STATO_RESET;
    g->nr++;

    pthread_mutex_unlock(&g->mutex);
}

void EndReset(struct gestore_t *g){
    pthread_mutex_lock(&g->mutex);
    g->nr--;
    /*while(g->cr > 0 && g->nr<1){
        g->cr--;
        pthread_cond_signal(&g->semRes);
    }*/
    if (g->cr > 0){
        //g->cr--; //QUI DECREMENTAVO DUE VOLTE!!!!!
        //g->nr++;
        pthread_cond_signal(&g->semRes);
    } else if (g->ca != 0 || g->cb != 0){
        //g->ca--; //ANCHE QUI!!!!
        //g->na++;
        g->stato = STATO_A_O_B;
        pthread_cond_signal(&g->semA);
    } /*else if (g->cb != 0){ //UNIFICANDO sem questa if non serve più
        g->cb--; //ANCHE QUI!!!!
        //g->nb++;
        g->stato = STATO_A_O_B;
        pthread_cond_signal(&g->semB);
    }*/ else {
        g->stato = NESSUNO;
    }

    pthread_mutex_unlock(&g->mutex);
}

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

void *A(void *arg){
    for (;;) {
        StartA(&gestore);
        putchar(*(char *)"A");
        putchar(*(char *)arg);
        putchar(*(char *)"a");
        putchar(*(char *)"\n");
        EndA(&gestore);
        pausetta();
    }
    return 0;
}

void *B(void *arg){
    for (;;) {
        StartB(&gestore);
        putchar(*(char *)"B");
        putchar(*(char *)arg);
        putchar(*(char *)"b");
        putchar(*(char *)"\n");
        EndB(&gestore);
        pausetta();
    }
    return 0;
}

void *Reset(void *arg){
    for (;;) {
        StartReset(&gestore);
        putchar(*(char *)"R");
        putchar(*(char *)arg);
        putchar(*(char *)"r");
        putchar(*(char *)"\n");
        EndReset(&gestore);
        pausetta();
    }
    return 0;
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

    //pthread_create(&p, &a, A, (void *)"a");
    pthread_create(&p, &a, A, (void *)"1");

    pthread_create(&p, &a, B, (void *)"2");
    //pthread_create(&p, &a, B, (void *)"b");

    pthread_create(&p, &a, Reset, (void *)"3");
    //pthread_create(&p, &a, Reset, (void *)"x");

    pthread_attr_destroy(&a);

    /* aspetto 10 secondi prima di terminare tutti quanti */
    sleep(10);

    return 0;
}