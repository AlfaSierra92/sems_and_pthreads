/*
Far Harbor
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
    sem_t mutex;
    sem_t entrata, uscita;

    int coda_in, coda_out, posti_occupati;
    int in_uscita, in_entrata;
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
    if (porto->posti_occupati < N && porto->in_uscita == 0 && porto->in_entrata <= 2){
        porto->posti_occupati++;
        sem_post(&porto->entrata);
        porto->in_entrata++;
    } else {
        porto->coda_in++;
    }
    sem_post(&porto->mutex);
    sem_wait(&porto->entrata);
}

void entrata_ok(struct porto_t *porto){
    sem_wait(&porto->mutex);
    porto->in_entrata--;
    if (porto->coda_out != 0 && porto->in_uscita <= 2){
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

void uscita_richiesta(struct porto_t *porto){
    sem_wait(&porto->mutex);
    if (porto->in_entrata == 0 && porto->in_uscita <=2){
        porto->posti_occupati--;
        sem_post(&porto->uscita);
        porto->in_uscita++;
    } else {
        porto->coda_out++;
    }
    sem_post(&porto->mutex);
    sem_wait(&porto->uscita);
}

void uscita_ok(struct porto_t *porto){
    sem_wait(&porto->mutex);
    porto->in_uscita--;
    if (porto->coda_out != 0 && porto->in_uscita < 2){
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
}

int main(){
    pthread_attr_t a;
    pthread_t barche[B];
    int id_barche[B];

    init_porto(&porto);

    srand(time(NULL));

    pthread_attr_init(&a);
    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    for(int i=0;i<B;i++){
        id_barche[i] = i;
        pthread_create(&barche[i], &a, barca, &id_barche[i]);
    }

    pthread_attr_destroy(&a);

    sleep(30);

    return 0;
}