/* Scrivere un programma C gestoreRisorse.c che deve generare un numero non noto di thread (il numero 
sia passato come parametro, come nel caso del programma nrogenericoThread.c). 
Questi thread eseguono il codice corrispondente al primo esempio di uso dei semafori visto a lezione: 
GESTIONE DI UN INSIEME DI RISORSE EQUIVALENTI (EsempiDiUsoDISemafori-2ter.pdf).
Il numero di risorse equivalenti (per semplicità) può essere definito da una costante che deve essere 
chiamata m (ad esempio uguale a 5, ma chiaramente è possibile variare tale numero a piacimento). Si 
segnala che il caso più interessante è comunque quello in cui il numero di thread sia significativamente 
maggiore del numero di risorse (ad esempio, 10 thread per 5 risorse).
La start_routine si deve chiamare esegui e devono essere previste le due funzioni RICHIESTA e RILASCIO 
mostrate a lezione. 
L'utilizzo della risorsa deve essere simulato con una sleep(5). 
Ogni thread deve tornare al main thread il numero d'ordine della risorsa che è stata assegnata e quindi 
utilizzata. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_RESOURCE 5
typedef enum {false, true} Boolean;
pthread_mutex_t MUTEX = PTHREAD_MUTEX_INITIALIZER;
sem_t risorse;
Boolean LIBERO[NUM_RESOURCE];

int RICHIESTA(){
    int i;

    sem_wait(&risorse);
    pthread_mutex_lock(&MUTEX);
    // sezione critica qui
    for (i=0; !LIBERO[i]; i++);
    LIBERO[i] = false;
    // fine sezione critica
    pthread_mutex_unlock(&MUTEX);
    return i;
}

void RILASCIO(int i){
    //int i;

    pthread_mutex_lock(&MUTEX);
    LIBERO[i]=true;
    pthread_mutex_unlock(&MUTEX);
    sem_post(&risorse);
    /*sem_wait(&risorse);
    pthread_mutex_lock(&MUTEX);
    // sezione critica qui
    pthread_mutex_unlock(&MUTEX);*/

}

void *thread_function(void *id){
    int x;

    x = RICHIESTA();
    printf("Risorsa %d bloccata\n", x);
    sleep(5);
    RILASCIO(x);

}

int main(int argc, char **argv){
    pthread_t *thread;
    int *taskids;
    int n_thread;
    int i;
    char error[250];

    // initialize semaphore, only to be used with threads in this process, set value to 1
    //sem_init(&mutex, 0, 1);

    for (i=0; i < NUM_RESOURCE; i++) LIBERO[i] = true;

    if (argc > 2){
        printf("Error! Too many arguments.\n");
        exit(1);
    }

    if (argc == 2){
        //fd = open(argv[1], O_RDONLY);
        //printf("%d",fd);
        n_thread=atoi(argv[1]);
    }
    if (sem_init(&risorse, 0, n_thread) != 0 ){
        perror("Problemi con l'inizializzazione del semaforo RISORSE\n");
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
        pthread_join(thread[i], NULL);
    }

    return 0;
}