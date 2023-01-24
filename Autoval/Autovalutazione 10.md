2022-11-30

1. Facendo riferimento, nella gestione della memoria virtuale, alle strategie di allocazione delle pagine, è possibile affermare che:  
    a. il working set di un processo è una approssimazione della località del processo stesso  
    b. la località di un processo è un sottoinsieme del working set del processo stesso  
    c. la località di un processo è l'insieme delle pagine che compongono il working set del processo in un certo istante  
    d. il working set di un processo coincide con la località del processo stesso☑️  

2. Nel Sistema Operativo Unix (versioni attuali), quale schema di gestione della memoria centrale si usa?  
    a. uno schema a paginazione su cui si basa la memoria virtuale con paginazione su richiesta ottimizzata e algoritmo di seconda chance come politica di sostituzione delle pagine  
    b. uno schema a segmentazione paginata su cui si basa la memoria virtuale con paginazione su richiesta ottimizzata e algoritmo di seconda chance come politica di sostituzione delle pagine☑️  
    c. uno schema a segmentazione su cui si basa la memoria virtuale con segmentazione su richiesta ottimizzata e algoritmo di seconda chance come politica di sostituzione dei segmenti  
    d. uno schema a paginazione segmentata su cui si basa la memoria virtuale con segmentazione su richiesta ottimizzata e algoritmo di seconda chance come politica di sostituzione dei segmenti  

3. In un Sistema Operativo a memoria virtuale paginata, in caso si renda necessario la sostituzione di una pagina in memoria centrale dopo un'interruzione di tipo page fault, è possibile affermare che:  
    a. la pagina "vittima" può essere scelta tra le pagine del processo che ha subito l'interruzione o tra tutte le pagine presenti in memoria centrale, a seconda che il processo sia stato lanciato in modo utente o in modo supervisore  
    b. si predilige una politica di sostituzione locale, in modo che il numero di pagine allocate per ogni processo rimanga costante  
    c. la pagina "vittima" viene solitamente scelta tra le pagine del processo che ha subito l'interruzione, in modo da garantire all'incirca le stesse performance ad ogni esecuzione  
    d. si predilige una politica di sostituzione globale, in quanto presenta un valore di throughput più elevato rispetto ad una politica di tipo locale☑️  

4. Un Sistema Operativo a memoria virtuale paginata è in trashing:  
    a. se spende più tempo nell'esecuzione dei processi utente che nel trattamento della memoria virtuale  
    b. se spende più tempo nel trattamento della memoria virtuale che nell'esecuzione dei processi utente☑️  
    c. se al diminuire del grado di multiprogrammazione aumenta la frequenza dei page fault  
    d. se al diminuire della frequenza dei page fault aumenta il grado di multiprogrammazione  

5. In un Sistema Operativo Unix, relativamente alla memoria virtuale, quale politica di sostituzione viene utilizzata?  
    a. politica di sostituzione FIFO  
    b. politica di sostituzione OPT  
    c. politica di sostituzione che approssima LRU, ed è basata su un algoritmo di seconda chance☑️  
    d. politica di sostituzione di tipo LRU, ed è basata su un algoritmo a classi di pagine  

6. Come funziona il metodo BUDDY per la gestione della memoria?  
    a. Utilizza una partizione di dimensione fissa, composta da pagine fisicamente contigue, e su questa applica un allocatore-potenza-di-2☑️  
    b. Utilizza una partizione di dimensione variabile e su questa applica un allocatore-potenza-di-2  
    c. Utilizza una partizione di dimensione fissa, composta da pagine fisicamente contigue, e su questa applica un allocatore a pagine  
    d. Utilizza una partizione di dimensione fissa, composta da pagine, e su questa applica un allocatore-potenza-di-2  

7. Facendo riferimento alla politica di allocazione delle pagine basata sulla teoria del working set e usata nella memoria virtuale, è possibile affermare che, per approssimare il working set, viene campionato/a a intervalli regolari:  
    a. il dirty bit  
    b. il reference bit☑️  
    c. la coppia "dirty bit - reference bit"  
    d. il bit di presenza  

8. Facendo riferimento al concetto di cache delle pagine in ambienti multiprocesso con memoria virtuale, è possibile affermare che:  
    a. si predilige l'utilizzo di una cache non dedicata insieme ad una politica globale di rimpiazzamento delle pagine caricate nella cache basata sull'algoritmo LRU  
    b. si predilige l'utilizzo di una cache dedicata per ogni processo insieme ad una politica di rimpiazzamento delle pagine caricate nella cache basata sull'algoritmo FIFO  
    c. si predilige l'utilizzo di una cache non dedicata insieme ad una politica locale di rimpiazzamento delle pagine caricate nella cache basata sull'algoritmo LRU☑️  
    d. si predilige l'utilizzo di una cache dedicata per ogni processo insieme ad una politica di rimpiazzamento delle pagine caricate nella cache basata sull'algoritmo LRU  

