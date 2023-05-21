/*
Esercizio Pasticceria.
Una pasticceria produce e vende al dettaglio delle torte. La pasticceria è gestita da un cuoco, che cucina le torte
con arte, e da un commesso, che prende le torte prodotte, le incarta e le vende al dettaglio. Il pasticcere evita di
iniziare a produrre torte se in pasticceria ci sono piu' di N torte invendute. I clienti acquistano una torta alla
volta. La vendita di una torta da parte del commesso coincide con l'acquisto da parte del cliente.
Il sistema è modellato tramite un thread per il cuoco, uno per il commesso, ed uno per ogni cliente. Il numero di
clienti non è specificato, e non è importante il loro ordine di accodamento
*/
/*
NOTA 1:
Allo start del programma, quando ovviamente non ci sono torte,
il cuoco fa il post sul semaforo commesso, semaforo che rimarrà sempre a 1
fino a quando le torte saranno nuovamente 0.
In quel momento entrerà nel blocco della if e farà la wait sul semaforo il
quale non bloccherà; successivamente essendo il numero delle torte negativo,
non passerà più quella if generando un ciclo che consuma torte negative.
Per risolvere questo problema, faccio in modo che il commesso all'apertura del negozio,
dia per scontato che c'è già almeno una torta disponibile alla vendita mediante la variabile
apertura_negozio che sarà a 0 solo allo start e poi rimarrà sempre settata a 1.

NOTA 2:
Il cuoco, una volta aperto il negozio, riempe tutta la vetrina di torte ma non aspetta che si svuoti completamente per rimettersi all'opera;
ogni volta che ne viene venduta una ricomincia a lavorare per riempire immediatamente lo spazio vuoto.
*/

#define USA_SEM
//#define USA_PTHREAD

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 50 //numero massimo di torte invendute
#define CLIENTI 25

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

#ifdef USA_SEM
struct pasticceria_t { 
    sem_t mutex;
    sem_t cuoco; //serve per bloccare il cuoco se ci sono troppe torte
    sem_t commesso; //serve per bloccare commesso in caso di assenza di torte
    sem_t cliente; //aspetta la disponibilità del commesso
    sem_t cassa; //blocca il commesso aspettando che "il cliente che paghi"
    sem_t acquisto; //blocca il cliente aspettando che la transazione sia ok
    //cosa succede se non ci sono torte? Il cliente non viene sbloccato dal
    //commesso!

    int torte_invendute;
    int apertura_negozio;
    //sem_t torte;

} pasticceria;

void init_pasticceria(struct pasticceria_t *p){
    sem_init(&p->mutex, 0, 1);
    sem_init(&p->cuoco, 0, 0);
    sem_init(&p->cliente, 0, 0);
    sem_init(&p->commesso, 0, 0);
    sem_init(&p->cassa, 0, 0);
    sem_init(&p->acquisto, 0, 0);

    p->torte_invendute = 0;
    p->apertura_negozio = 0;
}

void cuoco_inizio_torta(struct pasticceria_t *p){
    sem_wait(&p->mutex);
    if (p->torte_invendute > N-1) {
        sem_post(&p->mutex);
        printf("Stop cuoco.\n");
        sem_wait(&p->cuoco);
    } else sem_post(&p->mutex);
}

void cuoco_fine_torta(struct pasticceria_t *p){
    sem_wait(&p->mutex);
    if (p->torte_invendute == 0){
        p->torte_invendute++;
        if (p->apertura_negozio != 0) //vedi nota 1 in testa
            sem_post(&p->commesso); //sblocca il commesso che aspetta almeno una torta
    } else p->torte_invendute++;
    printf("Ci sono %d torte in vetrina.\n\n", p->torte_invendute);
    
    sem_post(&p->mutex);
}

void commesso_prendo_torta(struct pasticceria_t *p){
    sem_wait(&p->mutex);
    if (p->torte_invendute == 0) {
        sem_post(&p->mutex);
        sem_wait(&p->commesso); //aspetta che sia disp una torta
        sem_wait(&p->mutex);
    }
    p->apertura_negozio = 1;
    sem_post(&p->cliente); //avanti il prossimo cliente!
    sem_post(&p->mutex);
}

void commesso_vendo_torta(struct pasticceria_t *p){
    sem_wait(&p->cassa);//aspetto che si avvicini il cliente
    sem_wait(&p->mutex);
    //p->torte_invendute--;
    if (p->torte_invendute == N) {
        p->torte_invendute--; //il cuoco, che nel frattempo si era fermato,
        printf("Cuoco al lavorooo!\n"); //viene rimesso al lavoro
        sem_post(&p->cuoco); 
    } else {
        p->torte_invendute--;
        //sem_post(&p->cliente);
    }
    sem_post(&p->mutex);
    printf("Ho venduto la torta!\n\n");
    sem_post(&p->acquisto);
}

void cliente_acquisto(struct pasticceria_t *p){
    sem_wait(&p->cliente);//aspetto che il commesso sia pronto a servirmi
    sem_post(&p->cassa);//mi avvicino e inizio la transazione
    sem_wait(&p->acquisto);//aspetto che la transazione sia ok
}

void *cuoco(void *arg){
    while(1) {
        cuoco_inizio_torta(&pasticceria); // 1 torta; può essere bloccante
        printf("Preparo torta.\n");
        cuoco_fine_torta(&pasticceria); // 1 torta; non bloccante
    }
}

void *commesso(void *arg){
    while(1) {
        commesso_prendo_torta(&pasticceria); // 1 torta; bloccante
        printf("Incarto la torta in una confezione colorata.\n");
        commesso_vendo_torta(&pasticceria); // 1 torta; bloccante se non ci sono clienti
    }
}

void *un_cliente(void *arg){
    int cliente = *(int *) arg;
    while (1) {
        printf("%d va in pasticceria per comprare una torta sopraffina.\n", cliente);
        cliente_acquisto(&pasticceria); // 1 torta; bloccante
        printf("Torno a casa a mangiare la torta.\n");
        sleep(1);
        pausetta();
    }
}
#endif

int main(){
    pthread_attr_t a;
    pthread_t p;

    init_pasticceria(&pasticceria);

    srand(time(0));

    pthread_attr_init(&a);

    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    pthread_create(&p, &a, cuoco, NULL);
    pthread_create(&p, &a, commesso, NULL);

    for (int i=0; i<CLIENTI; i++){
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&p, &a, un_cliente, arg);
        //pausetta();
    }

    pthread_attr_destroy(&a);

    sleep(150);

    return 0;
}