/*
Esercizio 5.
Sembra funzionare tutto a prima botta. La consegna richiedeva di fare solo la versione con pthread ma ho usato i semafori.
*/
//#define USA_SEM
#define USA_PTHREAD

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define ELETTORI 11 //deve essere un numero dispari!

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

#ifdef USA_SEM
struct urna_t{
    sem_t mutex; //mutex
    sem_t ho_votato; //elettore aspetta risultati
    sem_t scrutinio; //lo scrutatore aspetta per scrutare

    int n_voti0, n_voti1;
    int votanti;
} urna;

void init_urna(struct urna_t *u){
    sem_init(&u->mutex, 0, 1);
    sem_init(&u->ho_votato, 0, 0);
    sem_init(&u->scrutinio, 0, 0);

    u->n_voti0 = u->n_voti1 = u->votanti = 0;
}

void vota(int v){
    sem_wait(&urna.mutex);
    switch (v){
    case 0:
        printf("Voto 0\n");
        urna.n_voti0++;
        printf("N voti 0: %d\n",urna.n_voti0);
        break;
    
    case 1:
        printf("Voto 1\n");
        urna.n_voti1++;
        printf("N voti 1: %d\n",urna.n_voti1);
        break;
    }
    urna.votanti++;

    if (urna.n_voti0 > ELETTORI/2 || urna.n_voti1 > ELETTORI/2){
        sem_post(&urna.mutex);
        for(int i=0; i<ELETTORI; i++) sem_post(&urna.ho_votato);
    } else {
        sem_post(&urna.mutex);
        sem_wait(&urna.ho_votato);
    }

}

int risultato(){
    if (urna.n_voti0 > urna.n_voti1) return 0;
    else return 1;
}

//codice dato dall'esercizio
void *thread(void *arg){
    int voto = rand()%2;
    pthread_t thread_id = pthread_self();

    vota(voto);
    if (voto == risultato()) printf("%lu Ho vinto!\n", thread_id);
    else printf("%lu Ho perso!\n", thread_id);
    pthread_exit(0);
}

#endif

#ifdef USA_PTHREAD
struct urna_t{
    pthread_mutex_t mutex; //mutex
    pthread_cond_t ho_votato; //elettore aspetta risultati
    pthread_cond_t scrutinio; //lo scrutatore aspetta per scrutare

    int n_voti0, n_voti1;
    int votanti;
} urna;

void init_urna(struct urna_t *u){
    pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;
    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);

    pthread_mutex_init(&u->mutex, &m_attr);
    pthread_cond_init(&u->ho_votato, &c_attr);
    pthread_cond_init(&u->scrutinio, &c_attr);

    pthread_condattr_destroy(&c_attr);
    pthread_mutexattr_destroy(&m_attr);

    u->n_voti0 = u->n_voti1 = u->votanti = 0;
}

void vota(int v){
    pthread_mutex_lock(&urna.mutex);
    switch (v){
    case 0:
        printf("Voto 0\n");
        urna.n_voti0++;
        printf("N voti 0: %d\n",urna.n_voti0);
        break;
    
    case 1:
        printf("Voto 1\n");
        urna.n_voti1++;
        printf("N voti 1: %d\n",urna.n_voti1);
        break;
    }
    urna.votanti++;

    if (urna.n_voti0 > ELETTORI/2 || urna.n_voti1 > ELETTORI/2){
        pthread_mutex_unlock(&urna.mutex);
        //for(int i=0; i<ELETTORI; i++) sem_post(&urna.ho_votato);
        pthread_cond_broadcast(&urna.ho_votato);
    } else {
        while(urna.n_voti0 < ELETTORI/2 && urna.n_voti1 < ELETTORI/2){
            pthread_cond_wait(&urna.ho_votato, &urna.mutex);
        }
        pthread_mutex_unlock(&urna.mutex);
    }

}

int risultato(){
    if (urna.n_voti0 > urna.n_voti1) return 0;
    else return 1;
}

//codice dato dall'esercizio
void *thread(void *arg){
    int voto = rand()%2;
    pthread_t thread_id = pthread_self();

    vota(voto);
    if (voto == risultato()) printf("%lu Ho vinto!\n", thread_id);
    else printf("%lu Ho perso!\n", thread_id);
    pthread_exit(0);
}
#endif

int main(){
    pthread_attr_t a;
    pthread_t p;

    init_urna(&urna);

    srand(time(0));

    pthread_attr_init(&a);

    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    for (int i=0; i<ELETTORI; i++){
        pthread_create(&p, &a, thread, NULL);
    }

    pthread_attr_destroy(&a);

    sleep(5);

    return 0;
}