9. Nel caso di utilizzo di segmentazione paginata per gestire la memoria virtuale, quale delle seguenti affermazioni è vera?  
    a. se non fosse caricata in memoria centrale alcun segmento, si dovrebbe passare ad una gestione basata solo su paginazione  
    b. se non fosse caricata in memoria centrale alcuna pagina di un certo segmento, potrebbe essere usato un bit di presenza di pagina nella TDS  
    c. se non fosse caricata in memoria centrale alcuna pagina di un certo segmento, potrebbe essere usato un bit di presenza di segmento nella TDS☑️  
    d. nessuna della alternative presenti  

10. In un Sistema Operativo a memoria virtuale paginata, il reference bit di ogni pagina viene messo a 1:  
    a. ogni volta che la pagina in questione viene acceduta☑️  
    b. ogni volta che la pagina in questione viene portata in memoria centrale/secondaria  
    c. ogni volta che la pagina in questione viene modificata  
    d. nessuna delle alternative presenti  

11. Quali vantaggi si hanno ad usare i file mappati in memoria?  
    a. si alleggerisce il lavoro del sistema di I/O e, tramite la condivisione di pagine, si realizza facilmente la condivisione dello stesso file fra più processi  
    b. si ha un accesso più rapido alle informazioni e, tramite la condivisione di pagine, si realizza facilmente la condivisione dello stesso file fra più processi  
    c. si alleggerisce il lavoro del sistema di I/O, si ha un accesso più rapido alle informazioni e, tramite la condivisione di pagine, si realizza facilmente la condivisione dello stesso file fra più processi☑️  
    d. l’unico vantaggio è l’uso di file temporanei senza scrittura su disco  

12. Facendo riferimento alle strategie di allocazione delle pagine usata nella memoria virtuale, si può affermare che la politica basata sulla frequenza dei page fault prevede:  
    a. l'individuazione e l'utilizzo di due valori limite☑️  
    b. l'utilizzo di un clock dedicato  
    c. il campionamento dei reference bit di ogni pagina ad intervalli di tempo regolari  
    d. l'utilizzo di una coda circolare  

13. In un Sistema Operativo Unix, relativamente alla memoria virtuale, facendo riferimento ai parametri caratteristici del pagedaemon:  
    a. lo scheduler attiva il pagedaemon se il numero di frame liberi è minore di minfree  
    b. lo scheduler attiva lo swapper se il numero di frame liberi è minore di desfree  
    c. lo scheduler attiva lo swapper se il numero di frame liberi è minore di lotsfree  
    d. lo scheduler attiva il pagedaemon se il numero di frame liberi è minore di lotsfree☑️  

14. Il metodo a LASTRE che vantaggio presenta rispetto a metodo BUDDY?  
    a. usa sempre pagine contigue  
    b. elimina il problema di frammentazione, poiché si utilizzano sempre partizioni di dimensione variabile  
    c. elimina il problema di frammentazione, poiché si utilizzano cache di oggetti☑️  
    d. nessuno  

15. In un Sistema Operativo a memoria virtuale paginata nel quale viene utilizzato un algoritmo di seconda chance migliorato, la pagina migliore da sostituire dovrebbe appartenere alla classe:  
    a. (1, 0)  
    b. (1, 1)  
    c. (0, 0)☑️  
    d. (0, 1)  

16. In un Sistema Operativo a memoria virtuale paginata nel quale viene utilizzato un algoritmo di seconda chance migliorato, si sostituisce la prima pagina che si trova:  
    a. nella classe minima non piena  
    b. nella classe massima non vuota  
    c. nella classe massima non piena  
    d. nella classe minima non vuota☑️  

17. In un Sistema Operativo Unix, relativamente alla memoria virtuale, si rende necessario evitare che il pagedaemon usi più del 10% del tempo totale di CPU affinché:  
    a. non venga sostituito un numero troppo elevato di pagine  
    b. non si verifichino situazioni di deadlock  
    c. nessuna delle alternative presenti  
    d. non si verifichino situazioni di thrashing☑️  

