2022-10-20

1. In un Sistema Operativo ad ambiente globale, la transizione di stato di un processo che corrisponde alla sua riattivazione (quindi la transizione da stato sospeso a stato esecuzione) da cosa può essere causata? 
    a. un interrupt, generato dal completamento di un'operazione di I/O, oppure da una wait sospensiva su un semaforo  
    b. un interrupt, generato dalla richiesta di un'operazione di I/O, oppure da una wait sospensiva su un semaforo  
    c. un interrupt, generato dalla richiesta di un'operazione di I/O, oppure da una signal su un semaforo  
    d. un interrupt, generato dal completamento di un'operazione di I/O, oppure da una signal su un semaforo☑️  

2. Si consideri la macchina virtuale derivante da un primo livello di Sistema Operativo (nucleo) che supporta esclusivamente un sistema a processi e un meccanismo di fork tipo Unix: tale macchina virtuale a cosa è logicamente assimilabile?  
    a. A un sistema con più processori e una memoria privata per ciascun processore☑️  
    b. A un sistema con più processori e una memoria condivisa  
    c. A un sistema con più processori, una memoria privata per ciascun processore, e uno spazio di memoria condivisa utilizzato per la comunicazione tra processi  
    d. A un sistema con un unico processore e uno spazio di memoria privata per ciascun processo  

3. In un Sistema Operativo ad ambiente locale, nel caso di scambio di messaggi, quale delle seguenti configurazioni, in assenza di errori, non garantisce l'ordinamento dei messaggi?  
    a. primitiva send asincrona, implementata su un'architettura distribuita con sistema di routing dinamico☑️  
    b. primitiva send asincrona, implementata su un'architettura distribuita con sistema di routing statico  
    c. primitiva send sincrona, implementata su un'architettura distribuita con sistema di routing dinamico  
    d. primitiva send sincrona, implementata su un'architettura distribuita con sistema di routing statico  

4. In un Sistema Operativo ad ambiente locale, in presenza di due processi comunicanti, la ritrasmissione di messaggi "corrotti" può essere demandata al processo mittente, in caso di:  
    a. comunicazioni sincrone con time-out o comunicazioni asincrone con identificazione diretta  
    b. comunicazioni sincrone con time-out o comunicazioni asincrone con messaggio di ACK da parte del ricevente☑️  
    c. comunicazioni sincrone senza time-out o comunicazioni asincrone con identificazione diretta  
    d. comunicazioni sincrone senza time-out o comunicazioni asincrone con messaggio di ACK da parte del ricevente  

5. All'interno del nucleo di un Sistema Operativo multiprocesso, potrebbe essere possibile non usare lo stato 'pronto'/'ready'?  
    a. No  
    b. Sì  
    c. Sì, ma solo in presenza di un sistema di interruzioni adeguato  
    d. Sì, ma solo in presenza di un numero di processori uguale al numero di processi attivi☑️  

6. In un Sistema Operativo Unix, il descrittore di un processo:  
    a. esiste per l'intera durata del processo, ed è un elemento della Text Table  
    b. esiste fintanto che il processo non subisce uno swap, ed è un elemento della Text Table  
    c. esiste per l'intera durata del processo, ed è un elemento della Process Table☑️  
    d. esiste fintanto che il processo non subisce uno swap, ed è un elemento della Process Table  

7. Quanti sono i possibili stati interni di un processo Unix?  
    a. 5  
    b. 7☑️  
    c. 8  
    d. 6  

8. In un Sistema Operativo ad ambiente globale durante una comunicazione tra due processi, la terminazione inaspettata di un processo viene segnalata al processo partner:  
    a. solo utilizzando canali con capacità di bufferizzazione  
    b. solo con l'intervento del sistema operativo☑️  
    c. solo se sono usate comunicazioni sincrone con time-out  
    d. solo se sono usate comunicazioni asincrone  

9. In un Sistema Operativo Unix, dove vengono memorizzate la Tabella del File Aperti e la Tabella dei segnali di uno specifico processo?  
    a. Nel kernel di UNIX  
    b. Nella kernel area dello specifico processo☑️  
    c. Nella Process Table  
    d. Nella area dati dello specifico processo  

10. In un Sistema Operativo Unix, all'atto dell'invocazione della primitiva exec:  
    a. viene modificato il puntatore del descrittore di processo alla Text Table, in modo che venga riferita la nuova area di codice, e viene puntata una nuova area dati☑️  
    b. viene modificato il puntatore del descrittore di processo alla Text Table, in modo che venga riferita la nuova area di codice, e viene puntata una nuova area kernel  
    c. viene inserito un nuovo elemento nella Process Table, poiché tramite la primitiva exec viene creato un nuovo processo  
    d. viene modificato il puntatore del descrittore di processo alla Text Table, in modo che venga riferita la nuova area di codice, viene puntata una nuova area dati e viene puntata una nuova area kernel  

