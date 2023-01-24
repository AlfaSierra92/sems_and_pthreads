2022-11-23

1. In un Sistema Operativo a memoria virtuale paginata, il dirty bit di ogni pagina (se presente) viene messo a 1:  
     a. ogni volta che la pagina in questione viene portata in memoria centrale/secondaria  
     b. ogni volta che la pagina in questione viene acceduta  
     c. nessuna delle alternative presenti  
     d. ogni volta che la pagina in questione viene modificata☑️  

2. Facendo riferimento alla tecnica della memoria virtuale, nel caso di paginazione su richiesta, si può affermare che il pager:  
     a. è un meccanismo del sistema operativo che si occupa del trasferimento delle pagine da/verso la memoria secondaria/centrale☑️  
     b. è un meccanismo del sistema operativo che si occupa del trasferimento dell'intero spazio di indirizzamento del processo da/verso la memoria secondaria/centrale  
     c. è un algoritmo di sostituzione usato per il trasferimento dell'intero spazio di indirizzamento del processo da/verso la memoria secondaria/centrale  
     d. è una politica adottata per il trasferimento delle pagine da/verso la memoria secondaria/centrale  

3. In un Sistema Operativo generale nel quale si fa uso di memoria paginata con dimensione della memoria fisica pari ad 1 MegaByte (1 MB = 220 byte), supponendo che ogni pagina abbia una dimensione di 256 byte, calcolare il numero di pagine che è possibile ottenere ed il numero di bit necessari per identificare l'indirizzo fisico, suddivisi in bit per la pagina e bit per lo spiazzamento:  
     a. 2048 pagine, 8 bit per la pagina, 20 bit per lo spiazzamento  
     b. 2048 pagine, 12 bit per la pagina, 8 bit per lo spiazzamento  
     c. 4096 pagine, 8 bit per la pagina, 20 bit per lo spiazzamento  
     d. 4096 pagine, 12 bit per la pagina, 8 bit per lo spiazzamento☑️  

4. Facendo riferimento alla tecnica della paginazione, e indicando con X il numero medio di righe della TDM che si devono esaminare per trovare NL pagine libere, è possibile affermare che:  
     a. X è direttamente proporzionale a NL secondo un fattore K=1/Q, dove Q è la probabilità che una certa pagina fisica sia libera☑️  
     b. X è direttamente proporzionale a NL secondo un fattore K=1/Q, dove Q è la probabilità che una certa pagina fisica sia occupata  
     c. X è direttamente proporzionale a NL secondo un fattore Q, dove Q è la probabilità che una certa pagina fisica sia occupata  
     d. X è inversamente proporzionale a NL secondo un fattore Q, dove Q è la probabilità che una certa pagina fisica sia libera  

5. In un Sistema Operativo generale in cui si fa uso di memoria virtuale, è possibile affermare che l'hardware:  
     a. deve essere in grado di riconoscere un'interruzione sia durante che al termine dell'esecuzione dell'istruzione☑️  
     b. deve essere in grado di riconoscere un'interruzione solamente al termine dell'esecuzione dell'istruzione  
     c. deve essere in grado di riconoscere un'interruzione o durante l'esecuzione dell'istruzione o al termine dell'esecuzione  
     d. deve essere in grado di riconoscere un'interruzione solamente durante l'esecuzione dell'istruzione  

6. Facendo riferimento, nella gestione della memoria virtuale, alle politiche di sostituzione delle pagine in memoria reale, quale delle seguenti affermazioni è corretta?  
     a. solamente la politica LRU è soggetta all'anomalia di Belady  
     b. nessuna delle alternative presenti☑️  
     c. sia la politica FIFO che la politica LRU sono soggette all'anomalia di Belady  
     d. sia la politica FIFO che la politica OPT sono soggette all'anomalia di Belady  

7. In un Sistema Operativo generale in cui si fa uso di memoria virtuale basata su paginazione, all'atto di un'interruzione di tipo page fault, si verifica la seguente situazione:  
     a. il processo che ha subito l'interruzione continua ugualmente l'esecuzione, senza recuperare la pagina mancante  
     b. il processo che ha subito l'interruzione rimane sospeso finché non viene sfrattata una pagina dalla memoria centrale da parte del Sistema Operativo  
     c. il processo che ha subito l'interruzione continua ugualmente l'esecuzione, e recupera solo in un secondo momento la pagina mancante  
     d. il processo che ha subito l'interruzione rimane sospeso finché la pagina mancante non viene portata in memoria reale da parte del Sistema Operativo☑️  

8. In un Sistema Operativo a memoria virtuale paginata, si consideri la seguente sequenza di riferimenti a pagine logiche: 1 2 3 4 5 3 4 1 6 7 8 7 8 9 7 8 9 5 4 5 4 2 Considerando 4 pagine fisiche utilizzabili dal processo, quanti page fault sono generati rispettivamente con gli algoritmi di sostituzione FIFO e LRU?  
     a. 13, 10  
     b. 14, 12  
     c. 13, 13☑️  
     d. 12, 14  

