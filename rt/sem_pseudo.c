#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/**
 * STRUTTURA DATI
 * 
 * Condivisa e utilizzata per gestione concorrenza e sincronizzazione
 **/
struct my_resource {
    sem_t mutex;
    sem_t priv;
} resource;

/**
 * INIZIALIZZAZIONE
 **/
void inizializza(struct my_resource *r) {
    sem_init(&r->mutex, 0, 1);
    sem_init(&r->priv, 0, 0);
}

/**
 * SOLUZIONE 1 
 * 
 * Prologo (post previa).
 **/
void prologo1(struct my_resource *r) {
    sem_wait(&r->mutex);

    if ("<POSSO ACCEDERE ALLA RISORSA>") {
        "<ALLOCO RISORSA>";
        sem_post(&r->priv);
    } else {
        "<REGISTRO BLOCCAGGIO>";
    }

    sem_post(&r->mutex);
    sem_wait(&r->priv);
}

/**
 * SOLUZIONE 1
 * 
 * Epilogo.
 **/
void epilogo1(struct my_resource *r) {
    sem_wait(&r->mutex);

    "<DEALLOCO RISORSA>";
    if ("<POSSO SVEGLIARE QUALCUNO>") {
        "<DEREGISTRO BLOCCAGGIO>";
        "<ALLOCO RISORSA>";
        sem_post(&r->priv);
    }

    sem_post(&r->mutex);
}

/**
 * SOLUZIONE 2
 * 
 * Prologo.
 **/
void prologo2(struct my_resource *r) {
    sem_wait(&r->mutex);

    if ("<NON POSSO ACCEDERE ALLA RISORSA>") {
        "<REGISTRO BLOCCAGGIO>";
        sem_post(&r->mutex);
        sem_wait(&r->priv);
        "<DEREGISTRO BLOCCAGGIO>";
    }

    "<ALLOCO RISORSA>";
    sem_post(&r->mutex);
}

/**
 * SOLUZIONE 2
 * 
 * Epilogo.
 **/
void epilogo2(struct my_resource *r) {
    sem_wait(&r->mutex);

    "<DEALLOCO RISORSA>";
    if ("<POSSO SVEGLIARE QUALCUNO>") {
        sem_post(&r->priv);
    } else {
        sem_post(&r->mutex);
    }
}

/**
 * THREAD 1
 * 
 * Utilizzo della risorsa protetto da prologo1 ed epilogo1.
 **/
void *thread1() {
    prologo1(&resource);
    "<UTILIZZO SAFE DELLA RISORSA>";
    epilogo1(&resource);

    return 0;
}

/**
 * THREAD 2
 * 
 * Utilizzo della risorsa protetto da prologo2 ed epilogo2.
 **/
void *thread2() {
    prologo2(&resource);
    "<UTILIZZO SAFE DELLA RISORSA>";
    epilogo2(&resource);

    return 0;
}

/**
 * MAIN
 * 
 * Thread principale che crea due thread concorrenti.
 **/
int main() {
    inizializza(&resource);

    pthread_attr_t attr;
    pthread_t thread;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_create(&thread, &attr, thread1, NULL);
    pthread_create(&thread, &attr, thread2, NULL);

    pthread_attr_destroy(&attr);
    sleep(10);

    return 0;
}
