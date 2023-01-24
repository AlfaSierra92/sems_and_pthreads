domenica 2 ottobre 2022
16:44

1. Nell'ambito del problema della MUTUA ESCLUSIONE nel modello dei processi ad ambiente globale, per quale motivo garantire l'assenza di ATTESA ATTIVA può portare a starvation per i processi che eseguono le sezioni critiche?

    1. La starvation si presenta solo se abbiamo due processi che devono escludersi mutuamente e quindi il problema è trascurabile

    2. Perché si deve garantire assenza di DEADLOCK che è un problema più importante della starvation

    3. Se si garantisce il terzo requisito che è quello della assenza di condizioni di stallo per i processi che eseguono le sezioni critiche di una stessa classe, automaticamente è garantita l'assenza di starvation

    4. Perché, per non avere ATTESA ATTIVA, i processi vengono sospesi in attesa di entrare nella sezione critica di una certa classe e potrebbero essere continuamente ”scavalcati” da altri processi☑️

1. In un Sistema Operativo basato sul modello dei processi ad Ambiente Globale, quali tipi di interazioni fra processi si possono avere?

    1. solo cooperazione
    2. l'utente può decidere quale tipo di interazione attivare
    3. solo competizione
    4. competizione e cooperazione☑️

1. In un Sistema Operativo che usa un modello dei processi ad ambiente globale cosa si intende per semaforo generalizzato o contatore?

    1. Un semaforo inizializzato a 0

    2. Un semaforo che può assumere tutti i valori interi positivi, compreso il valore 0☑️

    3. Un semaforo che può assumere tutti i valori interi positivi, ma non il valore 0

    4. Un semaforo che può assumere tutti i valori interi, positivi e negativi

1. Nell'ambito del modello dei processi ad ambiente globale, per garantire la MUTUA ESCLUSIONE, perché la soluzione che disabilita/riabilita le interruzioni come PROLOGO/EPILOGO ad una classe di SEZIONI CRITICHE non è una soluzione accettabile?

    1. Perché vengono violati tutti i requisiti che deve avere una soluzione per essere considerata accettabile per risolvere il problema della MUTUA ESCLUSIONE

    2. Perché è una soluzione parziale che funziona solo nel caso di monoprocessore e comunque esclude mutuamente NON SOLO sezioni critiche della stessa classe, ma elimina ogni possibilità di concorrenza e rende insensibile il sistema ad ogni stimolo esterno per tutta la durata di una qualunque sezione critica☑️

    3. Perché l'unica soluzione è usare LOCK/UNLOCK
    4. Perché vale solo per due processi

1. Quale tra questi NON è un requisito necessario per ottenere una soluzione accettabile al problema della mutua esclusione:

    1. dipendenza tra i processi che eseguono sezioni critiche☑️
    2. assenza di starvation per i processi che eseguono le sezioni critiche
    3. interruzioni abilitate durante l'esecuzione delle sezioni critiche
    4. assenza di attese attive per i processi che eseguono le sezioni critiche

1. Facendo riferimento all'uso di semafori nel modello dei processi ad ambiente globale, quanti semafori e con che valore iniziale servono per garantire l'esecuzione corretta di N sezioni critiche appartenenti alla stessa classe?

    1. N semafori inizializzati a N
    2. 1 semaforo inizializzato ad 1;☑️
    3. N semafori inizializzati ad 1;
    4. 1 semaforo inizializzato ad N

1. Nell'ambito del modello dei processi ad ambiente globale, per garantire la MUTUA ESCLUSIONE, a cosa servono il PROLOGO e l'EPILOGO che devono essere eseguiti prima e dopo una SEZIONE CRITICA?

    1. Il PROLOGO e l'EPILOGO servono solo nel caso di SEZIONI CRITICHE sufficientemente brevi

    2. Il PROLOGO si deve occupare di porre il valore del semaforo a 0 in modo da acquisire la SEZIONE CRITICA, mentre l'EPILOGO si deve occupare di porre il il valore del semaforo a 1

    3. Il PROLOGO si deve occupare di porre il flag X a true in modo da acquisire la SEZIONE CRITICA, mentre l'EPILOGO si deve occupare di porre il flag X a false

    4. Il PROLOGO si deve occupare di verificare la disponibilità della SEZIONE CRITICA, e in caso affermativo, acquisirla, mentre l'EPILOGO si deve occupare del rilascio della sezione critica (in modo che altri processi possano eseguirla)☑️

1. Nell'ambito del modello dei processi ad ambiente globale, che cosa stabilisce la regola di MUTUA ESCLUSIONE?

    1. La REGOLA di MUTUA ESCLUSIONE stabilisce che tutte le sezioni critiche debbano escludersi mutuamente nel tempo

    2. La REGOLA di MUTUA ESCLUSIONE stabilisce che i processi non possono essere in esecuzione nello stesso istante

    3. La REGOLA di MUTUA ESCLUSIONE stabilisce che sezioni critiche appartenenti alla stessa classe debbano escludersi mutuamente nel tempo☑️

    4. La REGOLA di MUTUA ESCLUSIONE stabilisce che una sola sezione critica può essere in esecuzione ad ogni istante