9. In un Sistema Operativo generale nel quale si fa uso di memoria paginata con dimensione della dimensione della memoria fisica è pari ad 32 MegaByte (32 MB = 225 byte), supponendo che ogni pagina abbia una dimensione di 256 byte, calcolare il numero di pagine che è possibile ottenere ed il numero di bit necessari per identificare l'indirizzo fisico, suddivisi in bit per la pagina e bit per lo spiazzamento:  
     a. 131072 pagine, 17 bit per la pagina, 8 bit per lo spiazzamento☑️  
     b. 65536 pagine, 16 bit per la pagina, 8 bit per lo spiazzamento  
     c. 131072 pagine, 9 bit per la pagina, 16 bit spiazzamento  
     d. 65536 pagine, 17 bit per la pagina, 8 bit per lo spiazzamento  

10. In un Sistema Operativo generale, qual è la differenza significativa nella conversione da indirizzo logico ad indirizzo fisico in uno schema di memoria a pagine rispetto a uno schema di memoria a segmenti?  
     a. Non vi è nessuna differenza significativa  
     b. Nel caso di uno schema di memoria a pagine la conversione da indirizzo logico a fisico prevede che l'indirizzo logico sia già  suddiviso in un numero di pagina e in un offset, mentre nel caso di uno schema di memoria a segmenti la conversione da indirizzo logico a fisico prevede una suddivisione automatica a livello Hw nell'indirizzo logico fra numero di segmento logico e offset  
     c. Nel caso di uno schema di memoria a pagine la conversione da indirizzo logico a fisico prevede di usare una tabella delle pagine, mentre nel caso di uno schema di memoria a segmenti la conversione da indirizzo logico a fisico prevede una tabella dei segmenti  
     d. Nel caso di uno schema di memoria a pagine la conversione da indirizzo logico a fisico prevede inizialmente una suddivisione automatica a livello Hw nell'indirizzo logico fra numero di pagina logica e offset, mentre nel caso di uno schema di memoria a segmenti la conversione da indirizzo logico a fisico prevede che l'indirizzo logico sia già  suddiviso in un numero di segmento e in un offset☑️  

11. In un Sistema Operativo generale in cui si fa uso di memoria virtuale basata su paginazione, all'atto di un'interruzione di tipo page fault, è necessario interrompere il processo e riprenderne l'esecuzione in futuro. In particolar modo, quando il processo torna in esecuzione:  
     a. è possibile solamente rieseguire interamente l'istruzione che ha causato l'interruzione, a patto che sia stato salvato lo stato interno della CPU nel momento in cui è avvenuta l'interruzione  
     b. è possibile solamente riprendere l'esecuzione dal punto esatto in cui è avvenuta l'interruzione, a patto che sia stato salvato lo stato interno della CPU nel momento in cui è avvenuta l'interruzione☑️  
     c. nessuna delle alternative presenti  
     d. è necessario rieseguire interamente l'istruzione che ha causato l'interruzione  

12. In un Sistema Operativo con gestione della memoria basata su segmentazione paginata, come avviene il calcolo dell'indirizzo fisico a partire dall'indirizzo logico?  
     a. determinando il numero di pagina logica P e lo spiazzamento S, quindi recuperando il numero d'ordine della pagina fisica dall'elemento P-esimo della Tabella delle Pagine del processo corrente e concatenando ad esso lo spiazzamento S  
     b. bisogna determinare il numero di pagina P e lo spiazzamento S, quindi recuperare, dall'elemento P-esimo della Tabella delle Pagine del processo corrente, l'indirizzo base della Tabella dei Segmenti di P; successivamente, utilizzando tale Tabella dei Segmenti e lo spiazzamento S, il meccanismo hardware procede all'individuazione dell'indirizzo di partenza del segmento e dell'offset O, in maniera analoga al caso della segmentazione pura  
     c. bisogna determinare il numero di segmento S e l'offset O, quindi recuperare, dall'elemento S-esimo della Tabella dei Segmenti del processo corrente, l'indirizzo base della Tabella delle Pagine di S; successivamente, utilizzando tale Tabella delle Pagine e l'offset O, il meccanismo hardware procede all'individuazione dell'indirizzo della pagina fisica e dello spiazzamento, in maniera analoga al caso della paginazione pura☑️  
     d. determinando il numero di segmento S e l'offset O, quindi recuperando l'indirizzo di partenza del segmento S dall'elemento S-esimo della Tabella dei Segmenti del processo corrente e sommando tale indirizzo all'offset O  

13. In un Sistema Operativo generale in cui si fa uso di memoria virtuale basata su paginazione, all'atto della sostituzione di una pagina in memoria reale:  
     a. si può sovrascrivere direttamente la pagina "vittima", in caso quest'ultima non sia stata modificata o abbia il dirty bit settato a 1  
     b. si deve copiare in memoria secondaria la pagina "vittima" prima della sostituzione, nel caso in cui il dirty bit sia settato a 0  
     c. non si deve copiare in memoria secondaria la pagina "vittima" prima della sostituzione, nel caso in cui il dirty bit sia settato a 0☑️  
     d. si deve copiare in memoria secondaria la pagina "vittima" prima della sostituzione, in caso quest'ultima non sia stata modificata o presenti il dirty bit settato a 1  

