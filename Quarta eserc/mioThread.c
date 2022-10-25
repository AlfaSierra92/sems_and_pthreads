#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 2

//int mutex=1;
int read=0;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;;

void *thread_function(void *id){
    int *pi = (int *)id;

    switch (*pi){
    case 0:
        pthread_mutex_lock(&count_mutex);
        printf("Insert a number: ");
        scanf("%d", &read);
        pthread_mutex_unlock(&count_mutex);
        break;
    
    case 1:
        pthread_mutex_lock(&count_mutex);
        read++;
        printf("%d\n", read);
        pthread_mutex_unlock(&count_mutex);
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

    return 0;
}