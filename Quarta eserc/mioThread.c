#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#define NUM_THREADS 2

int read=0;
sem_t semaphore;

void *thread_function(void *id){
    int *pi = (int *)id;

    switch (*pi){
    case 0:
        printf("Insert a number: ");
        scanf("%d", &read);
        sem_post(&semaphore);
        break;
    
    case 1:
        sem_wait(&semaphore);
        read++;
        printf("%d\n", read);
        sem_post(&semaphore);
        break;
        
    default:
        printf("Error!");
        break;
    }
}

int main(){
    pthread_t *thread;
    int *taskids;
    int i;
    char error[250];

    // initialize semaphore, only to be used with threads in this process, set value to 0
    sem_init(&semaphore, 0, 0);

    thread=(pthread_t *) malloc(NUM_THREADS * sizeof(pthread_t));
    if (thread == NULL){
	    perror("Problemi con l'allocazione dell'array thread\n");
        exit(1);
    }

    taskids = (int *) malloc(NUM_THREADS * sizeof(int));
    if (taskids == NULL){
       	perror("Problemi con l'allocazione dell'array taskids\n");
        exit(2);
    }

    taskids[0]=0;
    if (pthread_create(&thread[0], NULL, thread_function, (void *) (&taskids[0])) != 0) {
		sprintf(error,"SONO IL MAIN E CI SONO STATI PROBLEMI NELLA CREAZIONE DEL thread %d-esimo\n", taskids[i]);
		perror(error);
        exit(3);
    }

    //pthread_join(thread[0], NULL);

    taskids[1]=1;
    if (pthread_create(&thread[1], NULL, thread_function, (void *) (&taskids[1])) != 0) {
		sprintf(error,"SONO IL MAIN E CI SONO STATI PROBLEMI NELLA CREAZIONE DEL thread %d-esimo\n", taskids[i]);
		perror(error);
        exit(3);
    }

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    sem_destroy(&semaphore);
    return 0;
}