14. In un Sistema Operativo con gestione della memoria a pagine, come avviene il calcolo dell'indirizzo fisico partendo dall'indirizzo logico?  
     a. determinando il numero di pagina logica P, quindi recuperando il numero d'ordine della pagina fisica dall'elemento P-esimo della Tabella delle Pagine del processo corrente  
     b. determinando lo spiazzamento S, e quindi concatenando al numero di pagina corrente lo spiazzamento S  
     c. determinando il numero di pagina logica P e lo spiazzamento S, quindi recuperando il numero d'ordine della pagina fisica dall'elemento P-esimo della Tabella delle Pagine del processo corrente e concatenando ad esso lo spiazzamento S☑️  
     d. determinando il numero di pagina logica P e lo spiazzamento S, quindi recuperando il numero d'ordine della pagina fisica dall'elemento P-esimo della Tabella delle Pagine del processo corrente e sommando ad esso lo spiazzamento S  

15. Facendo riferimento alla tecnica della paginazione, è possibile affermare che:  
     a. è interamente gestita dal Sistema Operativo, elimina il problema della frammentazione esterna, non presenta evidenti complessità nell'allocazione/deallocazione delle pagine ma necessita di hardware dedicato molto sofisticato☑️  
     b. è interamente gestita dal Sistema Operativo, elimina il problema della frammentazione esterna, non presenta evidenti complessità nell'allocazione/deallocazione delle pagine e non necessita di hardware dedicato molto sofisticato  
     c. è interamente gestita dal Sistema Operativo, elimina il problema della frammentazione interna, presenta evidenti complessità nell'allocazione/deallocazione delle pagine e necessita di hardware dedicato molto sofisticato  
     d. non è interamente gestita dal Sistema Operativo, elimina il problema della frammentazione interna, non presenta evidenti complessità nell'allocazione/deallocazione ma necessita di hardware dedicato molto sofisticato  

16. Facendo riferimento ai supporti hardware per la tecnica della paginazione, che cos'è il TLB?  
     a. TLB è un acronimo che significa Translation Left-aside Buffer, ed è una memoria associativa ad alta velocità utilizzata per memorizzare un sottoinsieme della tabella delle pagine  
     b. TLB è un acronimo che significa Translation Look-aside Buffer, ed è una struttura dati, salvata su una memoria associativa ad alta velocità, in cui ogni elemento è una coppia formata da un numero di pagina logica ed il corrispondente numero di pagina fisica (copiato dalla tabella delle pagine)☑️  
     c. TLB è un acronimo che significa Table Look-aside Buffer, ed è una struttura dati contenente il registro base ed il registro limite della tabella delle pagine  
     d. TLB è un acronimo che significa Translation Look-aside Block, ed è il blocco di memoria contenente la tabella delle pagine del processo in esecuzione  

17. In un Sistema Operativo generale, qual è il vantaggio di uno schema di memoria a pagine rispetto a uno schema a segmenti?  
     a. Elimina la frammentazione interna  
     b. Rende più facile la protezione selettiva sulle pagine, in quanto le pagine sono di solito di dimensioni più piccole dei segmenti  
     c. La tabella delle pagine è più piccola della tabella dei segmenti, a parità di dimensioni dello spazio di indirizzamento del processo  
     d. Elimina la frammentazione esterna☑️  

18. Facendo riferimento alla tecnica della paginazione, la tabella delle pagine (tradizionale):  
     a. è una struttura dati per ogni processo, in cui ogni elemento è il numero d'ordine della pagina fisica☑️  
     b. è una struttura dati comune a tutti i processi, in cui ogni elemento è il numero d'ordine della pagina fisica  
     c. è una struttura dati per ogni processo, in cui ogni elemento è una coppia formata dall'indirizzo fisico iniziale della memoria in cui risiede la pagina e dallo spiazzamento  
     d. è una struttura dati comune a tutti i processi, in cui ogni elemento è una coppia formata dal numero d'ordine della pagina fisica e dallo spiazzamento  

19. In un Sistema Operativo a memoria virtuale paginata, il bit di presenza di ogni pagina viene modificato:  
     a. ogni volta che la pagina in questione viene portata in memoria centrale/secondaria☑️  
     b. ogni volta che la pagina in questione viene modificata  
     c. ogni volta che la pagina in questione viene acceduta  
     d. nessuna delle alternative presenti  

20. In un Sistema Operativo a memoria virtuale paginata, si consideri la seguente sequenza di riferimenti a pagine logiche:  4 2 3 1 5 3 6 7 6 4 7 3 1 2 5 Considerando 4 pagine fisiche utilizzabili dal processo, quanti page fault sono generati rispettivamente con gli algoritmi di sostituzione FIFO e LRU?  
      a. 12, 10  
     b. 11,10  
     c. 10, 7  
     d. 12, 11☑️  
   