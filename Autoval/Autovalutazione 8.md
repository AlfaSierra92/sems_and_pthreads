2022-11-16

1. Facendo riferimento al punto di vista esterno relativo alla gestione della memoria, cosa vuole dire codice binario assoluto?  
    a. Significa che il binding tra indirizzo logico e indirizzo fisico sarà fatto a tempo di caricamento  
    b. Significa che il binding tra indirizzo logico e indirizzo fisico sarà fatto a tempo di esecuzione  
    c. Significa che il binding tra indirizzo logico e indirizzo fisico è stato fatto a tempo di compilazione☑️  
    d. Significa che il binding tra indirizzo logico e indirizzo fisico sarà calcolato tramite l'uso di un registro base  

2. Facendo riferimento al punto di vista esterno relativo alla gestione della memoria, la rilocazione statica prevede che:  
    a. il binding tra indirizzo logico e indirizzo fisico sia fatto a tempo di compilazione  
    b. il binding tra indirizzo logico e indirizzo fisico sia fatto a tempo di esecuzione  
    c. il binding tra indirizzo logico e indirizzo fisico venga calcolato tramite l'uso di un registro base  
    d. il binding tra indirizzo logico e indirizzo fisico sia fatto a tempo di caricamento☑️  

3. In un Sistema Operativo generale, facendo riferimento alla tecnica della segmentazione, la TDS viene ottenuta:  
    a. applicando il procedimento di allocazione non contiguo della memoria  
    b. applicando il procedimento di allocazione del partizionamento statico ad ogni segmento  
    c. applicando il procedimento di allocazione del partizionamento dinamico che considera la dimensione totale del processo  
    d. applicando il procedimento di allocazione del partizionamento dinamico ad ogni segmento☑️  

4. In un Sistema Operativo che usi come gestore della memoria la strategia a Monitor Monoprocesso, la parte di Monitor viene allocata nella parte alta o bassa della memoria, a seconda:  
    a. della codifica utilizzata dal processore, big endian o little endian  
    b. della posizione del loader e dell'interprete dei comandi  
    c. nessuna delle alternative presenti  
    d. della posizione del vettore di interruzione dell'HW☑️  

5. Facendo riferimento alla tecnica dello swapping, nel caso di partizionamento statico della memoria, è possibile affermare che:  
    a. tutti i processi possono essere soggetti a swap  
    b. la creazione di un file di swap per ogni processo comporta una minore occupazione di memoria sul disco  
    c. il file di swapping di sistema viene creato a run-time in caso di necessità  
    d. l'associazione tra un generico processo swapped-out e la sua partizione corrispondente può essere statica o dinamica☑️  

6. Facendo riferimento al punto di vista esterno relativo alla gestione della memoria, cosa vuole dire codice binario rilocabile?  
    a. Significa che il binding tra indirizzo logico e indirizzo fisico sarà fatto solo a tempo di caricamento  
    b. Significa che il binding tra indirizzo logico e indirizzo fisico è stato fatto a tempo di compilazione  
    c. Significa che il binding tra indirizzo logico e indirizzo fisico sarà fatto solo a tempo di esecuzione  
    d. Significa che il binding tra indirizzo logico e indirizzo fisico sarà fatto a tempo di caricamento o a tempo di esecuzione☑️  

7. In un Sistema Operativo generale nel quale si utilizza un partizionamento dinamico della memoria, quali metodi di selezione dell'area libera cercano di ridurre la frammentazione esterna?  
    a. first-fit e best-fit  
    b. best-fit e worst-fit☑️  
    c. next-fit e worst-fit  
    d. first-fit e next-fit  

8. In un Sistema Operativo generale, effettuare lo swap di un processo sospeso in attesa di dati di I/O, può dar vita a problematiche inerenti il salvataggio dei dati attesi, in quanto il processo, dopo lo swap, non si trova più in memoria centrale. Come si può risolvere questa problematica?  
    a. nessuna delle alternative presenti  
    b. salvando i dati attesi in aree di I/O del sistema operativo☑️  
    c. salvando i dati attesi nel descrittore del processo  
    d. salvando i dati attesi nel file di swap del processo  

9. In un Sistema Operativo generale, il gestore della memoria si occupa di:  
    a. allocare la memoria fisica per i processi, proteggere lo spazio di indirizzamento di ogni processo e consentire la condivisione di aree di memoria fra processi interagenti☑️  
    b. allocare la memoria fisica per i processi e consentire la condivisione di aree di memoria fra processi interagenti, ma non proteggere lo spazio di indirizzamento di ogni processo  
    c. allocare la memoria fisica per i processi e proteggere lo spazio di indirizzamento di ogni processo, ma non consentire la condivisione di aree di memoria fra processi interagenti  
    d. allocare la memoria fisica per i processi, proteggere lo spazio di indirizzamento di ogni processo, ed effettuare il binding tra indirizzi logici e indirizzi fisici  

