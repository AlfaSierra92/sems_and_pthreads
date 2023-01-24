1. La primitiva CREATE prima di terminare ...
    a. prevede l'invocazione della primitiva OPEN in lettura e scrittura
    b. prevede l'invocazione della primitiva OPEN in lettura
    c. prevede l'invocazione della primitiva OPEN in scrittura☑️
    d. prevede l'invocazione della primitiva OPEN in append

2. In UNIX, la cancellazione di un file implica:
    a. la cancellazione delle informazioni dalla DBF (e quindi dell'I-NODE) e la liberazione dell'I-NODE; per tale ragione, non si riesce a recuperare un file cancellato.
    b. invalidazione delle informazioni nella DNF (nome file e I-NUMBER), la cancellazione delle informazioni dalla DBF (e quindi dell'I-NODE) e la liberazione dell'I-NODE; per tale ragione, si riesce a recuperare un file cancellato.
    c. la cancellazione delle informazioni dalla DNF (nome file e I-NUMBER) e la liberazione dell'I-NODE; per tale ragione, non si riesce a recuperare un file cancellato.☑️
    d. la cancellazione delle informazioni dalla DNF (nome file e I-NUMBER), la cancellazione delle informazioni dalla DBF (e quindi dell'I-NODE) e la liberazione dell'I-NODE; per tale ragione, non si riesce a recuperare un file cancellato.

3. In UNIX, il File Descriptor (fd) tornato dalla primitiva OPEN/CREAT rappresenta:
    a. l'indice della Tabella dei File Aperti (TFA) di sistema
    b. l'indice della Tabella dei File Aperti (TFA) del singolo processo☑️
    c. l'indice della Tabella dei File Attivi (TFA) di sistema
    d. il nome del File Control Block

4. In UNIX, nella primitiva CREAT si ha la seguente gestione di alcuni dei possibili errori:
    a. nel caso esista già un file con quel nome, se i diritti lo consentono, sovrascrive il contenuto e nel caso non esista un I-NODE libero nel File System fisico produce un errore☑️
    b. nel caso esista già un file con quel nome chiede all'utente il permesso di sovrascrivere il contenuto e nel caso non esista un I-NODE libero nel File System fisico produce un errore
    c. nel caso esista già un file con quel nome, se i diritti lo consentono, sovrascrive il contenuto e nel caso non esista un I-NODE libero nel File System fisico ne crea uno nuovo
    d. nel caso esista già un file con quel nome chiede all'utente il permesso di sovrascrivere il contenuto e nel caso non esista un I-NODE libero nel File System fisico ne crea uno nuovo

5. In un Sistema Operativo Unix, i dispositivi logici, ovvero stdin, stdout e stderr:
    a. non vengono considerati come file
    b. vengono considerati come file, ed occupano le ultime tre posizioni della Tabella dei File Aperti di ogni processo
    c. vengono considerati come file, ed occupano le prime tre posizioni della Tabella dei File Aperti di ogni processo☑️
    d. vengono considerati come file, ed occupano le prima tre posizioni della Tabella dei File Aperti di sistema

6. Nel Network File System (NFS) come si ottiene che stazioni eterogenee operino utilizzando un modello client-server?
    a. Si ottiene tramite l'uso di Remote Method Invocation (RMI) di Java
    b. Si ottiene tramite l'uso di Remote Procedure Call (RPC) e del protocollo XDR☑️
    c. Si ottiene tramite l'uso di chiamate asincrone fra dal client al server
    d. Si ottiene tramite l'uso di una stazione che funge da unico server per tutti le altre stazioni connesse

7. L'effetto della primitiva OPEN, se ha successo, è:
    a. inserimento della copia del descrittore del file e di altre informazioni nella tabella dei File Aperti (TFA) del processo
    b. inserimento della copia del descrittore del file nella tabella dei File Attivi di Sistema (se non già presente; se presente aggiornamento del contatore d'uso) 
    c. inserimento della copia del descrittore del file nella tabella dei File Attivi di Sistema (se non già presente; se presente aggiornamento del contatore d'uso) e inserimento di informazioni nella tabella dei File Aperti di sistema 
    d. inserimento della copia del descrittore del file nella tabella dei File Attivi di Sistema (se non già presente; se presente aggiornamento del contatore d'uso) e inserimento delle necessarie informazioni nella tabella dei File Aperti (TFA) del processo☑️

8. Nella primitiva OPEN, il connection-ID viene chiamato:
    a. sempre File Descriptor (fd) 
    b. sempre File Handle
    c. sempre File Control Block
    d. File Descriptor (fd) in UNIX e File Handle in MS-DOS☑️

9. In UNIX, la primitiva CREAT in caso di successo:
    a. usa un I-NODE con i 13 indirizzi che puntano a blocchi, i primi 10 per i dati e gli ultimi 3 per indici, e il file aperto in scrittura
    b. usa un I-NODE con tutti e 13 gli indirizzi a NIL e il file aperto in scrittura☑️
    c. usa un I-NODE con tutti e 13 gli indirizzi a NIL e il file aperto in append
    d. usa un I-NODE con il primo indirizzo che punta ad un blocco di dati e gli altri 12 gli indirizzi a NIL e il file aperto in scrittura

10. In un Sistema Operativo Unix, le prime tre posizioni della Tabella dei File Aperti di ogni processo sono solitamente occupate:
    a. dai file utilizzati più frequentemente, in modo da velocizzarne l'accesso in futuro
    b. dai dispositivi logici, ovvero stdin, stdout e stderr☑️
    c. dai file di sistema necessari per il corretto funzionamento del processo stesso
    d. dai file utilizzati più recentemente, in modo da velocizzarne l'accesso in futuro

11. Nella primitiva lseek di UNIX, il ruolo della posizione logica presente a livello generale viene svolto da:
    a. offset rispetto all'inizio file.
    b. origine dello spostamento (che può essere inizio file, posizione corrente file pointer o fine del file) e offset rispetto a tale origine.☑️
    c. origine dello spostamento (che può essere inizio file o fine del file) e offset rispetto a tale origine.
    d. origine dello spostamento (che può essere inizio file o posizione corrente file pointer) e offset rispetto a tale origine.

12. Nel Sistema Operativo Unix, a cosa serve il dispositivo /dev/tty?
    a. Serve per 'scartare' output non interessante
    b. Serve per sapere a quale dispositivo è collegato lo standard output
    c. Serve per sapere quale dispositivo è collegato allo standard input
    d. Serve per forzare lo standard output sul terminale corrente☑️

13. La chiusura dei file può essere automatica alla terminazione di un processo?
    a. Sì in generale, ma in UNIX invece deve essere prevista esplicitamente altrimenti le strutture dati di sistema, Tabella dei File Aperti e Tabella dei File Attivi, rimangono inconsistenti.
    b. No.
    c. Sì, come avviene ad esempio in UNIX.☑️
    d. Sì, ma solo se livello sistemistico si imposta questa opzione.

14. Cosa sono e a cosa servono le System Call?
    a. Le System Call (o SYSCALL o chiamate di sistema) sono semplici funzioni di libreria.
    b. Le System Call (o SYSCALL o chiamate di sistema) sono funzioni implementate nel S.O. che possono essere usate dai processi in user space e servono come interfaccia per semplificare l’uso delle risorse Hw da parte dei processi, assicurando la sicurezza del sistema dato che sono eseguite in kernel mode.☑️
    c. Le System Call (o SYSCALL o chiamate di sistema) sono speciali istruzioni macchina.
    d. Le System Call (o SYSCALL o chiamate di sistema) sono funzioni implementate nel S.O. che possono essere usate dai processi solo dopo che sono passati in kernel mode.

15. Nelle primitive di READ e WRITE riferite ai file quali sono i vantaggi di usare buffer interni (cioè disk/buffer cache)?
    a. I vantaggi sono che si possono ridurre le operazioni di I/O in caso di operazioni asincrone.
    b. I vantaggi sono che si possono ridurre le operazioni di I/O sempre nella READ, mentre nella WRITE in caso di operazioni asincrone.☑️
    c. Ci sono vantaggi solo usando una disk/buffer cache unificata con la page cache.
    d. I vantaggi sono che si possono ridurre le operazioni di I/O.

16. Nel Sistema Operativo Unix, a cosa serve il dispositivo /dev/null?
    a. Serve per forzare lo standard output sul terminale corrente
    b. Serve per sapere a quale dispositivo è collegato lo standard output
    c. Serve per 'scartare' output non interessante☑️
    d. Serve per sapere quale dispositivo è collegato allo standard input

17. Quale differenze sostanziali ci sono fra una System Call e una chiamata di funzione?
    a. Le differenze sostanziali sono che l’indirizzo delle System Call è presente in una tabella del kernel e che durante la chiamata di una syscall il processore entra in Kernel Mode.☑️
    b. Non ci sono differenze sostanziali.
    c. C'è una sola differenza sostanziale che è data dal fatto che durante la chiamata di una syscall il processore entra in Kernel Mode.
    d. C'è una sola differenza sostanziale che è data dal fatto che l’indirizzo delle System Call è presente in una tabella del kernel.
