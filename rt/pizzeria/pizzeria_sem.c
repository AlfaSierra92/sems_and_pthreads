/*
Pizzeria al semaforo
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5
#define SI 1
#define NO 0

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

struct codaclienti_t{
    sem_t mutex; //mutex
    sem_t pizzasem; //blocca il pizzaiolo in caso di nessun cliente
    sem_t clienti[N]; //coda per i clienti in attesa
    sem_t cassa; //il cliente servito aspetta che siano pronte le pizze

    int ordini[N][2]; //tiene nota degli ordini
    int cliente_scelto, numero_pizze; //cleinte prescelto
    int scelgo_cliente; //il pizzaiolo deve scegliere il cliente da servire o no?
}coda;

void init_codaclienti(struct codaclienti_t *codaclienti){
    sem_init(&codaclienti->mutex, 0, 1);
    sem_init(&codaclienti->pizzasem, 0, 0);
    //sem_init(&codaclienti->clienti, 0, 0);
    sem_init(&codaclienti->cassa, 0, 0);

    for(int i=0;i<N;i++){
        sem_init(&codaclienti->clienti[i], 0, 0);
        for(int j=0;j<2;j++) codaclienti->ordini[i][j] = 0;
    }
        
    codaclienti->cliente_scelto = codaclienti->numero_pizze = -1;
    codaclienti->scelgo_cliente = SI;
}

void ordina_pizze(struct codaclienti_t *codaclienti, int numeropizze, int cliente){
    int posto = 0;
    sem_wait(&codaclienti->mutex);
    for(int i=0;i<N;i++){
        if(codaclienti->ordini[i][0] == -1){
            codaclienti->ordini[i][0] = cliente;
            codaclienti->ordini[i][1] = numeropizze;
            posto = i;
        }
    }
    sem_post(&codaclienti->mutex);
    //sem_wait(&codaclienti->clienti[posto]);
}

void ritira_pizze(struct codaclienti_t *codaclienti, int cliente){
    int posto = -1;
    for(int i=0;i<N;i++){
        if(codaclienti->ordini[i][0] == cliente) posto = i;
    }
    sem_wait(&codaclienti->clienti[posto]);
}

void prossima_pizza(struct codaclienti_t *codaclienti){
    sem_wait(&codaclienti->pizzasem);
    sem_wait(&codaclienti->mutex);
    //cerca il cliente con il minor numero di pizze nell'ordine
    if(codaclienti->scelgo_cliente == SI){
        codaclienti->cliente_scelto = codaclienti->ordini[0][0];
        codaclienti->numero_pizze = codaclienti->ordini[0][1];
        int posto = 0;
        for(int i=0;i<N;i++){
            if(codaclienti->ordini[i][1] < codaclienti->numero_pizze){
                codaclienti->cliente_scelto = codaclienti->ordini[i][0];
                codaclienti->numero_pizze = codaclienti->ordini[i][1];
                posto = i;
            }
        }
        //elimino cliente dalla coda poichè lo sto servendo
        codaclienti->ordini[posto][0] = -1;
        codaclienti->ordini[posto][1] = -1;
        codaclienti->scelgo_cliente = NO;
        for(int i=0;i<codaclienti->numero_pizze;i++) sem_post(&codaclienti->pizzasem);
    }
    sem_post(&codaclienti->mutex);

    
}


void consegna_pizza(struct codaclienti_t *codaclienti){
    //servi il cliente prescelto decrementando ad ogni ciclo le pizze
    sem_wait(&codaclienti->mutex);
    codaclienti->numero_pizze--;
    if(codaclienti->numero_pizze == 0){
        codaclienti->numero_pizze = -1;
        codaclienti->scelgo_cliente = SI;

        int posto = -1;
        for(int i=0;i<N;i++){
            if(codaclienti->ordini[i][0] == codaclienti->cliente_scelto) posto = i;
        }
        codaclienti->cliente_scelto = -1;
        sem_post(&codaclienti->clienti[posto]);
    }
    sem_post(&codaclienti->mutex);
}

void *cliente(void *arg){
    int numerocliente = *(int *) arg;
    while(1){
        int numeropizze = rand()%10;
        //vado in pizzeria
        ordina_pizze(&coda, numeropizze, numerocliente); //NON BLOCCANTE
        //attendi
        ritira_pizze(&coda, numerocliente); //BLOCCANTE
        //torna a casa
    }
    return 0;
}

void *pizzaiolo(void *arg){
    while(1){
        prossima_pizza(&coda); //UNA SOLA PIZZA - BLOCCANTE
        //impasto e cottura pizza
        consegna_pizza(&coda); //UNA SOLA PIZZA - NON BLOCCANTE
    }
    return 0;
}

int main(){
    pthread_attr_t a;
    pthread_t p;

    init_codaclienti(&coda);

    srand(time(0));

    pthread_attr_init(&a);

    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    pthread_create(&p, &a, pizzaiolo, NULL);

    for (int i=0; i<N; i++){
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&p, &a, cliente, arg);
        //pausetta();
    }

    pthread_attr_destroy(&a);

    sleep(150);

    return 0;
}