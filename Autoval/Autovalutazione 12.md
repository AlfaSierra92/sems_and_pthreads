Autovalutazione 12  
2022-12-19 14:56

1. Nell’ambito della gestione dei file, quale metodo viene utilizzato per la gestione dei blocchi/cluster liberi dei dischi?  
    a. L’unico metodo è la lista dei blocchi/cluster liberi  
    b. L’unico metodo che è utilizzato è la BIT MAP  
    c. Può essere utilizzata sia la BIT MAP che la lista dei blocchi/cluster liberi e in questo ultimo caso può essere utilizzato anche il Grouping e il Counting per migliorarne l’efficienza☑️  
    d. Può essere utilizzata sia la BIT MAP che la lista dei blocchi/cluster liberi  

2. Nel Sistema Operativo Unix, perchè sono state introdotte due ulteriori Tabelle di Sistema, Tabella dei File Aperti di sistema e la Tabella degli I-Node Attivi di sistema?  
    a. Le due Tabelle servono perchè altrimenti non potrebbero essere memorizzati il file pointer, la modalità di apertura e la copia dell'I-Node  
    b. La Tabella dei File Aperti di sistema serve per consentire la condivisione del file pointer fra processi in parentela, mentre la Tabella degli I-Node Attivi di sistema serve per non avere copie multiple dello stesso I-NODE e necessità  di aggiornare copie multiple☑️  
    c. Le due Tabelle servono per consentire la condivisione dei file da parte di processi diversi, secondo il modello dei processi ad ambiente globale  
    d. Le due Tabelle servono per garantire le regole del modello dei processi ad ambiente locale, cui Unix si ispira  

3. Che cosa è nell’ambito della gestione dei file la BIT MAP?  
    a. La bit map è un array di bit che per ogni blocco/cluster di un disco mantiene l’informazione se tale blocco/cluster è libero oppure allocato☑️  
    b. La bit map è una matrice di bit che per ogni blocco/cluster di ogni disco mantiene l’informazione se tale blocco/cluster è libero oppure allocato  
    c. La bit map è un array di bit che per ogni blocco/cluster di un disco mantiene l’informazione se tale blocco/cluster è libero, mentre l’informazione se un blocco/cluster è allocato è presente all’interno dei descrittori di file  
    d. La bit map è un array di bit che per ogni blocco/cluster di un disco mantiene l’informazione se tale blocco/cluster è allocato, mentre l’informazione se un blocco/cluster è libero è presente all’interno della lista dei blocchi/cluster liberi  

4. Facendo riferimento ai metodi di allocazione della memoria secondaria, quale dei seguenti problemi non è proprio solamente dell'allocazione contigua?  
    a. la difficoltà di aggirare blocchi fisici danneggiati  
    b. la frammentazione interna☑️  
    c. la difficoltà di prevedere la dimensione di ogni file all'atto della creazione  
    d. la frammentazione esterna  

5. Nel Sistema Operativo Unix, che cosa è la Tabella dei File Aperti di sistema?  
    a. è una tabella globale contenente, per ogni file aperto, l'I/O pointer e il puntatore alla copia dell'i-node del file mantenuto nella Tabella dei File Attivi☑️  
    b. è una tabella globale contenente, per ogni file aperto, la modalità  di apertura, l'I/O pointer e il puntatore alla copia dell'i-node del file mantenuto nella Tabella dei File Attivi  
    c. è una tabella globale contenente, per ogni file aperto, la copia dell'i-node del file  
    d. è una tabella globale contenente, per ogni file aperto, la modalità  di apertura e il puntatore alla copia dell'i-node del file mantenuto nella Tabella dei File Attivi  

6. In un generico Sistema Operativo, a cosa serve il blocco di controllo di avviamento (Boot Control Block) di un volume?  
    a. Serve per contenere le informazioni di quel volume come numero totale di blocchi e loro dimensione blocchi libero, etc.  
    b. Serve per contenere le informazioni relative al File System presente su quel volume  
    c. Serve per contenere i blocchi di controllo di quel volume  
    d. Serve per contenere le informazioni per l'avviamento del Sistema Operativo da quel volume☑️  