11. Facendo riferimento alle informazioni contenute nel descrittore di un processo, in un Sistema Operativo Unix all'atto dell'invocazione della primitiva exec:  
    a. vengono modificati i parametri UID e/o GID effettivi, solo se la exec viene invocata subito dopo una fork   
    b. vengono modificati i parametri UID e/o GID effettivi, in caso il programma da eseguire presenti sUID e/o sGID settati☑️  
    c. vengono modificati i parametri UID e/o GID effettivi, solo se la exec viene invocata dal superutente  
    d. vengono modificati i parametri UID e/o GID reali, in caso il programma da eseguire presenti sUID e/o sGID settati  

12. All'interno del nucleo di un Sistema Operativo multiprocesso con una sola CPU quale di queste affermazioni è vera?  
    a. Un solo processo (al massimo) si trova nello stato "esecuzione"/"running" e gli altri processi si trovano nello stato "pronto"/"ready"  
    b. Un solo processo (al massimo) si trova nello stato "esecuzione"/"running" e gli altri processi si trovano negli stati "pronto"/"ready" o "sospeso"/"blocked"☑️  
    c. Nessuna delle alternative presenti  
    d. Un solo processo (al massimo) si trova nello stato "esecuzione"/"running" e gli altri processi si trovano nello stato "sospeso"/"blocked"  

13. In un Sistema Operativo multiprocesso, il process switching è:  
    a. un insieme di operazioni del Sistema Operativo eseguite in modo utente  
    b. un insieme di operazioni del Sistema Operativo necessarie solamente per gli algoritmi di scheduling di tipo preemptive  
    c. un insieme di operazioni del Sistema Operativo eseguite in modo supervisore☑️  
    d. un insieme di operazioni del Sistema Operativo eseguite solamente per i thread  

14. In un Sistema Operativo che usa un modello dei processi ad ambiente locale implementato su una architettura distribuita, quando si può verificare il problema dell'ordinamento dei messaggi fra un processo mittente S e un processo destinatario R che risiedono su nodi diversi?  
    a. Mai  
    b. Solo se S usa per la spedizione dei messaggi una primitiva di send asincrona e se l'algoritmo di routing (instradamento) dei messaggi è dinamico☑️  
    c. Solo se l'algoritmo di routing (instradamento) dei messaggi è dinamico  
    d. Sempre  

15. Quale soluzione adotta il Sistema Operativo Unix per affrontare il problema di 'morte' del processo sender, partner di una comunicazione tramite pipe?  
    a. Unix non adotta nessuna soluzione e quindi il receiver non verrà avvisato che non arriveranno più informazioni  
    b. Unix adotta come soluzione di sbloccare il processo receiver, bloccato sulla primitiva di ricezione, in modo che controllando il valore di ritorno di tale primitiva possa rendersi conto che il partner è 'morto'☑️  
    c. Unix adotta come soluzione di inviare un segnale al processo receiver in modo da avvisarlo della 'morte' del processo sender  
    d. Unix adotta come soluzione quella di 'uccidere' il processo receiver dato che non può più ricevere informazioni  

16. Volendo realizzare un semaforo di mutua esclusione in ambiente locale, utilizzando un canale con identificazione diretta asimmetrica senza bufferizzazione:  
    a. il codice del processo semaforo PS dovrà contenere due primitive send, mentre il codice del generico processo Pi, che vuole eseguire la sezione critica, dovrà contenere due primitive receive  
    b. il codice di entrambi i processi, del processo semaforo PS e del generico processo Pi che vuole eseguire la sezione critica, dovrà contenere, in quest'ordine, una primitiva receive e una primitiva send  
    c. il codice di entrambi i processi, del processo semaforo PS e del generico processo Pi che vuole eseguire la sezione critica, dovrà contenere, in quest'ordine, una primitiva send e una primitiva receive  
    d. il codice del processo semaforo PS dovrà contenere due primitive receive, mentre il codice del generico processo Pi, che vuole eseguire la sezione critica, dovrà contenere due primitive send☑️  

17. Facendo riferimento al nucleo di un Sistema Operativo, il descrittore di un processo:  
    a. mantiene tutte le informazioni relative allo stato del processo, al program counter, ai registri della CPU utilizzati; contiene inoltre informazioni di scheduling e di accounting, informazioni relative allo stato di I/O e per la gestione della memoria☑️  
    b. mantiene tutte le informazioni relative allo stato del processo, al program counter, ai registri della CPU utilizzati; non contiene informazioni di scheduling e di accounting, informazioni relative allo stato di I/O e per la gestione della memoria  
    c. mantiene tutte le informazioni relative allo stato del processo, al program counter, ai registri della CPU utilizzati, oltre che informazioni relative allo stato di I/O e per la gestione della memoria; non contiene informazioni di scheduling e di accounting  
    d. mantiene tutte le informazioni relative allo stato del processo, al program counter, ai registri della CPU utilizzati, oltre che informazioni di scheduling e di accounting; non contiene informazioni relative allo stato di I/O e per la gestione della memoria  

