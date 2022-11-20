/*
Scrivere un programma C produttori-consumatori.c che deve generare un numero non noto di threads (il 
numero sia passato come parametro, come nel caso del programma nrogenericoThread.c e per quanto sarà 
di seguito illustrato sia un multiplo di 2) che eseguono il codice corrispondente al quarto esempio di uso dei 
semafori: PRODUTTORI E CONSUMATORI. 
Si assuma, per semplicità, che il numero di produttori e il numero di consumatori sia uguale: 
- devono prima essere creati una metà di thread che devono agire come produttori, 
- devono poi un'altra metà come consumatori. 
La dimensione del buffer usato per la comunicazione può essere definita da una costante (per semplicità)
che deve essere chiamata N (ad esempio uguale a 5). 
Ogni singolo messaggio scambiato deve essere una stringa di lunghezza 4 caratteri (quindi un array di 5 
caratteri per comprendere anche il terminatore di stringa). 
La start_routine dei produttori si deve chiamare eseguiProduttore, mentre quella dei consumatori si deve 
chiamare eseguiConsumatore e devono essere previste le 2 funzioni INSERIMENTO e PRELIEVO mostrate a
lezione. 
La fase di produzione deve essere simulata andando a memorizzare nel messaggio che deve essere 
depositato il numero d'ordine del thread produttore, mentre la fase di consumo del messaggio deve essere
simulata con una sleep (ad esempio di 2 sec.).
Sia produttori che consumatori eseguono il loro codice in un ciclo con NTIMES ripetizioni (per semplicità, si 
assuma NTIMES costante e eguale a 10). Ogni thread torna al main thread il proprio numero d'ordine. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define NTIMES 10

char error[250];
char buffer[N][5]; 
pthread_mutex_t MUTEX = PTHREAD_MUTEX_INITIALIZER;
sem_t risorse;

void *thread_prod_function(void *id){
    int i;
    int x;
    int *ptr;
    int *pi = (int *) id;
    char messaggio[5];

    for(i=0;i<NTIMES;i++){
        sprintf(messaggio, "%d", *pi);
        sem_wait(&risorse);
        pthread_mutex_lock(&MUTEX);
        INSERIMENTO(messaggio);
        pthread_mutex_unlock(&MUTEX);
        sem_post(&risorse);
    }
    *ptr = *pi;
    pthread_exit((void *) ptr);
}

void *thread_cons_function(void *id){

}

int main(int argc, char **argv){
    pthread_t *thread_prod, *thread_cons;
    int *taskids_prod, *taskids_cons;
    int n_thread;
    int i;
    int *p;

    // initialize semaphore, only to be used with threads in this process, set value to 1
    sem_init(&MUTEX, 0, 1);
    if (sem_init(&risorse, 0, N) != 0 ){ 
        perror("Problemi con l'inizializzazione del semaforo RISORSE\n");
        exit(5);
    }

    //for (i=0; i < NUM_RESOURCE; i++) LIBERO[i] = true;

    if (argc > 2){
        printf("Error! Too many arguments.\n");
        exit(1);
    }

    if (argc == 2 && atoi(argv[1])%2 == 0){
        n_thread=atoi(argv[1])/2;
    } else {
        printf("Wrong arguments type.\n");
        exit(1);
    }

    thread_prod=(pthread_t *) malloc(n_thread * sizeof(pthread_t));
    taskids_prod = (int *) malloc(n_thread * sizeof(int));
    // CREAZIONE THREAD PRODUTTORI
    for(i=0; i<n_thread; i++){
        taskids_prod[i]=i;
        printf("Sto per creare il thread %d-esimo\n", taskids_prod[i]);
        if (pthread_create(&thread_prod[i], NULL, thread_prod_function, (void *) (&thread_prod[i])) != 0) {
		    sprintf(error,"SONO IL MAIN E CI SONO STATI PROBLEMI NELLA CREAZIONE DEL thread %d-esimo\n", thread_prod[i]);
		    perror(error);
            exit(3);
        }
    }

    thread_cons=(pthread_t *) malloc(n_thread * sizeof(pthread_t));
    taskids_cons = (int *) malloc(n_thread * sizeof(int));
    // CREAZIONE THREAD CONSUMATORI
    for(i=0; i<n_thread; i++){
        taskids_cons[i]=i;
        printf("Sto per creare il thread %d-esimo\n", taskids_cons[i]);
        if (pthread_create(&thread_cons[i], NULL, thread_cons_function, (void *) (&thread_cons[i])) != 0) {
		    sprintf(error,"SONO IL MAIN E CI SONO STATI PROBLEMI NELLA CREAZIONE DEL thread %d-esimo\n", thread_cons[i]);
		    perror(error);
            exit(3);
        }
    }
    /*if (sem_init(&risorse, 0, NUM_RESOURCE) != 0 ){ //ERRORE DEL CAPPEROOOOOOO; inizializzavo il semaforo col numero di thread 
        perror("Problemi con l'inizializzazione del semaforo RISORSE\n"); //anzichè il numero di risorse.....
        exit(5);
    }

    thread=(pthread_t *) malloc(n_thread * sizeof(pthread_t));
    if (thread == NULL){
	    perror("Problemi con l'allocazione dell'array thread\n");
        exit(1);
    }
    taskids = (int *) malloc(n_thread * sizeof(int));

    for(i=0; i<n_thread; i++){
        taskids[i]=i;
        printf("Sto per creare il thread %d-esimo\n", taskids[i]);
        if (pthread_create(&thread[i], NULL, thread_function, (void *) (&taskids[i])) != 0) {
		    sprintf(error,"SONO IL MAIN E CI SONO STATI PROBLEMI NELLA CREAZIONE DEL thread %d-esimo\n", taskids[i]);
		    perror(error);
            exit(3);
        }
    }

    for(i=0; i<n_thread; i++){
        int ris;
        pthread_join(thread[i], (void**) & p);
        ris = *p;
        printf("Pthread %d-esimo restituisce %d\n", i, ris);
    }*/

    return 0;
}