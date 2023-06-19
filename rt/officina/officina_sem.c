/*
Bob l'aggiustatutto
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5 //numero operai
#define CLIENTI_MAX 10 //numero clienti massimo

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

struct officina_t{
    sem_t mutex; //mutex
    sem_t clienti[N]; //coda per i clienti (una per ogni tipo di work)
    sem_t operai[N]; //1 semaforo per ogni operaio (una per ogni tipo di work)

    int coda[N]; //tiene conto del tipo di riparazione richiesta
    int token_riparazione;
} o;

void init_officina(struct officina_t *officina){
    sem_init(&officina->mutex, 0, 1);
    for (int i=0; i<N; i++)
        sem_init(&officina->clienti[i], 0, 0);
    for (int i=0; i<N; i++) 
        sem_init(&officina->operai[i], 0, 0);
    for (int i=0; i<N; i++) 
        officina->coda[i] = 0;
    officina->token_riparazione = -1;
}

void cliente_arrivo(struct officina_t *officina, int riparazione){
    sem_wait(&officina->mutex);
    officina->token_riparazione = riparazione;
    officina->coda[riparazione]++;
    printf("Riparazioni %d in coda: %d\n", riparazione, officina->coda[riparazione]);
    sem_post(&officina->operai[riparazione]);
}

void cliente_attesafineservizio(struct officina_t *officina){
    int riparazione = officina->token_riparazione;
    officina->token_riparazione = -1;
    sem_post(&officina->mutex);
    sem_wait(&officina->clienti[riparazione]);
}

void operaio_attesacliente(struct officina_t *officina, int riparazione){
    sem_wait(&officina->operai[riparazione]);
    sem_post(&officina->clienti[riparazione]);
    sem_wait(&officina->mutex);
    officina->coda[riparazione]--;
    printf("Riparazioni %d in coda: %d\n", riparazione, officina->coda[riparazione]);
    sem_post(&officina->mutex);
}

void operaio_fineservizio(struct officina_t *officina){
    printf("Fine lavoro\n");
}

void *cliente(void *arg){
    //arriva nell'ufficio per effettuare riparazione r
    int r = *(int *) arg;
    pthread_t thread_id = pthread_self();
    printf("CLIENTE: %lu arrivo per riparazione %d\n", thread_id, r);
    cliente_arrivo(&o, r); //BLOCCANTE
    //leggo un giornale
    printf("CLIENTE: %lu leggo il giornale\n", thread_id);
    cliente_attesafineservizio(&o); //BLOCCANTE
    //torno a casa
    printf("CLIENTE: %lu torno a casa\n", thread_id);
    return 0;
}

void *operaio(void *arg){
    //r indica la riparazione che l'operaio è in grado di fare
    int r = *(int *) arg;
    pthread_t thread_id = pthread_self();
    for(;;){
        operaio_attesacliente(&o, r); //BLOCCANTE
        //riparo
        printf("OPERAIO: %lu aggiusto %d\n", thread_id, r);
        operaio_fineservizio(&o); //NON BLOCCANTE
        //pausa
        printf("OPERAIO: Pausa caffè\n");
        pausetta();
    }
}

int main(){
    pthread_attr_t a;
    pthread_t clienti[CLIENTI_MAX], operai[N];

    init_officina(&o);

    srand(time(0));

    pthread_attr_init(&a);
    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    int *arg = malloc(sizeof(*arg));
    for(int i=0;i<N;i++){
        *arg = i;
        pthread_create(&operai[i], &a, operaio, arg);
    }

    for(int i=0;i<CLIENTI_MAX;i++){
        *arg = rand()%N;
        pthread_create(&clienti[i], &a, cliente, arg);
    }

    pthread_attr_destroy(&a);

    sleep(30);

    return 0;
}