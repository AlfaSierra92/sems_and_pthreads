sabato 8 ottobre 2022
16:52

1. Durante l'evoluzione dei Sistemi Operativi, nel modello dei processi ad ambienti globale nasce la necessità di introdurre costrutti per la sincronizzazione, poiché i semafori:

    1. non consentono di risolvere tutti i problemi di competizione

    2. non consentono di risolvere tutti i problemi di cooperazione e competizione

    3. non sono di semplice utilizzo, in quanto strumenti di basso livello☑️
    4. non consentono di risolvere tutti i problemi di mutua esclusione

1. Facendo riferimento al problema della cena dei filosofi, la soluzione che prevede l'utilizzo di un semaforo di mutua esclusione per ogni bastoncino, è sbagliata perchè

    1. non evita possibili casi di starvation
    2. non evita possibili casi di deadlock☑️
    3. nessuna delle alternative presenti
    4. non evita possibili casi di deadlock e starvation

1. In un Sistema Operativo che usa un modello dei processi ad ambiente globale, si considerino tre processi P1, P2 e P3, e due semafori generalizzati S1 e S2 inizializzati a zero. I processi hanno la seguente struttura: P1 - while (1) {signal(S1)}; P2 - while (1) {wait(S1); print('A'); signal(S2);}; P3 - while (1) {wait(S2); print('B');}. Quale fra le seguenti sequenze NON può essere stampata?

    1. AABBAABBAA...
    2. AAABBABBBA....☑️
    3. AAABBAABBBA....
    4. ABABABAB.....

1. Facendo riferimento al problema dei processi lettori/scrittori, per evitare starvation dei processi scrittori bisogna che:

    1. tutti i processi lettori in attesa, alla fine di una scrittura, abbiano accesso prioritario alla risorsa rispetto ai processi scrittori

    2. i processi lettori abbiano la precedenza sui processi scrittori

    3. un processo lettore non acceda alla risorsa se ci sono processi scrittori in attesa☑️

    4. un processo scrittore non acceda alla risorsa se c'è un processo lettore in attesa

1. Facendo riferimento al problema dei processi lettori/scrittori, per evitare starvation dei processi lettori bisogna che:

    1. tutti i processi lettori in attesa, alla fine di una scrittura, abbiano accesso prioritario alla risorsa rispetto ai processi scrittori☑️

    2. i processi lettori abbiano la precedenza sui processi scrittori

    3. un processo lettore non acceda alla risorsa se ci sono processi scrittori in attesa

    4. un processo scrittore non acceda alla risorsa se c'è un processo lettore in attesa

1. In un Sistema Operativo che usa un modello dei processi ad ambiente globale, quando si considera accettabile l'utilizzo delle operazioni indivisibili lock e unlock per proteggere una sezione critica?

    1. nel caso non sia possibile effettuare un'attesa attiva
    2. nessuna delle alternative presenti
    3. nel caso la sezione critica sia sufficientemente breve☑️

    4. nel caso i processi che eseguono la sezione critica siano indipendenti fra loro

1. In un Sistema Operativo che usa un modello dei processi ad ambiente globale, si considerino due processi P1, P2, e un semaforo generalizzato S1 inizializzato a zero, con il seguente codice: P1 - int I = 0; while (1) { I = I + 2; print (I); signal(S1); }; P2 - int J = 1; while (1) { wait(S1); J = J + 2; print(J); }. Quale fra le seguenti sequenze NON può essere stampata?

    1. 2 3 4 5 6 7 8 .....
    2. 2 4 6 8 10 12 14....
    3. 2 4 3 5 7 6 8 ....☑️
    4. 2 4 3 5 6 8 7 ...

