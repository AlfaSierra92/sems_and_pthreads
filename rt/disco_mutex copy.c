#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define CLIENTI_MAX_DENTRO 35
#define CLIENTI_MAX_SERATA 5

#define CHIUSA 0
#define APERTA 1

#define CASSA_DISPONIBILE 0
#define CASSA_INDISPONIBILE 1

#define CLIENTE_PRESENTE 0
#define CLIENTE_NON_PRESENTE 1

struct discoteca_t{
    pthread_mutex_t mutex;
    pthread_cond_t porta; //coda esterna
    pthread_cond_t cassa; //coda interna
    pthread_cond_t cassiera;

    int coda_esterno; //numero clienti in coda all'esterno
    int coda_interno; //numero clienti in coda all'interno
    int stato_porta, disponibilita_cassa, presenza_cliente;
    int chiusura;
} discoteca;

void pausetta(void){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand()%10+1)*1000000;
    nanosleep(&t,NULL);
}

void init_discoteca(struct discoteca_t *d){
    pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;

    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);

    pthread_mutex_init(&d->mutex, &m_attr); //mutex
    pthread_cond_init(&d->porta, &c_attr); 
    pthread_cond_init(&d->cassa, &c_attr); //disponibilità cassa
    pthread_cond_init(&d->cassiera, &c_attr); //disponibilità cassiera

    d->coda_interno = d->coda_esterno = 0;
    d->stato_porta = APERTA;
    d->disponibilita_cassa = CASSA_INDISPONIBILE;
    d->presenza_cliente = CLIENTE_NON_PRESENTE;
    d->chiusura = 0;
}

//BLOCCANTE se la porta è chiusa
void cliente_coda_fuori(struct discoteca_t *d){
    pthread_mutex_lock(&d->mutex);
    if (d->stato_porta == APERTA) {
        d->stato_porta = CHIUSA;
        printf("=== PORTA CHIUSA ===\n");
        d->coda_interno++;
    } else {
        d->coda_esterno++;
        while (d->stato_porta == CHIUSA){
            pthread_cond_wait(&d->porta,&d->mutex);
        }
        d->coda_esterno--;
        d->coda_interno++;
    }
    pthread_mutex_unlock(&d->mutex);
}

//BLOCCANTE se la cassa è occupata
void cliente_coda_dentro(struct discoteca_t *d){
    pthread_mutex_lock(&d->mutex);
    while(d->disponibilita_cassa != CASSA_DISPONIBILE){
        pthread_cond_wait(&d->cassa,&d->mutex);
    }
    d->presenza_cliente = CLIENTE_PRESENTE;
    pthread_cond_signal(&d->cassiera);
    pthread_mutex_unlock(&d->mutex);
    
    //pthread_mutex_lock(&d->mutex);
    
    //pausetta();
}

//NON BLOCCANTE
void cliente_esco_coda(struct discoteca_t *d){
    //pthread_mutex_lock(&d->mutex);
    if (d->coda_interno == 0){
        //printf("%s", "=== PORTA APERTA ===\n");
        pthread_mutex_lock(&d->mutex);
        d->stato_porta = APERTA;
        //pthread_mutex_unlock(&d->mutex);
        if (d->coda_interno <= CLIENTI_MAX_DENTRO && d->coda_esterno > 0){
            //pthread_mutex_lock(&d->mutex);
            //d->stato_porta = APERTA;
            pthread_cond_signal(&d->porta);
            //d->stato_porta = CHIUSA;
            //pthread_mutex_unlock(&d->mutex);
        }
        //pthread_cond_signal(&d->porta);
        //pthread_mutex_lock(&d->mutex);
        d->stato_porta = CHIUSA;
        pthread_mutex_unlock(&d->mutex);
        //printf("%s", "=== PORTA CHIUSA ===\n");
    }
    //pthread_mutex_unlock(&d->mutex);
}

//BLOCCANTE
//la cassiera dice "avanti!"
void cassiera_attesa_cliente(struct discoteca_t *d){
    pthread_mutex_lock(&d->mutex);
    d->disponibilita_cassa = CASSA_DISPONIBILE;
    //pthread_mutex_unlock(&d->mutex);
    pthread_cond_signal(&d->cassa);
    while(d->presenza_cliente == CLIENTE_NON_PRESENTE){
        pthread_cond_wait(&d->cassiera,&d->mutex);
    }
    d->presenza_cliente = CLIENTE_NON_PRESENTE;
    //pthread_mutex_lock(&d->mutex);
    d->coda_interno--;
    d->disponibilita_cassa = CASSA_INDISPONIBILE;
    pthread_mutex_unlock(&d->mutex);
    
}

//NON BLOCCANTE
void cassiera_cliente_servito(struct discoteca_t *d){
    printf("%s", "Biglietto emesso\n");

}

void *cliente(void *arg){
    pthread_t tid = pthread_self();
    printf("%lu %s", (unsigned long)tid, "arriva fuori in disco\n");
    cliente_coda_fuori(&discoteca);
    printf("%lu %s", (unsigned long)tid, "entra dentro\n");
    cliente_coda_dentro(&discoteca);

    //DA QUI PARTE ZONA NON BLOCCANTE
    printf("%lu %s", (unsigned long)tid, "paga e ritira biglietto\n");
    cliente_esco_coda(&discoteca);
    printf("%lu %s", (unsigned long)tid, "balla!\n");
}

void *cassiera(void *arg){
    int i=0;
    while(i<CLIENTI_MAX_SERATA){
        cassiera_attesa_cliente(&discoteca);

        //DA QUI PARTE ZONA NON BLOCCANTE
        printf("%s", "Emetto biglietto\n");
        cassiera_cliente_servito(&discoteca);
        printf("%s", "$$$\n");
        //pausetta();
        i++;
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
    while(i<CLIENTI_MAX_SERATA){
        pausetta();
        pthread_create(&p, &a, cliente, (void *)"1");
        i++;
        
    }

    pthread_attr_destroy(&a);
    /* aspetto 10 secondi prima di terminare tutti quanti */
    sleep(200);
    printf("%s", "Chiusura!\n");

    return 0;
}