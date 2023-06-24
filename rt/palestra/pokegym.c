/*
Bad gym
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5 //tipologie di attrezzi
#define M 1 //copie di ogni singolo attrezzo
#define P 3 //numero di persone
#define E 5 //numero di esercizi per ogni persona

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

struct palestra_t{
    sem_t mutex;
    sem_t attrezzi[N]; //un semaforo per ogni attrezzo

    int prenotazioni[P]; //ogni atleta prenota l'attr. succ.
    int attrezzo_in_uso[P]; //tiene conto dell'attrezzo usato
    int num_attrezzi_disp[N];
    int attrezzi_prenotati[N];
} palestra;

void init_palestra(struct palestra_t *p){
    sem_init(&p->mutex, 0, 1);
    for(int i=0; i<N; i++) {
        sem_init(&p->attrezzi[i], 0, 0);
        p->num_attrezzi_disp[i] = M;
        p->attrezzi_prenotati[i] = 0;
    }
    for(int i=0; i<P; i++) {
        p->prenotazioni[i] = -10;
        p->attrezzo_in_uso[i] = -1;
    }
}

void usaattrezzo(struct palestra_t *p, int numeropersona, int tipoattrezzo){
    printf("\nTRAINER: ci sono %d dell'attrezzo %d\n\n", p->num_attrezzi_disp[tipoattrezzo], tipoattrezzo);
    sem_wait(&p->mutex);
    if (p->prenotazioni[numeropersona] != -1 && p->num_attrezzi_disp[tipoattrezzo] > 0) { //l'atleta ha effettuato la prenotazione in precedenza
        printf("ATLETA: %d uso attrezzo %d\n", numeropersona, tipoattrezzo);
        sem_post(&p->attrezzi[tipoattrezzo]);
        p->attrezzo_in_uso[numeropersona] = tipoattrezzo; //indica l'attrezzo utilizzato
        p->num_attrezzi_disp[tipoattrezzo]--;
        if (p->attrezzo_in_uso[numeropersona] != -10) p->attrezzi_prenotati[tipoattrezzo]--; //per il primo giro
        p->prenotazioni[numeropersona] = -1; //rimuovo prenotazione
        sem_post(&p->mutex);
        sem_wait(&p->attrezzi[tipoattrezzo]);
    } else { //se non ha prenotato in precedenza l'attrezzo, salta l'esercizio
        printf("ATLETA: %d NON uso attrezzo %d\n", numeropersona, tipoattrezzo);
        sem_post(&p->mutex);
    }
    //pausetta();

}

void prenota(struct palestra_t *p, int numeropersona, int tipoattrezzo){
    sem_wait(&p->mutex);
    if(p->num_attrezzi_disp[tipoattrezzo] > 0 || p->attrezzi_prenotati[tipoattrezzo] < M) {
        p->prenotazioni[numeropersona] = tipoattrezzo;
        p->attrezzi_prenotati[tipoattrezzo]++;
        printf("ATLETA: %d prenoto attrezzo %d\n", numeropersona, tipoattrezzo);
    } else { //se non ci sono attrezzi disponibili, non prenota e quindi non effettuerà l'esercizio
        printf("ATLETA: %d NON prenoto attrezzo %d\n", numeropersona, tipoattrezzo);
    }
    sem_post(&p->mutex);
    //pausetta();
}

void fineuso(struct palestra_t *p, int numeropersona, int tipoattrezzo){
    sem_wait(&p->mutex);
    printf("ATLETA: %d libero attrezzo %d\n\n", numeropersona, tipoattrezzo);
    if (p->attrezzo_in_uso[numeropersona] != -1){
        //printf("DEBUG1: %d\n", p->num_attrezzi_disp[tipoattrezzo]);
        sem_post(&p->attrezzi[tipoattrezzo]);
        p->num_attrezzi_disp[tipoattrezzo]++;
        p->attrezzo_in_uso[numeropersona] = -1; //non usa più l'attrezzo
    } else {
        //printf("DEBUG2: %d %d %d\n", numeropersona, tipoattrezzo, p->num_attrezzi_disp[tipoattrezzo]);
    }
    if (p->attrezzo_in_uso[numeropersona] == -10) p->attrezzo_in_uso[numeropersona] = -1; //serve per il primo giro
    sem_post(&p->mutex);
    //pausetta();
}

void *persona(void *arg){
    int attrezzocorrente = rand()%N;
    int prossimoattrezzo = rand()%N;
    int numeropersona = *(int*)arg;

    for (int i = E; i>0; i--){
        printf("ATLETA: %d faccio esercizio numero %d\n", numeropersona, i);
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

    sleep(300);

    return 0;
}