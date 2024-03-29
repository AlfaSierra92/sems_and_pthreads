/*
PLEASE ADD "-lpthread" PARAMETER TO TASKS.JSON FILE
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 2

void *PrintHello(void *id)
{
   int *pi = (int *)id;
   printf("Thread%d partito: Hello World!\n", *pi);
   return NULL;
}

int main ()
{
   pthread_t *thread;
   int *taskids;
   int i;
   char error[250];
   
   thread=(pthread_t *) malloc(NUM_THREADS * sizeof(pthread_t)); //Alloco il thread; la memoria dell’elemento puntato deve esistere prima della chiamata!
   if (thread == NULL)
   {
	perror("Problemi con l'allocazione dell'array thread\n");
        exit(1);
   }

   taskids = (int *) malloc(NUM_THREADS * sizeof(int));
   if (taskids == NULL)
   {
       	perror("Problemi con l'allocazione dell'array taskids\n");
        exit(2);
    }

   for (i=0; i < NUM_THREADS; i++)
   {
        taskids[i] = i;
   	printf("Sto per creare il thread %d-esimo\n", taskids[i]);
   	if (pthread_create(&thread[i], NULL, PrintHello, (void *) (&taskids[i])) != 0) //crea il thread qui passando PrintHello come funzione
   	{                                                                             //che deve essere eseguita nel thread
		sprintf(error,"SONO IL MAIN E CI SONO STATI PROBLEMI NELLA CREAZIONE DEL thread %d-esimo\n", taskids[i]);
		perror(error);
        	exit(3);

    	}
    }

   exit(0);
}
