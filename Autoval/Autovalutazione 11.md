2022-12-07

1. In un Sistema Operativo generale, qual è la minima parte indirizzabile di un disco fisso?  
    a. byte  
    b. 1 bit  
    c. dipende dal tipo di disco  
    d. blocco☑️  

2. Come differisce la gestione delle wildcard * e ? fra i Sistemi Operativi UNIX e MS-DOS?  
    a. UNIX gestisce le wildcard mediante la shell, mentre MS-DOS ha solo alcuni comandi che le gestiscono☑️  
    b. Nessuna differenza  
    c. Nessuna differenza per il ?, ma in UNIX l'* fa match con qualunque stringa anche nulla, mentre in MS-DOS con qualunque stringa NON nulla  
    d. Nessuna differenza per l'*, ma in UNIX il ? fa match con qualunque carattere NON nullo, mentre in MS-DOS con qualunque carattere anche nullo   

3. Per la memoria secondaria usata per l'implementazione del File System quale è caratteristica più rilevante?  
    a. La caratteristica più rilevante è quella di essere costituita da media diversi  
    b. La caratteristica più rilevante è quella di essere una memoria di massa  
    c. La caratteristica più rilevante è quella di virtualizzare il concetto di file  
    d. La caratteristica più rilevante è quella di essere una memoria permanente☑️  

4. Facendo riferimento alla struttura di un File System, il livello implementativo I/O control:  
    a. conosce la struttura delle directory e si occupa delle richieste dell'utente  
    b. genera gli indirizzi fisici in termini di numero di traccia e numero di settore☑️  
    c. considera il volume logico come insieme di blocchi  
    d. genera gli indirizzi in termini di blocchi e richiede la lettura/scrittura al livello sottostante  

5. In un generico Sistema Operativo, un file ha sempre:  
    a. almeno un nome☑️  
    b. un nome  
    c. un nome costituito da una parte base e da una estensione  
    d. un nome di lunghezza limitata in caratteri  

6. Nel Sistema Operativo Unix, facendo riferimento alla gestione dei file, è possibile affermare che:  
    a. i link simbolici devono essere utilizzati per creare link a directory e per creare link tra file system fisici diversi☑️  
    b. i link hardware devono essere utilizzati per creare link tra file system logici diversi  
    c. i link hardware devono essere utilizzati per creare link a directory e per creare link tra file system fisici diversi  
    d. i link simbolici devono essere utilizzati per creare link a directory che appartengono allo stesso utente  

7. Quale è la proprietà fondamentale del File System?  
    a. La proprietà fondamentale è quella di virtualizzare il concetto di directory  
    b. La proprietà fondamentale è quella di virtualizzare i dispositivi di memorizzazione permanente, fornendo una visione logica uniforme☑️  
    c. La proprietà fondamentale è quella di virtualizzare i dischi rigidi, ma non gli altri dispositivi di memorizzazione permanente  
    d. La proprietà fondamentale è quella di concorrere alla realizzazione della memoria virtuale  

8. Nel Sistema Operativo Unix, due processi possono condividere un file se e solo se:  
    a. sono processi in relazione di parentela  
    b. sono processi indipendenti  
    c. sono processi disgiunti  
    d. nessuna delle alternative presenti, dato che in Unix due processi possono condividere un file senza nessuna condizione☑️  

9. In un Sistema Operativo, la dimensione del record logico per memorizzare i dati nei file è:  
    a. Sempre diversa da quella del record fisico e quindi serve fare il packing dei record fisici (blocchi) nel record logico  
    b. Sempre uguale a quella del record fisico (blocco)  
    c. Sempre diversa da quella del record fisico e quindi serve fare il packing dei record logici nel record fisico (blocco)☑️  
    d. La dimensione del record logico è sempre un multiplo di 512 byte (che è la dimensione di un blocco)  

10. Facendo riferimento al concetto di file da un punto di vista esterno, individua l'affermazione errata:  
    a. un file ha sempre un descrittore associato  
    b. un file ha sempre diversi nomi che lo identificano☑️  
    c. un file è la più piccola parte di memoria secondaria indirizzabile  
    d. nessuna delle alternative presenti  

11. Facendo riferimento alla struttura di un File System, il livello implementativo logical File System:  
    a. trasferisce blocchi di informazioni tra il disco e la memoria  
    b. genera gli indirizzi in termini di blocchi e richiede la lettura/scrittura al livello sottostante  
    c. conosce la struttura delle directory e si occupa delle richieste dell'utente☑️  
    d. genera gli indirizzi fisici in termini di numero di traccia e numero di settore  

