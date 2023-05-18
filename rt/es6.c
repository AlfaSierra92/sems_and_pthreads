/*
Esercizio 6
*/

//#define USA_SEM
#define USA_PTHREAD

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_FILOSOFI 5
#define DELAY 10

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

#ifdef USA_SEM
struct tavolo_t{
    sem_t mutex;
    sem_t forchette[NUM_FILOSOFI];

} tavolo;

void init_tavolo(struct tavolo_t *t){
    sem_init(&t->mutex, 0, 1);

    for(int i=0; i<NUM_FILOSOFI; i++) sem_init(&t->forchette[i], 0, 1);
}

void prende_forchette(int filosofo){
    printf("%d prende forchette\n", filosofo);
    if (filosofo != 0){
        sem_wait(&tavolo.forchette[filosofo]);
        sem_wait(&tavolo.forchette[filosofo-1]);
    } else {
        sem_wait(&tavolo.forchette[NUM_FILOSOFI-1]);
        sem_wait(&tavolo.forchette[filosofo]);
        
    }
    printf("%d ha preso forchette\n", filosofo);
    
}

void lascia_forchette(int filosofo){
    printf("%d lascia forchette\n", filosofo);
    if (filosofo != 0){
        sem_post(&tavolo.forchette[filosofo]);
        sem_post(&tavolo.forchette[filosofo-1]);
    } else {
        sem_post(&tavolo.forchette[NUM_FILOSOFI-1]);
        sem_post(&tavolo.forchette[filosofo]);
        
    }
    printf("%d ha lasciato forchette\n", filosofo);
}
#endif


#ifdef USA_PTHREAD
struct tavolo_t{
    pthread_mutex_t mutex;
    pthread_cond_t forchette[NUM_FILOSOFI];

    int fork[NUM_FILOSOFI]; //1 forchetta libera; 0 forchetta occupata
} tavolo;

void init_tavolo(struct tavolo_t *t){
    pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;
    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);

    pthread_mutex_init(&t->mutex, &m_attr);

    for(int i=0; i<NUM_FILOSOFI; i++) {
        pthread_cond_init(&t->forchette[i], &c_attr);
        t->fork[i] = 1;
    }

    pthread_condattr_destroy(&c_attr);
    pthread_mutexattr_destroy(&m_attr);
}

void prende_forchette(int filosofo){
    printf("%d prende forchette\n", filosofo);
    pthread_mutex_lock(&tavolo.mutex);
    if (filosofo != 0){
        while(tavolo.fork[filosofo] == 0) pthread_cond_wait(&tavolo.forchette[filosofo], &tavolo.mutex);
        tavolo.fork[filosofo] = 0;
        while(tavolo.fork[filosofo-1] == 0)pthread_cond_wait(&tavolo.forchette[filosofo-1], &tavolo.mutex);
        tavolo.fork[filosofo-1] = 0;
    } else {
        while(tavolo.fork[NUM_FILOSOFI-1] == 0) pthread_cond_wait(&tavolo.forchette[NUM_FILOSOFI-1], &tavolo.mutex);
        tavolo.fork[NUM_FILOSOFI-1] = 0;
        while(tavolo.fork[filosofo] == 0) pthread_cond_wait(&tavolo.forchette[filosofo], &tavolo.mutex); 
        tavolo.fork[filosofo] = 0;  
    }
    printf("%d ha preso forchette\n", filosofo);
    pthread_mutex_unlock(&tavolo.mutex);
    
}

void lascia_forchette(int filosofo){
    printf("%d lascia forchette\n", filosofo);
    pthread_mutex_lock(&tavolo.mutex);
    if (filosofo != 0){
        pthread_cond_signal(&tavolo.forchette[filosofo]);
        pthread_cond_signal(&tavolo.forchette[filosofo-1]);
        tavolo.fork[filosofo] = 1;
        tavolo.fork[filosofo-1] = 1;
    } else {
        pthread_cond_signal(&tavolo.forchette[NUM_FILOSOFI-1]);
        pthread_cond_signal(&tavolo.forchette[filosofo]);
        tavolo.fork[NUM_FILOSOFI-1] = 1;
        tavolo.fork[filosofo] = 1;
    }
    pthread_mutex_unlock(&tavolo.mutex);
    printf("%d ha lasciato forchette\n", filosofo);
}
#endif

void *filosofo(void *arg){
    int tempo;
    int filosofo = *(int *) arg;
    int ciclo = 0;

    while(ciclo<50){
        tempo = 0;
        printf("%d sta pensando\n", filosofo);
        while(tempo<DELAY){
            //PENSA
            pausetta();
            tempo++;
        }

        prende_forchette(*(int *)arg);
        printf("%d sta mangiando per la %desima volta\n", filosofo, ciclo);
        while(tempo<DELAY){
            //MANGIA
            pausetta();
            tempo++;
        }
        lascia_forchette(*(int *)arg);
        pausetta();
        ciclo++;
    }
    
}

int main(){
    pthread_attr_t a;
    pthread_t p;

    init_tavolo(&tavolo);

    srand(time(0));

    pthread_attr_init(&a);

    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    for (int i=0; i<NUM_FILOSOFI; i++){
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&p, &a, filosofo, arg);
    }

    pthread_attr_destroy(&a);

    sleep(120);

    return 0;
}