18. In un Sistema Operativo a memoria virtuale paginata, facendo riferimento all'algoritmo di sostituzione delle pagine di seconda chance, è possibile affermare che:  
    a. si rende necessario l'utilizzo di un byte di storia  
    b. l'algoritmo usa il reference bit su una coda circolare di numeri di pagina☑️  
    c. si rende necessario l'utilizzo di un apposito clock  
    d. l'algoritmo usa sia il reference che il dirty bit  

19. In un generico Sistema Operativo, nelle implementazioni che approssimano l'algoritmo di sostituzione di pagine LRU per la gestione della memoria virtuale, quali meccanismi vengono utilizzati?  
    a. Si devono usare sempre insieme i meccanismi del reference bit e del dirty bit  
    b. L'unico meccanismo utilizzato è quello del working set  
    c. Il meccanismo più utilizzato è quello del reference bit☑️  
    d. Il meccanismo più utilizzato è quello del dirty bit  

20. In un Sistema Operativo con memoria virtuale, l'algoritmo di sostituzione LRU (completo):  
    a. è implementabile solo se a livello architetturale è presente hardware dedicato aggiuntivo☑️  
    b. è implementabile solo se a livello architetturale è presente il dirty bit  
    c. è implementabile solo se a livello architetturale sono presenti il dirty bit e il reference bit  
    d. è implementabile solo se a livello architetturale è presente il reference bit  

21. In un Sistema Operativo Unix, relativamente alla memoria virtuale, facendo riferimento ai parametri caratteristici del pagedaemon (quindi, lotsfree: numero minimo di frame liberi per evitare paginazione su richiesta, minfree: numero minimo di frame liberi necessari per evitare lo swapping dei processi, desfree: numero minimo di frame desiderabili), quale delle seguenti relazioni è corretta?  
    a. desfree > minfree > lotsfree  
    b. lotsfree > minfree > desfree  
    c. minfree < desfree < lotsfree☑️  
    d. minfree < lotsfree < desfree  

22. Cosa significa avere file mappati in memoria?  
    a. caricare tutti i blocchi del disco, che contengono i dati di un file, in pagine riservate della memoria; tutti i blocchi di un file vengono caricati in memoria o in modo implicito all’atto della open del file o in modo esplicito tramite una system call (ad esempio mmap di Posix)  
    b. avere dei file temporanei che sono presenti solo nelle pagine della memoria e i cui dati non permangono allo spegnimento del sistema  
    c. associare i blocchi del disco, che contengono i dati di un file, a pagine della memoria; i blocchi di un file vengono caricati in memoria solo su necessità o in modo implicito all’atto della open del file o in modo esplicito tramite una system call (ad esempio mmap di Posix)☑️  
    d. associare i blocchi del disco, più utilizzati di un file, a pagine della memoria; tali blocchi di un file vengono caricati in memoria all’inizio sulla base di una system call (ad esempio mmap di Posix)  

23. Il kernel di un S.O. come gestisce la memoria per sé stesso?  
    a. si utilizza sempre un metodo di allocazione contigua come il metodo BUDDY o quello a LASTRE☑️  
    b. si utilizza la stessa politica che si usa per i processi utente, ma non si utilizza la memoria virtuale  
    c. si utilizza sempre la paginazione  
    d. si utilizza la stessa politica che si usa per i processi utente  

24. Come si evita il problema della sostituzione di una pagina utilizzata in un’operazione di I/O, in caso di algoritmo di sostituzione globale?  
    a. L’unica soluzione è di usare buffer di sistema e quindi aggirare il problema  
    b. Ci sono solo 2 possibilità: o si usano buffer di sistema e quindi aggira il problema o si ‘blocca’ la pagina in modo che non venga rimpiazzata☑️  
    c. L’unica soluzione è di non attivare la sostituzione globale se qualche processo è bloccato in operazioni di I/O  
    d. Ci sono solo 2 possibilità: o si usano file mappati in memoria o si ‘blocca’ la pagina in modo che non venga rimpiazzata  

25. In un Sistema Operativo a memoria virtuale paginata, facendo riferimento alle politiche di sostituzione delle pagine e supponendo di memorizzare in un byte di storia i reference bit campionati ad intervalli regolari, è possibile affermare che:  
    a. la pagina "vittima" sarà quella con il minor byte di storia, interpretando quest'ultimo come intero con segno  
    b. la pagina "vittima" sarà quella con il minor byte di storia, interpretando quest'ultimo come intero senza segno☑️  
    c. la pagina "vittima" sarà quella con il maggior byte di storia, interpretando quest'ultimo come intero senza segno  
    d. la pagina "vittima" sarà quella con il maggior byte di storia, interpretando quest'ultimo come intero con segno  