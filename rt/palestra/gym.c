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
#define P 15//numero di persone
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

    int prenotazioni_atleta[P]; //ogni atleta prenota l'attr. succ.
    //int atleta_attrezzo_in_uso[P]; //tiene conto dell'attrezzo usato
    int num_attrezzi_disp[N];
    int coda[N];
} palestra;

void init_palestra(struct palestra_t *p){
    sem_init(&p->mutex, 0, 1);
    for(int i=0; i<N; i++) {
        sem_init(&p->attrezzi[i], 0, 0);
        p->num_attrezzi_disp[i] = M;
        p->coda[i] = 0;
    }
    for(int i=0; i<P; i++) {
        p->prenotazioni_atleta[i] = -1;
        //p->atleta_attrezzo_in_uso[i] = -1;
    }
}

void usaattrezzo(struct palestra_t *p, int numeropersona, int tipoattrezzo){
    //todo
    printf("\nTRAINER: ci sono %d dell'attrezzo %d\n\n", p->num_attrezzi_disp[tipoattrezzo], tipoattrezzo);
    sem_wait(&p->mutex);
    if (p->prenotazioni_atleta[numeropersona] != -1 || p->num_attrezzi_disp[tipoattrezzo] > 0){
        printf("ATLETA [%d] uso attrezzo %d\n", numeropersona, tipoattrezzo);

        sem_post(&p->attrezzi[tipoattrezzo]);
        p->prenotazioni_atleta[numeropersona] = -1;
        p->num_attrezzi_disp[tipoattrezzo]--;
        //p->atleta_attrezzo_in_uso[numeropersona] = tipoattrezzo;
    } else {
        p->coda[tipoattrezzo]++;
    }

    if (p->prenotazioni_atleta[numeropersona] != -1) p->coda[tipoattrezzo]--;

    //p->atleta_attrezzo_in_uso[numeropersona] = tipoattrezzo;
    sem_post(&p->mutex);
    sem_wait(&p->attrezzi[tipoattrezzo]);
}

void prenota(struct palestra_t *p, int numeropersona, int tipoattrezzo){
    //todo
    sem_wait(&p->mutex);
    if (p->num_attrezzi_disp[tipoattrezzo] > 0){
        
        printf("ATLETA [%d] prenoto attrezzo %d\n", numeropersona, tipoattrezzo);
        p->prenotazioni_atleta[numeropersona] = tipoattrezzo;
        p->coda[tipoattrezzo]++;
        
    }
    sem_post(&p->mutex);
}

void fineuso(struct palestra_t *p, int numeropersona, int tipoattrezzo){

    sem_wait(&p->mutex);
    printf("ATLETA [%d] libero attrezzo %d\n\n", numeropersona, tipoattrezzo);
    //p->atleta_attrezzo_in_uso[numeropersona] = -1;

    if (p->coda[tipoattrezzo] > 0) {
        p->coda[tipoattrezzo]--;
        sem_post(&p->attrezzi[tipoattrezzo]);
    }
    else p->num_attrezzi_disp[tipoattrezzo]++;
    
    //sem_post(&p->attrezzi[tipoattrezzo]);
    sem_post(&p->mutex);
}

void *persona(void *arg){
    int attrezzocorrente = rand()%N;
    int prossimoattrezzo = rand()%N;
    int numeropersona = *(int*)arg;

    for (int i = E; i>0; i--){
        printf("ATLETA [%d] faccio esercizio numero %d\n", numeropersona, i);
        usaattrezzo(&palestra, numeropersona, attrezzocorrente);
        if (i != 0) prenota(&palestra, numeropersona, prossimoattrezzo);
        fineuso(&palestra, numeropersona, attrezzocorrente);
        if (i != 0) {
            attrezzocorrente = prossimoattrezzo;
            prossimoattrezzo = rand()%N;
        }
        pausetta();
    }
    printf("ATLETA [%d] ha finito\n", numeropersona);
}

int main(){
    pthread_attr_t a;
    pthread_t persone[P];
    int id_persone[P];

    init_palestra(&palestra);

    srand(time(NULL));

    pthread_attr_init(&a);
    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    for(int i=0;i<P;i++){
        id_persone[i] = i;
        pthread_create(&persone[i], &a, persona, &id_persone[i]);
    }

    pthread_attr_destroy(&a);

    sleep(300);

    return 0;
}