1. In un Sistema Operativo che usa un modello dei processi ad ambiente globale, considerando di avere una architettura multiprocessore strettamente connessa (con memoria condivisa), come si realizza l'indivisibilità delle operazioni wait e signal sui semafori?

    1. è sufficiente usare nella implementazione delle operazioni wait e signal sui semafori le operazioni indivisibili lock e unlock, con la lock realizzata a sua volta usando le istruzioni HW TEST_AND_SET oppure EXCHANGE☑️

    2. è sufficiente usare, invece che le operazioni wait e signal sui semafori, le operazioni indivisibili lock e unlock

    3. è sufficiente usare, invece che le operazioni wait e signal sui semafori, le istruzioni HW TEST_AND_SET oppure EXCHANGE

    4. è sufficiente il meccanismo di disabilitazione delle interruzioni

1. In un Sistema Operativo che usa un modello dei processi ad ambiente globale, la semantica della operazione SIGNAL su un semaforo implica che:

    1. si controlli la coda associata al semaforo e se ci sono dei processi il primo viene fatto transitare dallo stato SOSPESO allo stato PRONTO, mentre in caso contrario il valore del semaforo deve essere incrementato☑️

    2. il valore del semaforo deve essere incrementato
    3. il valore del semaforo deve essere decrementato

    4. si controlli la coda associata al semaforo e se ci sono dei processi il primo viene fatto transitare dallo stato SOSPESO allo stato IN ESECUZIONE, mentre in caso contrario il valore del semaforo deve essere incrementato

1. In un Sistema Operativo che usa un modello dei processi ad ambiente globale, la semantica della operazione WAIT su un semaforo implica che:

    1. si controlli il valore associato al semaforo e se tale valore è 0 il processo deve transitare da stato IN ESECUZIONE a stato SOSPESO, mentre in caso contrario il valore del semaforo deve essere decrementato☑️

    2. il valore del semaforo deve essere decrementato
    3. il valore del semaforo deve essere incrementato

    4. il processo deve sempre transitare da stato IN ESECUZIONE a stato SOSPESO

1. In un Sistema Operativo che usa un modello dei processi ad ambiente globale, la semantica della operazione SIGNAL su una variabile CONDIZIONE di un monitor implica che:

    1. il valore della variabile CONDIZIONE deve essere incrementato

    2. si controlli la coda associata alla variabile CONDIZIONE e se ci sono dei processi il primo viene fatto transitare dallo stato SOSPESO allo stato IN ESECUZIONE, , mentre in caso contrario non succede nulla

    3. si controlli la coda associata alla variabile CONDIZIONE e se ci sono dei processi il primo viene fatto transitare dallo stato SOSPESO allo stato PRONTO, mentre in caso contrario non succede nulla☑️

    4. il valore della variabile CONDIZIONE deve essere decrementato

1. In un Sistema Operativo che usa un modello dei processi ad ambiente globale, la semantica della operazione WAIT su una variabile CONDIZIONE di un monitor implica che:

    1. il processo deve sempre transitare da stato IN ESECUZIONE a stato SOSPESO☑️

    2. il valore della variabile CONDIZIONE deve essere decrementato
    3. il valore della variabile CONDIZIONE deve essere incrementato

    4. si controlli il valore associato alla variabile CONDIZIONE e se tale valore è 0 il processo deve transitare da stato IN ESECUZIONE a stato SOSPESO, mentre in caso contrario il valore deve essere decrementato

1. Durante l'evoluzione dei Sistemi Operativi, in caso di modello dei processi ad ambiente globale, la motivazione principale che ha portato all'introduzione del costrutto Monitor fu:

    1. l'impossibilità di risolvere tutti i problemi di sincronizzazione tramite l'utilizzo di semafori

    2. la necessità di nascondere ai processi lo stato interno delle risorse condivise☑️

    3. la possibilità di sospendere i processi solamente all'inizio delle sezioni critiche

    4. nessuna delle alternative presenti

1. Nell'ambito della cooperazione tra processi, in quale modello dei processi si può presentare il problema produttore/consumatore?

    1. Sia nel caso in cui il modello dei processi è ad ambiente globale e sia nel caso in cui il modello dei processi è ad ambiente locale☑️

    2. Solo nel caso in cui il modello dei processi è ad ambiente globale
    3. Solo nel caso in cui il modello dei processi è ad ambiente locale

    4. Solo nel caso in cui il modello dei processi è ad ambiente locale e l'architettura è a memoria comune