10. In un Sistema Operativo generale, facendo riferimento alla tecnica della segmentazione, è possibile affermare che:  
    a. solamente i valori del registro base e del registro limite della tabella dei descrittori di segmento vengono mantenuti sui registri macchina, in quanto sono sufficienti per la traduzione degli indirizzi da logici a fisici  
    b. oltre ai valori del registro base e del registro limite della tabella dei descrittori di segmento, si mantengono su particolari registri macchina le informazioni relative ai segmenti utilizzati correntemente, in modo da limitare gli accessi in memoria necessari per il reperimento dei dati☑️  
    c. solamente i valori del registro base e del registro limite della tabella dei descrittori di segmento vengono mantenuti sui registri macchina, in quanto non è possibile salvare l'intera tabella dei descrittori di segmento sui registri macchina  
    d. l'intera tabella dei descrittori di segmento viene salvata sui registri macchina  

11. Facendo riferimento al Sistema Operativo MS-DOS, qual è la caratteristica dei file eseguibili .COM?  
    a. Contengono programmi che possono essere eseguiti solo da linea di comando  
    b. Sono file che contengono codice binario assoluto che quindi deve essere allocato in posizioni prefissate di memoria centrale☑️  
    c. Sono file che contengono programmi che devono essere rilocati staticamente dal loader  
    d. Sono file che contengono codice binario rilocabile che deve essere allocato in posizioni prefissate di memoria centrale  

12. In un Sistema Operativo generale nel quale si utilizza un partizionamento dinamico della memoria, nel caso in cui si voglia creare una partizione di memoria per un nuovo processo P ma non esista nessuna area libera in grado di ospitare tale processo, la scelta di ritardare l'esecuzione del processo P:  
    a. nessuna delle alternative presenti  
    b. può influire sulle decisioni dello scheduler di breve termine  
    c. può influire sulle decisioni dello scheduler di medio termine  
    d. può influire sulle decisioni dello scheduler di lungo termine☑️  

13. In un Sistema Operativo generale nel quale si utilizza un partizionamento statico della memoria, è possibile affermare che:  
    a. il livello di frammentazione interna è inversamente proporzionale all'esistenza di processi con esigua richiesta di memoria la cui esecuzione avviene poco frequentemente  
    b. il livello di frammentazione interna è direttamente proporzionale all'esistenza di processi con grande richiesta di memoria la cui esecuzione avviene poco frequentemente☑️  
    c. il livello di frammentazione esterna è inversamente proporzionale all'esistenza di processi con grande richiesta di memoria la cui esecuzione avviene molto frequentemente  
    d. il livello di frammentazione interna è direttamente proporzionale all'esistenza di processi con grande richiesta di memoria la cui esecuzione avviene molto frequentemente  

14. Facendo riferimento al punto di vista esterno relativo alla gestione della memoria, la rilocazione dinamica prevede che:  
    a. il binding tra indirizzo logico e indirizzo fisico sia fatto a tempo di esecuzione☑️  
    b. il binding tra indirizzo logico e indirizzo fisico venga calcolato tramite l'uso di un registro base  
    c. il binding tra indirizzo logico e indirizzo fisico sia fatto a tempo di compilazione  
    d. il binding tra indirizzo logico e indirizzo fisico sia fatto a tempo di caricamento  

15. In un Sistema Operativo generale nel quale si utilizza un partizionamento dinamico della memoria, la lista delle aree di memoria libera viene mantenuta:  
    a. nella tabella di descrizione delle partizioni  
    b. nella parte residente del Sistema Operativo  
    c. in appositi registri del Sistema Operativo  
    d. il puntatore iniziale alla lista nella parte residente del Sistema Operativo, e il resto nei primi/ultimi byte di ogni area di memoria libera☑️  

16. In un Sistema Operativo che usi come gestore della memoria la strategia a Monitor Monoprocesso, facendo riferimento alle possibili soluzioni adottate per la protezione del Monitor da accessi indesiderati, è possibile affermare che:  
    a. il Monitor in memoria a sola lettura è la soluzione più usata  
    b. l'utilizzo di un registro barriera richiede l'esistenza di due modalità di funzionamento, modo utente e modo supervisore  
    c. entrambe le soluzioni di "registro barriera" e "bit di protezione" richiedono l'esistenza di due modalità di funzionamento, modo utente e modo supervisore☑️  
    d. l'utilizzo di un bit di protezione richiede l'esistenza di due modalità di funzionamento, modo utente e modo supervisore  

17. Facendo riferimento alla tecnica della segmentazione, la tabella dei descrittori di segmento viene definita come:  
    a. una struttura dati in cui ogni elemento è una terna ordinata di valori, formata dall'indirizzo fisico iniziale della memoria in cui risiede il segmento, dall'indirizzo base e dalla dimensione del segmento  
    b. una struttura dati in cui ogni elemento è una terna ordinata di valori, formata dall'indirizzo fisico iniziale della memoria in cui risiede il segmento, dalla dimensione del segmento e dallo spiazzamento  
    c. una struttura dati in cui ogni elemento è una coppia ordinata di valori, formata dall'indirizzo base del segmento e dalla dimensione del segmento☑️  
    d. una struttura dati in cui ogni elemento è una coppia ordinata di valori, formata dal numero del segmento e dallo spiazzamento  