12. Facendo riferimento alla struttura di un File System, il livello implementativo basic File System:  
    a. trasferisce blocchi di informazioni tra il disco e la memoria  
    b. conosce la struttura delle directory e si occupa delle richieste dell'utente  
    c. genera gli indirizzi in termini di blocchi e richiede la lettura/scrittura al livello sottostante☑️  
    d. genera gli indirizzi fisici in termini di numero di traccia e numero di settore  

13. Facendo riferimento alla struttura di un File System, quali possono essere in generale i livelli implementativi nel quale è suddiviso?  
    a. basic File System - I/O control  
    b. file-organization module - basic File System - I/O control  
    c. logical File System - file-organization module - basic File System - I/O control☑️  
    d. logical File System - I/O control  

14. In un Sistema Operativo generale, come può essere implementata la Matrice di Protezione necessaria per l'accesso controllato alle risorse?  
    a. Utilizzando solo una memorizzazione delle righe usando le C-List (Capability List)  
    b. Utilizzando solo una matrice sparsa  
    c. Utilizzando o una memorizzazione delle colonne usando le ACL (Access Control List) oppure una memorizzazione delle righe usando le C-List (Capability List)☑️  
    d. Utilizzando solo una memorizzazione delle colonne usando le ACL (Access Control List)  

15. Nel Sistema Operativo Unix, come viene implementata la Matrice di Protezione necessaria per l'accesso controllato ai file/directory?  
    a. Utilizzando una memorizzazione delle colonne usando le ACL (Access Control List)  
    b. Utilizzando una memorizzazione delle righe usando le C-List (Capability List)  
    c. Utilizzando una memorizzazione delle colonne usando le ACL (Access Control List) in versione ridotta☑️  
    d. Utilizzando una matrice sparsa  

16. Quali sono le proprietà di una organizzazione ad albero di directory?  
    a. un albero di directory ha una UNICA RADICE e ogni directory può contenere sia file che directory  
    b. un albero di directory ha una UNICA RADICE e una directory corrente  
    c. un albero di directory ha una UNICA RADICE e ogni file ha un unico PATH NAME  
    d. un albero di directory ha una UNICA RADICE, ogni file ha un unico PATH NAME e ogni directory può contenere sia file che directory☑️  

17. Facendo riferimento ad un grafo aciclico di directory, è possibile affermare che:  
    a. un link simbolico è un file speciale che contiene il path name completo del file condiviso, mentre un link hardware è una copia del descrittore del file condiviso☑️  
    b. un link hardware è una entry particolare all'interno del descrittore del file condiviso, mentre un link simbolico è una copia del file condiviso  
    c. un link simbolico è una entry particolare all'interno del descrittore del file condiviso, mentre un link hardware è una copia del file condiviso  
    d. un link hardware è un file speciale che contiene il path name completo del file condiviso, mentre un link simbolico è una copia del descrittore del file condiviso  

18. Facendo riferimento alla gestione dei file in un Sistema Operativo generale, che cos'è il FCB?  
    a. FCB è un acronimo che significa File Counter Block, ed è un contatore che tiene traccia del numero di aperture di ogni file presente nella Tabella dei File Aperti  
    b. FCB è un acronimo che significa File Chain Block, ed è una tabella di sistema che associa il nome logico del file all'utente proprietario  
    c. FCB è un acronimo che significa File Control Buffer, ed è una zona di memoria centrale dedicata ai file in attesa di essere scritti sul disco  
    d. FCB è un acronimo che significa File Control Block, ed è il nome con cui vengono chiamati i record della Tabella dei File Aperti☑️  

19. In un Sistema Operativo Unix, è possibile affermare che:  
    a. un File System logico corrisponde ad un solo File System fisico  
    b. un File System logico contiene uno o più File System fisici, solo se questi sono remoti  
    c. un File System logico contiene uno o più File System fisici☑️  
    d. un File System fisico contiene uno o più File System logici  

20. In un Sistema Operativo Unix, le informazioni relative al dominio di protezione di ogni file sono mantenute in:  
    a. una matrice di protezione  
    b. una lista di capability  
    c. una lista di controllo  
    d. una lista di controllo ridotta☑️  