1. Nell'ambito del modello dei processi ad ambiente globale, per garantire la MUTUA ESCLUSIONE, perché la soluzione che associa una variabile enumerazione TURNO ad una classe di SEZIONI CRITICHE non è una soluzione accettabile?

    1. Perché viene violato il secondo requisito che è quello della indipendenza dei processi che eseguono le sezioni critiche di una stessa classe☑️

    2. Perché vengono violati tutti i requisiti che deve avere una soluzione per essere considerata accettabile per risolvere il problema della MUTUA ESCLUSIONE

    3. Perché non si può chiamare TURNO, ma si deve chiamare LOCK

    4. Perché viene violato il quarto requisito che è quello della ATTESA ATTIVA

1. Nell'ambito del modello dei processi ad ambiente globale, per garantire la MUTUA ESCLUSIONE, perché la soluzione che associa una variabile booleana LIBERO ad una classe di SEZIONI CRITICHE non è una soluzione accettabile?

    1. Perché viene violato il primo requisito che è quello della MUTUA ESCLUSIONE per i processi che eseguono le sezioni critiche di una stessa classe☑️

    2. Perché vengono violati tutti i requisiti che deve avere una soluzione per essere considerata accettabile per risolvere il problema della MUTUA ESCLUSIONE

    3. Perché viene violato il quarto requisito che è quello della ATTESA ATTIVA

    4. Perché non si può chiamare LIBERO, ma si deve chiamare LOCK

1. Nell'ambito del modello dei processi ad ambiente globale, per garantire la MUTUA ESCLUSIONE fra due processi, perché la soluzione che associa due variabili booleane PRONTO1 e PRONTO2 ad una classe di SEZIONI CRITICHE non è una soluzione accettabile?

    1. Perché non si possono usare due variabili booleane, ma solo una di nome LOCK

    2. Perché vengono violati tutti i requisiti che deve avere una soluzione per essere considerata accettabile per risolvere il problema della MUTUA ESCLUSIONE

    3. Perché viene violato il quarto requisito che è quello della ATTESA ATTIVA

    4. Perché viene violato il terzo requisito che è quello della assenza di condizioni di stallo per i processi che eseguono le sezioni critiche di una stessa classe☑️

1. Nell'ambito del modello dei processi ad ambiente globale, cosa si intende per SEZIONE CRITICA?

    1. Una SEZIONE CRITICA è la definizione di un insieme di variabili comuni

    2. Una SEZIONE CRITICA è la sequenza di operazioni** **con le quali un processo accede e modifica un insieme di variabili comuni☑️

    3. Non si può mai parlare di SEZIONE CRITICA, ma si deve sempre parlare di CLASSE DI SEZIONI CRITICHE

    4. Una SEZIONE CRITICA è la sequenza di operazioni** **con le quali un processo garantisce la MUTUA ESCLUSIONE

1. Nell'ambito del modello dei processi ad ambiente globale, cosa si intende per CLASSE DI SEZIONI CRITICHE?

    1. Una CLASSE DI SEZIONI CRITICHE è un insieme di SEZIONI CRITICHE che operano sulle stesse variabili comuni a più processi☑️

    2. Una CLASSE DI SEZIONI CRITICHE è un insieme di variabili comuni a più processi

    3. Una CLASSE DI SEZIONI CRITICHE è una classe Java di oggetti in comune con diversi processi

    4. Una CLASSE DI SEZIONI CRITICHE è la sequenza di operazioni con le quali un processo garantisce la MUTUA ESCLUSIONE

1. In un Sistema Operativo basato sul modello dei processi ad Ambiente Globale, quale meccanismo di sincronizzazione si deve usare per regolare le interazioni fra processi?

    1. il meccanismo di semaforo (con wait e signal)☑️
    2. il meccanismo di monitor
    3. il meccanismo dello scambio di messaggi/segnali
    4. il meccanismo di lock/unlock

1. Sapendo che S0=valore iniziale semaforo, che ns(S)=numero di volte che è stata eseguita la signal con nessun processo in coda , e che nw(S)=numero di volte che è stata eseguita la wait con successo, allora l'invariante dei semafori è:

    1. nw(S) ≥ ns(S) + S0
    2. nw(S) ≤ ns(S) - S0☑️
    3. nw(S) ≥ ns(S) - S0
    4. nw(S) ≤ ns(S) + S0

1. Nell'ambito del modello dei processi ad ambiente globale, per garantire la MUTUA ESCLUSIONE fra due processi, perché la soluzione di Peterson non è una soluzione accettabile?

    1. Perché vengono violati tutti i requisiti che deve avere una soluzione per essere considerata accettabile per risolvere il problema della MUTUA ESCLUSIONE

    2. Perché vale solo per due processi

    3. Perché viene violato il quarto requisito che è quello della ATTESA ATTIVA☑️

    4. Perché è troppo complicata
