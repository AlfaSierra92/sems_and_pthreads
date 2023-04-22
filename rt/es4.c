/*
Esercizio 4

Errori commessi:
-rand() non funzionante (restituiva sempre zero);
-rand() configurata male (restituiva anche il valore 3 che rompeva l'esecuzione dei threads);
-qualche errato posizionamento dei semafori (poca roba).
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define CARTA 0
#define SASSO 1
#define FORBICE 2

char *nomi_mosse[3] = {"carta", "sasso", "forbice"};

struct morra_t{
    sem_t mutex;
    sem_t arbitro;
    sem_t player1,player2;

    int mossa1, mossa2;
    int vincitore;
}morra;

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

void init_morra(struct morra_t *m){
    sem_init(&m->mutex, 0, 1);

    sem_init(&m->arbitro, 0, 0);
    sem_init(&m->player1, 0, 0);
    sem_init(&m->player2, 0, 0);

    m->mossa1 = m->mossa2 = -1;
    m->vincitore = 0;
}

void init_arbitro(struct morra_t *morra){
    sem_wait(&morra->mutex);
    //pausetta();
    sem_post(&morra->player1);
    //pausetta();
    sem_post(&morra->player2);
    sem_post(&morra->mutex);

    while (morra->mossa1 == -1 || morra->mossa2 == -1){
        sem_wait(&morra->arbitro);
    }
}

void *arbitro(void *arg){
    while (1){
        init_arbitro(&morra);
        sem_wait(&morra.mutex);
        //SEZIONE PLAYER 1 VINCENTE
        if (morra.mossa1 == SASSO && morra.mossa2 == FORBICE) morra.vincitore = 1;
        if (morra.mossa1 == FORBICE && morra.mossa2 == CARTA) morra.vincitore = 1;
        if (morra.mossa1 == CARTA && morra.mossa2 == SASSO) morra.vincitore = 1;
        //SEZIONE PAREGGIO
        if (morra.mossa1 == SASSO && morra.mossa2 == SASSO) morra.vincitore = 0;
        if (morra.mossa1 == FORBICE && morra.mossa2 == FORBICE) morra.vincitore = 0;
        if (morra.mossa1 == CARTA && morra.mossa2 == CARTA) morra.vincitore = 0;
        //SEZIONE PLAYER 2 VINCENTE
        if (morra.mossa2 == SASSO && morra.mossa1 == FORBICE) morra.vincitore = 2;
        if (morra.mossa2 == FORBICE && morra.mossa1 == CARTA) morra.vincitore = 2;
        if (morra.mossa2 == CARTA && morra.mossa1 == SASSO) morra.vincitore = 2;

        if (morra.vincitore != 0) printf("Il vincitore è il giocatore %d\n", morra.vincitore);
        else printf("Pareggio\n");
        morra.mossa1 = morra.mossa2 = -1;
        morra.vincitore = 0;
        sem_post(&morra.mutex);
        getchar();
    }
    
}

void player(struct morra_t *morra, int *giocatore){
    while(1){
        if (*giocatore == 1) sem_wait(&morra->player1);
        else sem_wait(&morra->player2);

        pausetta();
        sem_wait(&morra->mutex);
        if (*giocatore == 1) {
            morra->mossa1 = rand() % 3;
            switch(morra->mossa1){
                case CARTA:
                printf("Player 1: %s\n", nomi_mosse[0]);
                break;
                case SASSO:
                printf("Player 1: %s\n", nomi_mosse[1]);
                break;
                case FORBICE:
                printf("Player 1: %s\n", nomi_mosse[2]);
                break;
            }
        }
        else {
            morra->mossa2 = rand() % 3;
            switch(morra->mossa2){
                case CARTA:
                printf("Player 2: %s\n", nomi_mosse[0]);
                break;
                case SASSO:
                printf("Player 2: %s\n", nomi_mosse[1]);
                break;
                case FORBICE:
                printf("Player 2: %s\n", nomi_mosse[2]);
                break;
            }
        }
        sem_post(&morra->mutex);
        sem_post(&morra->arbitro);
    }
}

void *giocatore(void *arg){
    int giocatore = *(int *) arg;
    player(&morra, &giocatore);
}

int main(){
    pthread_attr_t a;
    pthread_t p;

    init_morra(&morra);

    srand(time(0));

    pthread_attr_init(&a);

    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    pthread_create(&p, &a, arbitro, NULL);
    int *arg = malloc(sizeof(*arg));
    for (int i=0;i<2;i++){
        *arg = i + 1;
        pthread_create(&p, &a, giocatore, (void *)arg);
        pausetta();
    }
    /**arg = 1;
    pthread_create(&p, &a, giocatore, (void *)arg);
    pausetta();
    *arg = 2;
    pthread_create(&p, &a, giocatore, (void *)arg);*/

    pthread_attr_destroy(&a);

    /* aspetto 10 secondi prima di terminare tutti quanti */
    sleep(600);

    return 0;
}