21. In un generico Sistema Operativo, un file ha fra i suoi metadati sempre:  
    a. un tipo, la dimensione, il creatore del file, la protezione e dati di controllo d'uso, oltre la locazione del file sul dispositivo  
    b. un tipo, oltre la locazione del file sul dispositivo  
    c. la locazione del file sul dispositivo☑️  
    d. un tipo, il creatore del file e la protezione, oltre la locazione del file sul dispositivo  

22. Facendo riferimento alla gestione dei file, è possibile affermare che la matrice di protezione:  
    a. è una struttura dati logica di ogni file nella quale vengono mantenute le relazioni tra gli utenti e il file stesso  
    b. è un particolare tipo di ACL  
    c. è un particolare tipo di C-List  
    d. è una struttura dati logica del Sistema Operativo nella quale vengono mantenute le relazioni tra risorse e domini di protezione☑️  

23. In un generico Sistema Operativo, come avviene l'accesso sequenziale ad un file?  
    a. L'accesso sequenziale avviene con la sola primitiva write, dato che la read dovendo sempre leggere dall'inizio del file deve prima spostare il file pointer con la primitiva seek per raggiungere l'inizio del file  
    b. L'accesso sequenziale avviene con le primitive read e write che spostano automaticamente il file pointer☑️  
    c. L'accesso sequenziale avviene con le primitive read e write e spostando poi il file pointer con la primitiva seek per mantenere la consistenza rispetto alle primitive read/write  
    d. L'accesso sequenziale avviene con la sola primitiva read, dato che la write dovendo sempre scrivere in fondo al file deve prima spostare il file pointer con la primitiva seek per raggiungere la fine del file  
 
 24. Facendo riferimento alla struttura delle directory, è possibile affermare che le directory a due livelli:  
    a. sono adatti a sistemi multiutente e, per la singola utenza, risolvono il problema dell'unicità dei nomi ma possono presentare un lungo elenco di nomi di file  
    b. non sono adatti a sistemi multiutente, non risolvono il problema dell'unicità dei nomi e possono presentare un lungo elenco di nomi di file per ogni utente  
    c. sono adatti a sistemi multiutente, risolvono il problema dell'unicità dei nomi tra utenti diversi e, per la singola utenza, non presentano un lungo elenco di nomi di file  
    d. sono adatti a sistemi multiutente, ma, per la singola utenza, non risolvono il problema dell'unicità dei nomi e possono presentare un lungo elenco di nomi di file☑️  
 
 25. Quali sono le tecniche principali usate dai Sistemi Operativi per identificare i tipi di file?  
    a. l'unica tecnica possibile è quella di usare i magic number  
    b. le tecniche sono 3 e sono il meccanismo  delle  estensioni, attributo “tipo” associato al file e i magic number☑️  
    c. l'unica tecnica possibile è quella di inserire fra i metadati il “tipo” associato al file  
    d. l'unica tecnica possibile è quella di usare una estensione nel nome del file  
 
 26. In un Sistema Operativo generale, quale delle seguenti funzioni non è propria di un gestore di file?  
    a. trasferimento di dati che compongono un file tra memoria principale e memoria secondaria  
    b. meccanismi di protezione e condivisione dei file  
    c. traduzione delle richieste di accesso dallo spazio di indirizzamento logico a quello fisico  
    d. gestione della memoria principale, delle cache e della memoria secondaria☑️  
 
 27. In un Sistema Operativo generale, che cosa è una directory:  
    a. Una directory è una porzione di un disco che contiene un insieme di file  
    b. Una directory è un insieme di descrittori di file, memorizzato in memoria secondaria☑️  
    c. Una directory è una locazione in memoria secondaria dove si trovano i nomi di tutti i file del File System  
    d. Una directory è una speciale struttura dati mantenuta in memoria centrale  
 
 28. In un Sistema Operativo Unix, nella struttura delle directory a grafo, è contemplata la presenza di cicli?  
    a. sì, e la loro presenza viene individuata solo durante l'utilizzo dei nomi di file☑️  
    b. no, in quanto la struttura è per definizione aciclica  
    c. sì, e la loro presenza viene individuata prima dell'utilizzo dei nomi di file  
    d. nessuna delle alternative presenti  
 
 29. Nel Sistema Operativo Unix, il JCL che veniva usato dai Sistemi Operativi con esecuzione batch, a che cosa corrisponde?  
    a. Al linguaggio comandi della sola Bash  
    b. Al linguaggio comandi di una qualunque shell☑️  
    c. nessuna delle alternative presenti  
    d. Al linguaggio comandi della sola Bourne shell  