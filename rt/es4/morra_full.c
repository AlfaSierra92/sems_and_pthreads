/*
Esercizio 4

Errori commessi:
-rand() non funzionante (restituiva sempre zero);
-rand() configurata male (restituiva anche il valore 3 che rompeva l'esecuzione dei threads);
-qualche errato posizionamento dei semafori (poca roba).
*/
//#define USA_SEM
#define USA_MUTEX

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define CARTA 0
#define SASSO 1
#define FORBICE 2

char *nomi_mosse[3] = {"carta", "sasso", "forbice"};

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

#ifdef USA_SEM

struct morra_t{
    sem_t mutex;
    sem_t arbitro;
    sem_t player1,player2;

    int mossa1, mossa2;
    int vincitore;
}morra;

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
        printf("\n");
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

#endif

#ifdef USA_MUTEX

struct morra_t{
    pthread_mutex_t mutex;
    pthread_cond_t arbitro;
    pthread_cond_t player1,player2;

    int mossa1, mossa2;
    int sveglia1, sveglia2;
    int vincitore;
}morra;

void init_morra(struct morra_t *m){
    pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;
    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);

    pthread_mutex_init(&m->mutex, &m_attr);

    pthread_cond_init(&m->arbitro, &c_attr);
    pthread_cond_init(&m->player1, &c_attr);
    pthread_cond_init(&m->player2, &c_attr);

    pthread_condattr_destroy(&c_attr);
    pthread_mutexattr_destroy(&m_attr);

    m->mossa1 = m->mossa2 = -1;
    m->sveglia1 = m->sveglia2 = 0;
    m->vincitore = 0;
}

void init_arbitro(struct morra_t *morra){
    pthread_mutex_lock(&morra->mutex);
    //pausetta();
    pthread_cond_signal(&morra->player1);
    //pausetta();
    pthread_cond_signal(&morra->player2);
    morra->sveglia1 = morra->sveglia2 = 1;
    //pthread_mutex_unlock(&morra->mutex);

    //pthread_mutex_lock(&morra->mutex);
    while (morra->mossa1 == -1 || morra->mossa2 == -1){
        //pthread_mutex_lock(&morra->mutex);
        pthread_cond_wait(&morra->arbitro,&morra->mutex);
        //pthread_mutex_unlock(&morra->mutex);
    }
    pthread_mutex_unlock(&morra->mutex);
}

void *arbitro(void *arg){
    while (1){
        init_arbitro(&morra);
        pthread_mutex_lock(&morra.mutex);
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
        printf("\n");
        morra.mossa1 = morra.mossa2 = -1;
        morra.vincitore = 0;
        pthread_mutex_unlock(&morra.mutex);
        getchar();
    }
    
}

void player(struct morra_t *morra, int *giocatore){
    while(1){
        pthread_mutex_lock(&morra->mutex);
        if (*giocatore == 1) {
            while (morra->sveglia1 != 1){
                pthread_cond_wait(&morra->player1,&morra->mutex);
            }
            morra->sveglia1 = 0;
        }
        else {
            while (morra->sveglia2 != 1){
                pthread_cond_wait(&morra->player2,&morra->mutex);
            }
            morra->sveglia2 = 0;
        }
        pthread_mutex_unlock(&morra->mutex);

        pausetta();
        //sem_wait(&morra->mutex);
        pthread_mutex_lock(&morra->mutex);
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
        pthread_mutex_unlock(&morra->mutex);
        pthread_cond_signal(&morra->arbitro);
    }
}

void *giocatore(void *arg){
    int giocatore = *(int *) arg;
    player(&morra, &giocatore);
}

#endif

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
    sleep(120);

    return 0;
}