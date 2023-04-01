/*
Una discoteca ha la seguente organizzazione per far entrare i clienti nella sala da ballo:
- esiste una cassiera che emette UN BIGLIETTO ALLA VOLTA. 
Emissione del biglietto e riscossione partono assieme, ma alla fine sono non bloccanti.

- per evitare confusione alla cassa esiste una porta che fa attendere i clienti fuori dalla discoteca.
- La porta allinizio del sistema c aperta. All'arrivo del primo cliente la porta si chiude dietro di lui.
- Quando l'ULTIMO cliente in coda alla Cassa ha ritrato il biglietto (ovvero alla fine di cliente esco coda), 
se ci sono dei clienti in attesa fuori, si apre la porta, si fanno entrare (a vostra scelta se farli entrare tutti o solo parte di essi), dopo di che la porta si richiude di nuovo. 
Se non ci sono clienti in attesa fuori la porta viene aperta.

Il sistema è modellato tramite un thread per la cassiera, ed uno per ogni cliente. 
Il numero di clienti non è specificato. 
Non è importante l'ordine di accodamento dei clienti.
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define CLIENTI_MAX_DENTRO 5

#define CHIUSA 0
#define APERTA 1

struct discoteca_t{
    sem_t mutex;
    sem_t porta, cassa, cassiera;

    int coda_esterno; //numero clienti in coda all'esterno
    int coda_interno; //numero clienti in coda all'interno
    int stato_porta;
    int chiusura;
} discoteca;

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

void init_discoteca(struct discoteca_t *d){
    sem_init(&d->mutex, 0, 1); //mutex
    sem_init(&d->porta, 0, 0); 
    sem_init(&d->cassa, 0, 0); //disponibilità cassa
    sem_init(&d->cassiera, 0, 0); //disponibilità cassa

    d->coda_interno = d->coda_esterno = 0;
    d->stato_porta = APERTA;
    d->chiusura = 0;
}

//BLOCCANTE se la porta è chiusa
void cliente_coda_fuori(struct discoteca_t *d){
    sem_wait(&d->mutex);
    if (d->stato_porta == CHIUSA){
        d->coda_esterno++; //lo decrementerò alla fine di cliente_esco_coda
    } else {
        d->stato_porta = CHIUSA;
        sem_post(&d->porta);
        d->coda_interno++;
    }
    sem_post(&d->mutex);
    sem_wait(&d->porta);
}

//BLOCCANTE se la cassa è occupata
void cliente_coda_dentro(struct discoteca_t *d){
    sem_wait(&d->cassa);
    sem_wait(&d->mutex);
    d->coda_interno--;
    sem_post(&d->mutex);
}

//NON BLOCCANTE
void cliente_esco_coda(struct discoteca_t *d){
    sem_wait(&d->mutex);
    if (d->coda_interno == 0){
        d->stato_porta = APERTA;
        for(int i=0; i<CLIENTI_MAX_DENTRO; i++){
            d->coda_esterno--;
            sem_post(&d->porta);
            d->coda_interno++;
        }
        d->stato_porta = CHIUSA;
    }
    sem_post(&d->mutex);
}

//BLOCCANTE
//la cassiera dice "avanti!"
void cassiera_attesa_cliente(struct discoteca_t *d){
    sem_wait(&d->mutex);
    if(d->coda_interno > 0) {
        sem_post(&d->cassa);
        printf("%s", "Cliente servito dalla cassa\n");
    }
    
    sem_post(&d->mutex);
}

//NON BLOCCANTE
void cassiera_cliente_servito(struct discoteca_t *d){
    printf("%s", "Biglietto emesso\n");
}

void *cliente(void *arg){
    pthread_t tid = pthread_self();
    //printf("Il thread corrente ha l'id: %lu\n", (unsigned long)tid);
    printf("%lu %s", (unsigned long)tid, "Arrivo in disco\n");
    cliente_coda_fuori(&discoteca);
    printf("%lu %s", (unsigned long)tid, "fa biglietto\n");
    cliente_coda_dentro(&discoteca);
    printf("%lu %s", (unsigned long)tid, "paga e ritira biglietto\n");
    cliente_esco_coda(&discoteca);
    printf("%lu %s", (unsigned long)tid, "balla!\n");
}

void *cassiera(void *arg){
    int i=0;
    while(i<15){
        if (&discoteca.coda_interno != 0){
            cassiera_attesa_cliente(&discoteca);
            printf("%s", "Emetto biglietto\n");
            cassiera_cliente_servito(&discoteca);
            printf("%s", "$$$\n");
            i++;
        }
        
        pausetta();
    }
}

int main(){
    pthread_attr_t a;
    pthread_t p;
    
    /* inizializzo il mio sistema */
    init_discoteca(&discoteca);

    /* inizializzo i numeri casuali, usati nella funzione pausetta */
    srand(555);

    pthread_attr_init(&a);

    /* non ho voglia di scrivere 10000 volte join! */
    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    pthread_create(&p, &a, cassiera, (void *)"1");

    int i=0;
    while(i<15){
        pthread_create(&p, &a, cliente, (void *)"1");
        i++;
    }

    pthread_attr_destroy(&a);
    /* aspetto 10 secondi prima di terminare tutti quanti */
    sleep(10);
    printf("%s", "Chiusura!\n");

    return 0;
}