18. Quali sono i possibili stati interni di un processo Unix?  
    a. idle/sleeping/running/ready/swapped  
    b. idle/terminated/sleeping/swapped/ready/zombie/running☑️  
    c. idle/running/sleeping/ready/zombie/terminated  
    d. idle/swapped/sleeping/running/locked/zombie/terminated/ready  

19. Quale soluzione adotta il Sistema Operativo Unix per affrontare il problema di 'morte' del processo receiver, partner di una comunicazione tramite pipe?  
    a. Unix adotta come soluzione di sbloccare il processo sender, bloccato sulla primitiva di spedizione, in modo che controllando il valore di ritorno di tale primitiva possa rendersi conto che il partner è 'morto'  
    b. Unix non adotta nessuna soluzione e quindi il sender non verrà avvisato che le informazioni che invia non saranno ricevute da nessuno  
    c. Unix adotta come soluzione di inviare un segnale al processo sender in modo da avvisarlo della 'morte' del processo receiver☑️  
    d. Unix adotta come soluzione quella di 'uccidere' il processo sender dato che le sue informazioni non servono più a nessuno  

20. Facendo riferimento al nucleo di un Sistema Operativo, che cos'è il PCB?  
    a. PCB è un acronimo che significa Process Control Batch, ed è un algoritmo di scheduling di lungo termine  
    b. PCB è un acronimo che significa Program Counter Block, ed è il blocco contenente l'indirizzo della prossima istruzione da eseguire  
    c. PCB è un acronimo che significa Process Control Block, ed è una struttura dati con vari campi associata ad ogni processo☑️  
    d. PCB è un acronimo che significa Process Chain Block, ed è la coda dei processi a più alta priorità  

21. Facendo riferimento al nucleo di un Sistema Operativo, un nuovo processo, all'atto della creazione:  
    a. viene associato ad un descrittore "vuoto" ed inserito nella coda a più bassa priorità  
    b. viene associato ad un descrittore libero  
    c. viene associato ad un descrittore libero o ad un descrittore creato a run-time☑️  
    d. viene associato ad un descrittore creato a run-time  

22. Facendo riferimento alla descrizione dei processi in un Sistema Operativo Unix, quali delle seguenti aree possono essere soggette a swap?  
    a. area di codice ed area dati  
    b. area dati, kernel area ed area di codice☑️  
    c. area dati e kernel area  
    d. area di codice  

23. In un Sistema Operativo Unix, in seguito all'invocazione della primitiva fork per il nuovo processo cosa avviene?  
    a. vengono create, tramite copia dal processo padre, una nuova kernel area, una nuova area dati ed una nuova area di codice  
    b. vengono create, tramite copia dal processo padre, una nuova kernel area e una nuova area dati, mentre l'area di codice viene condivisa con il processo padre☑️  
    c. viene creata, tramite copia dal processo padre, una nuova area di codice, mentre la kernel area e l'area dati vengono condivise con il processo padre  
    d. vengono create ex novo una nuova kernel area e una nuova area dati, mentre l'area di codice viene condivisa con il processo padre  

24. In un Sistema Operativo generale, la transizione di un processo dallo stato di esecuzione ('running') a quello di pronto ('ready') quando si può verificare?  
    a. Si verifica solo quando il processo running lo richiede  
    b. Si verifica se è prevista la preemption (prelazione) oppure se è previsto che un processo chieda il descheduling☑️  
    c. Si verifica solo quando si risveglia un processo a priorità  maggiore  
    d. Si verifica solo allo scadere del quanto di tempo  

25. In un Sistema Operativo generale, indicando con P1 il generico processo attualmente in esecuzione e con P2 il generico processo da mandare in esecuzione, è possibile affermare che il process switching:  
    a. è un insieme di operazioni del Sistema Operativo che prevede il salvataggio del contesto del processo P1, l'inserimento del descrittore di P1 nella coda appropriata, il ripristino del contesto del processo P2, l'inserimento dell'identificatore di P2 nel registro running e l'eventuale estrazione del descrittore di P2 dalla coda dei processi pronti☑️  
    b. è una politica del Sistema Operativo che si occupa di salvare il contesto del processo in esecuzione, di effettuare il passaggio da modo supervisore a modo utente e di individuare la giusta istruzione del programma utente da mandare in esecuzione  
    c. è un meccanismo del Sistema Operativo che si occupa di effettuare il cambio di contesto, di effettuare il passaggio da modo supervisore a modo utente e di individuare la giusta istruzione del programma utente da mandare in esecuzione  
    d. è un insieme di operazioni del Sistema Operativo che prevede il salvataggio del contesto del processo P1, il passaggio da modo utente a modo supervisore, ed il ripristino del contesto del processo P2  