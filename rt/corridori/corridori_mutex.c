/*
In uno stadio ci sono N corridori pronti a partire sulla pista dei 100 mt. Al via dell'arbitro, tutti i corridori iniziano a correre.
Dopo alcuni secondi tutti i corridori arrivano al traguardo. Quando l'ultimo corridore raggiunge il traguardo l'arbitro annuncia il primo e l'ultimo classificato.

Il sistema è modellato con un thread per ogni corridore, ed un thread per l'arbitro. Il corridore arriva al punto di partenza ed aspetta il via dell'arbitro. 
Quando l'arnitro da il via, il corridore corre ed arriva al traguardo. L'arbitro arriva ed attende che tutti i corridori siano posizionati. Dopo di che da il via alla gara,
e si mette in attesa dell'arrivo dell'ultimo corridore. Non appena l'ultimo corridore arriva, l'arbitro comunica il primo e l'ultimo classificato della gara.

struct corsa_t { ... } corsa;
void init_corsa(struct corsa_t *s);
void corridore_attendivia(struct corsa_t *corsa, int numerocorridore);
void corridore_arrivo(struct corsa_t *corsa, int numerocorridore);
void arbitro_attendicorridori(struct corsa_t *corsa);
void arbitro_via(struct corsa_t *corsa);
void arbitro_risultato(struct corsa_t *corsa, int *primo, int *ultimo);

void //*corridore(void *arg){
    <vado sulla pista>
    corridore_attendivia(struct corsa_t *corsa, int numerocorridore); //BLOCKING
    <corro più veloce possibile>
    corridore_arrivo(struct corsa_t *corsa, int numerocorridore); //NON BLOCKING
    <torno a casa>
}

void //*arbitro(void *arg){
    <vado sulla pista>
    arbitro_attendicorridori(struct corsa_t *corsa); //BLOCKING
    <pronti, partenza, ...>
    arbitro_via(struct corsa_t *corsa); //NON BLOCKING
    <attendo tutti i corridori>
    arbitro_risultato(struct corsa_t *corsa, int *primo, int *ultimo); //BLOCKING
}
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 15

struct corsa_t{
    pthread_mutex_t mutex;
    pthread_cond_t partenza, arrivo;
    pthread_cond_t arbitro;

    //numero runners che partono e arrivano
    int corridori_partenza, corridori_arrivo;

    int starter;

    //numero del vincitore e dell'ultimo arrivato
    int numero_primo_arrivato, numero_ultimo_arrivato;

}corsa;

void pausetta(void){
  struct timespec t;
  t.tv_sec = 0;
  t.tv_nsec = (rand()%10+1)*1000000;
  nanosleep(&t,NULL);
}

void init_corsa(struct corsa_t *c){
    pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;
    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);
    
    pthread_mutex_init(&c->mutex, &m_attr);

    pthread_cond_init(&c->partenza, &c_attr);
    pthread_cond_init(&c->arrivo, &c_attr);
    pthread_cond_init(&c->arbitro, &c_attr);

    pthread_condattr_destroy(&c_attr);
    pthread_mutexattr_destroy(&m_attr);

    //inzialmente non c'è nessuno ai posti di partenza
    //e ovviamente nessuno al traguardo
    c->corridori_partenza = c->corridori_arrivo = c->starter = 0;
    //nessun vincitore ne vinto
    c->numero_primo_arrivato = c->numero_ultimo_arrivato = -1;
}

void corridore_attendivia(struct corsa_t *corsa, int numerocorridore){
    //si pone sul semaforo partenza e incrementa il numero di corridori
    //sulla linea di partenza
    //sblocca arbitro_attendicorridori quando il numero è 
    //strettamente uguale a N
    pthread_mutex_lock(&corsa->mutex);
    printf("%d: attendi via\n", numerocorridore);
    corsa->corridori_partenza++;
    if (corsa->corridori_partenza == N) {
        corsa->starter = 1;
        pthread_cond_signal(&corsa->arbitro);
    }
    //pthread_mutex_unlock(&corsa->mutex);
    //sem_wait(&corsa->partenza);

    while (corsa->starter == 0) {
        pthread_cond_wait(&corsa->partenza, &corsa->mutex);
    }
    pthread_mutex_unlock(&corsa->mutex);
}

void corridore_arrivo(struct corsa_t *corsa, int numerocorridore){
    //il primo che arriva pone a primo_arrivato a numerocorridore 
    //(corridori_arrivo sarà uguale a zero)
    //appena arriva l'ultimo pone ultimo_arrivato a numerocorridore
    //(corridori_arrivo sarà uguale a N)
    //e sblocca arbitro_risultato fermo sul semaforo arbitro
    pthread_mutex_lock(&corsa->mutex);
    if (corsa->corridori_arrivo == 0) { //primo
        corsa->corridori_arrivo++;
        corsa->numero_primo_arrivato = numerocorridore;
        pthread_mutex_unlock(&corsa->mutex);
    } else if (corsa->corridori_arrivo < N-1) { //gli altri
        corsa->corridori_arrivo++;
        pthread_mutex_unlock(&corsa->mutex);
    } else { //l'ultimo
        corsa->corridori_arrivo++;
        corsa->numero_ultimo_arrivato = numerocorridore;
        pthread_cond_signal(&corsa->arbitro);
        pthread_mutex_unlock(&corsa->mutex);
    }
    //sem_post(&corsa->mutex);
}

void arbitro_attendicorridori(struct corsa_t *corsa){
    //aspetta sul semaforo arbitro
    //finchè non arrivano N corridori sulla linea di partenza
    pthread_mutex_lock(&corsa->mutex);
    while (corsa->starter == 0) {
        pthread_cond_wait(&corsa->arbitro,&corsa->mutex);
    }
    printf("On your marks, get set...\n");
    pthread_mutex_unlock(&corsa->mutex);
}

void arbitro_via(struct corsa_t *corsa){
    //da' il via con broadcast
    pthread_mutex_lock(&corsa->mutex);
    for (int i=0; i<N; i++){
        pthread_cond_broadcast(&corsa->partenza);
        printf("Risveglio %d\n", i);
    }
    printf("...Go!\n");
    pthread_mutex_unlock(&corsa->mutex);
}

void arbitro_risultato(struct corsa_t *corsa, int *primo, int *ultimo){
    //aspetta sul semaforo arbitro
    //fino a che N corridori arrivino sul semaforo arrivo
    pthread_mutex_lock(&corsa->mutex);
    while(corsa->corridori_arrivo < N){
        pthread_cond_wait(&corsa->arbitro,&corsa->mutex);
    }

    *primo = corsa->numero_primo_arrivato;
    *ultimo = corsa->numero_ultimo_arrivato;
    printf("Il vincitore e': %d\n", *primo);
    printf("L'ultimo e': %d\n", *ultimo);
    pthread_mutex_unlock(&corsa->mutex);
}

void *corridore(void *arg){
    //<vado sulla pista>
    pausetta();
    corridore_attendivia(&corsa, *(int *)arg); //BLOCKING (numerocorridore)
    //<corro più veloce possibile>
    pausetta();
    corridore_arrivo(&corsa, *(int *)arg); //NON BLOCKING (numerocorridore)
    //<torno a casa>
}

void *arbitro(void *arg){
    //<vado sulla pista>
    pausetta();
    arbitro_attendicorridori(&corsa); //BLOCKING
    //<pronti, partenza, ...>
    pausetta();
    arbitro_via(&corsa); //NON BLOCKING
    //<attendo tutti i corridori>
    pausetta();

    int primo, ultimo;
    arbitro_risultato(&corsa, &primo, &ultimo); //BLOCKING
}

int main(){
    pthread_attr_t a;
    pthread_t p;

    init_corsa(&corsa);

    srand(555);

    pthread_attr_init(&a);

    pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);

    pthread_create(&p, &a, arbitro, NULL);

    for (int i=0;i<=N;i++){
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&p, &a, corridore, arg);
    }
    sleep(5);
}