7. In un generico Sistema Operativo, a cosa serve il Direttorio Base dei File (DBF) nell'implementazione del File System?  
    a. Per realizzare facilmente il meccanismo di link Hardware☑️  
    b. Per mantenere la corrispondenza fra ogni nome logico di file e un identificatore unico  
    c. Per consentire l'accesso alla directory ROOT  
    d. Per tenere separati i file dei diversi utenti  

8. Nel Sistema Operativo Unix, quale schema di allocazione dei file si adotta?  
    a. Uno schema di allocazione non contigua indicizzato e ottimizzato: si mantiene nella riga del DBF (cioè nell'I-NODE) un certo numero di puntatori a blocchi indice di primo, secondo, terzo livello  
    b. Uno schema di allocazione contigua ottimizzato: si mantiene nella riga del DBF (cioè nell'I-NODE) i puntatori ai blocchi del file  
    c. Uno schema di allocazione non contigua concatenato e ottimizzato: si mantiene nella riga del DBF (cioè nell'I-NODE) un certo numero di puntatori ai primi blocchi del file (sufficienti per file corti) e un puntatore agli ulteriori blocchi (necessario per file lunghi)  
    d. Uno schema di allocazione non contigua indicizzato e ottimizzato: si mantiene nella riga del DBF (cioè nell'I-NODE) un certo numero di puntatori ai primi blocchi del file (sufficienti per file corti) e un certo numero di puntatori a blocchi indice di primo, secondo, terzo livello (necessari per file lunghi)☑️  

9. Facendo riferimento ai metodi di allocazione della memoria secondaria, è possibile affermare che:  
    a. utilizzando metodi di allocazione contigua sia l’accesso sequenziale che quello diretto presentano prestazioni simili, mentre, utilizzando metodi di allocazione non contigua di tipo concatenato, l’accesso diretto risulta avere prestazioni peggiori di quello sequenziale☑️  
    b. utilizzando metodi di allocazione non contigua di tipo concatenato, l’accesso diretto risulta più efficace di quello sequenziale, in quanto, per accedere al blocco i-esimo, è necessario accedere a tutti i blocchi precedenti  
    c. utilizzando metodi di allocazione contigua l’accesso sequenziale risulta più efficiente di quello diretto, in quanto, per accedere al blocco i-esimo, è necessario accedere a tutti i blocchi precedenti  
    d. utilizzando metodi di allocazione non contigua di tipo concatenato, sia l’accesso sequenziale che quello diretto presentano prestazioni simili, mentre, utilizzando metodi di allocazione contigua, l’accesso diretto risulta avere prestazioni peggiori di quello sequenziale  

10. Facendo riferimento ai metodi di allocazione contigua della memoria secondaria, come è possibile risolvere il problema legato alla necessità  di conoscere a priori la dimensione di ogni file al momento della creazione, e quindi ad una possibile sottostima della dimensione?  
    a. tramite l'utilizzo temporaneo di uno o più cluster di allocazione non contigui☑️  
    b. tramite un'attenta analisi del codice del processo creatore  
    c. nessuna delle alternative presenti  
    d. tramite l'utilizzo di apposite aree del Sistema Operativo in cui memorizzare momentaneamente i file  

11. Nei Sistemi Operativi MS-DOS e Windows, che cosa è la FAT?  
    a. La FAT (File Allocation Table) è una tabella che contiene i riferimenti ai cluster liberi; essa è memorizzata in una posizione fissa del disco e presente in duplice copia  
    b. La FAT (File Allocation Table) è una tabella che contiene i riferimenti ai cluster occupati; essa è memorizzata in una posizione fissa del disco e presente in duplice copia  
    c. La FAT (File Allocation Table) è una tabella che contiene i riferimenti ai cluster liberi ed occupati; essa è memorizzata in una posizione fissa del disco e presente in duplice copia☑️  
    d. La FAT (Formatting Access Table) è una tabella che contiene i riferimenti ai cluster liberi ed occupati; essa è memorizzata in una posizione fissa del disco e presente in duplice copia  

12. In un Sistema Operativo generale, a cosa serve l'operazione di montaggio?  
    a. Il montaggio serve solo per poter utilizzare i file system speciali come /proc di Linux  
    b. Il montaggio serve per poter utilizzare in un file system logico diverse partizioni, ognuna con il proprio file system fisico☑️  
    c. Il montaggio serve in un sistema composto da più CPU per poter usare l'SMP (Symmetric Multiprocessing)  
    d. Il montaggio serve per poter gestire i blocchi liberi di una partizion  

13. In un generico Sistema Operativo, la frammentazione interna che si può presentare nella gestione della memoria secondaria:  
    a. può dipendere dal metodo di allocazione  
    b. è presente solo se si usano cluster di allocazione  
    c. non dipende dal metodo di allocazione☑️  
    d. dipende dal metodo di allocazione  

14. In un Sistema Operativo generale, facendo riferimento alla gestione dei file, è possibile affermare che:  
    a. il Direttorio dei Nomi dei File è una struttura dati associata ad ogni directory definita dall'utente☑️  
    b. il Direttorio Base dei File mantiene solamente l'indirizzo base della locazione fisica del file sul dispositivo di memorizzazione  
    c. il Direttorio dei Nomi dei File mantiene solamente l'associazione tra il nome logico del file ed il contatore dei link hardware  
    d. il Direttorio Base dei File è sempre una struttura dati unica per il File System logico  

15. Nel File System VxFS, quale metodo di allocazione si usa per i file?  
    a. Si usa l’allocazione contigua basata sull’allocazione di extent (più blocchi adiacenti)☑️  
    b. Si usa l’allocazione concatenata  
    c. Si usa l’allocazione concatenata ottimizzata mediante l’uso della FAT (File Allocation Table)  
    d. Si usa l’allocazione ad indicizzazione con una ottimizzazione simile a quella di UNIX  

16. Quali metodi di allocazione della memoria secondaria non presentano il problema della frammentazione esterna?  
    a. I metodi di allocazione non contigua concatenata e non contigua ad indicizzazione☑️  
    b. I metodi di allocazione contigua e di allocazione non contigua ad indicizzazione  
    c. I metodi di allocazione contigua e di allocazione non contigua concatenata  
    d. Nessuno dato che tutti i metodi di allocazione presentano questo problema  

17. Nel Sistema Operativo Unix, quali tabelle vengono usate per l'accesso ai file?  
    a. Oltre alla Tabella dei File Aperti di ogni singolo processo, ci sono due tabelle di kernel: la Tabella dei File Aperti di sistema (dove fra l'altro per ogni elemento c'è il file pointer) e la Tabella degli I-Node Attivi di sistema (dove fra l'altro per ogni elemento ci sono la copia dell'I-Node e la modalità  di apertura)  
    b. Oltre alla Tabella dei File Aperti di ogni singolo processo, ci sono due tabelle di kernel: la Tabella dei File Aperti di sistema (dove fra l'altro per ogni elemento ci sono le modalità  di apertura) e la Tabella degli I-Node Attivi di sistema (dove fra l'altro per ogni elemento ci sono la copia dell'I-Node e il file pointer)  
    c. Oltre alla Tabella dei File Aperti di ogni singolo processo, ci sono due tabelle di kernel: la Tabella dei File Aperti di sistema (dove fra l'altro per ogni elemento ci sono le modalità  di apertura e il file pointer) e la Tabella degli I-Node Attivi di sistema (dove fra l'altro per ogni elemento c'è la copia dell'I-Node)☑️  
    d. Oltre alla Tabella dei File Aperti di ogni singolo processo, c'è una tabella di kernel: la Tabella dei File Attivi di sistema (dove fra l'altro per ogni elemento ci sono le modalità  di apertura, il file pointer e la copia dell'I-Node)  

18. Su quale dei seguenti metodi è basato il sistema di allocazione della memoria secondaria del Sistema Operativo MS-DOS?  
    a. ad allocazione non contigua di tipo concatenato☑️  
    b. ad allocazione contigua  
    c. nessuna delle alternative presenti  
    d. ad allocazione non contigua di tipo indicizzato  