/*
Bad gym
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5 //tipologie di attrezzi
#define M 10 //copie di ogni singolo attrezzo
#define P 20 //numero di persone
#define E 10 //numero di esercizi per ogni persona

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

struct palestra_t{
    sem_t mutex;
    sem_t attrezzi[N]; //un semaforo per ogni attrezzo
    sem_t persone[P]; //un semafoto per ogni persona

    int prenotazioni[P]; //ogni atleta prenota l'attr. succ.
    int num_attrezzi[N];
} palestra;

void init_palestra(struct palestra_t *p){
    sem_init(&p->mutex, 0, 1);
    for(int i=0; i<N; i++) {
        sem_init(&p->attrezzi[i], 0, 0);
        p->num_attrezzi[i] = M;
    }
    for(int i=0; i<P; i++) {
        sem_init(&p->persone[i], 0, E);
        p->prenotazioni[i] = -1;
    }
}

void usaattrezzo(struct palestra_t *p, int numeropersona, int tipoattrezzo){
    printf("TRAINER: ci sono %d dell'attrezzo %d\n", p->num_attrezzi[tipoattrezzo], tipoattrezzo);
    
    if (p->prenotazioni[numeropersona] != tipoattrezzo || p->num_attrezzi[tipoattrezzo] == 0){ 
        sem_wait(&p->attrezzi[tipoattrezzo]);
    }
    sem_wait(&p->mutex);
    p->num_attrezzi[tipoattrezzo]--;
    p->prenotazioni[numeropersona] = -1;
    sem_post(&p->mutex);
    pausetta();
    printf("ATLETA: %d uso attrezzo %d\n", numeropersona, tipoattrezzo);

}

void prenota(struct palestra_t *p, int numeropersona, int tipoattrezzo){
    sem_wait(&p->mutex);
    p->prenotazioni[numeropersona] = tipoattrezzo;
    printf("ATLETA: %d prenoto attrezzo %d\n", numeropersona, tipoattrezzo);
    sem_post(&p->mutex);
}

void fineuso(struct palestra_t *p, int numeropersona, int tipoattrezzo){
    printf("ATLETA: %d libero attrezzo %d\n\n", numeropersona, tipoattrezzo);
    int val = -1;
    sem_getvalue(&p->attrezzi[tipoattrezzo], &val);
    sem_wait(&p->mutex);
    sem_post(&p->attrezzi[tipoattrezzo]);
    p->num_attrezzi[tipoattrezzo]++;
    sem_post(&p->mutex);
}

void *persona(void *arg){
    //todo
    int attrezzocorrente = rand()%N;
    int prossimoattrezzo = rand()%N;
    int numeropersona = *(int*)arg;

    for (int i = E; i>0; i--){
        printf("ATLETA: %d faccio esercizio %d\n", numeropersona, i);
        usaattrezzo(&palestra, numeropersona, attrezzocorrente);
        if (i != 0) prenota(&palestra, numeropersona, prossimoattrezzo);
        fineuso(&palestra, numeropersona, attrezzocorrente);
        if (i != 0) {
            attrezzocorrente = prossimoattrezzo;
            prossimoattrezzo = rand()%N;
        }
        pausetta();
    }
}

int main(){
    pthread_attr_t a;
    pthread_t persone[P];

    init_palestra(&palestra);

    srand(time(0));

    pthread_attr_init(&a);
    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    int *arg = malloc(sizeof(*arg));
    for(int i=0;i<P;i++){
        *arg = i;
        pthread_create(&persone[i], &a, persona, arg);
    }

    pthread_attr_destroy(&a);

    sleep(30);

    return 0;
}