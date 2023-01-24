2022-11-26

1. In un Sistema Operativo generale che preveda lo scheduler di medio termine, tale scheduler su quale coda agisce?  
    a. Sulla coda dei processi swapped☑️  
    b. Sulla coda dei lavori batch  
    c. Sulla coda dei processi pronti  
    d. Sulle code dei processi sospesi  

2. Facendo riferimento allo scheduler di breve termine di un Sistema Operativo, che cosa di intende per preemption?  
    a. la situazione in cui il processo a cui è stata assegnata la CPU ne mantiene il possesso fino a che non decide volontariamente di sospendersi oppure termina  
    b. la situazione in cui al processo in esecuzione viene sempre sottratta la CPU  
    c. la situazione in cui il processo a cui è stata assegnata la CPU ne mantiene il possesso fino a che termina  
    d. la situazione in cui al processo in esecuzione può essere sottratta la CPU in specifiche situazioni☑️  

3. Facendo riferimento all'algoritmo di scheduling con code multiple e retroazione, è possibile affermare che:  
    a. la coda a priorità più alta viene gestita tramite l'algoritmo Round-Robin, mentre quella a priorità più bassa tramite l'algoritmo SJF  
    b. ogni processo, all'atto della sua creazione, viene inserito nella coda a priorità più alta☑️  
    c. la coda a priorità più alta viene gestita tramite l'algoritmo Round-Robin, mentre quella a priorità più bassa tramite l'algoritmo SRTN  
    d. ogni processo, all'atto della sua creazione, viene inserito nella coda a priorità più bassa  

4. In un Sistema Operativo generale, il concetto di scheduling:  
    a. può essere derivato dal concetto di coda di priorità  
    b. può essere associato a più risorse del sistema☑️  
    c. è proprio della CPU  
    d. descrive il meccanismo utilizzato per passare il controllo della CPU ad un processo  

5. Nell'algoritmo di scheduling Round-Robin, il valore del quanto di tempo Q come deve essere?  
    a. il valore di Q deve essere minore del tempo di process switching  
    b. il valore di Q deve essere maggiore del tempo di ricircolo  
    c. il valore di Q deve essere maggiore del tempo di process switching☑️  
    d. il valore di Q deve essere minore del tempo di ricircolo  

6. Facendo riferimento agli algoritmi di scheduling di un Sistema Operativo generale, è possibile affermare che:  
    a. l'algoritmo SJF può presentare casi di starvation, ma non l'algoritmo SRTN  
    b. l'algoritmo SRTN può presentare casi di starvation, ma non l'algoritmo SJF  
    c. entrambi gli algoritmi SJF e SRTN possono presentare casi di starvation☑️  
    d. l'algoritmo SJF è di tipo preemptive  

7. In un Sistema Operativo su una architettura monoprocessore, durante l'utilizzo di un algoritmo di scheduling di tipo preemptive, può capitare che il processo in esecuzione, nell'istante in cui viene esercitata la prelazione, stia eseguendo una primitiva, e quindi ad esempio modificando strutture dati del nucleo. La sua interruzione potrebbe portare pertanto il sistema in uno stato inconsistente. Per evitare questa situazione, è possibile:  
    a. disabilitare le interruzioni durante l'esecuzione delle primitive☑️  
    b. non effettuare prelazione fino allo scadere del quanto di tempo  
    c. raddoppiare la durata del quanto di tempo  
    d. nessuna delle alternative presenti  

8. In un Sistema Operativo su una architettura multiprocessore, durante l'utilizzo di un algoritmo di scheduling di tipo preemptive, può capitare che il processo in esecuzione, nell'istante in cui viene esercitata la prelazione, stia eseguendo una primitiva, e quindi ad esempio modificando strutture dati del nucleo. La sua interruzione potrebbe portare pertanto il sistema in uno stato inconsistente. Per evitare questa situazione, è possibile:  
    a. disabilitare le interruzioni durante l'esecuzione delle primitive  
    b. non effettuare prelazione fino al completamento delle operazioni☑️  
    c. non effettuare prelazione fino allo scadere del quanto di tempo  
    d. nessuna delle alternative presenti  

9. In un Sistema Operativo generale, un thread:  
    a. non richiede il process switching  
    b. è l'insieme delle unità di esecuzione che condividono codice e dati  
    c. condivide codice e dati con altre unità di esecuzione appartenenti allo stesso task☑️  
    d. si ispira al modello locale  

10. Facendo riferimento ai parametri di valutazione per lo scheduler di breve termine, teoricamente si dovrebbe:  
    a. massimizzare lo sfruttamento della CPU ed il lavoro utile, e minimizzare il tempo di attesa, il tempo di ricircolo e il tempo di risposta☑️  
    b. minimizzare il tempo di ricircolo ed il tempo di attesa, e massimizzare lo sfruttamento della CPU, il tempo di risposta e il lavoro utile  
    c. minimizzare il tempo di ricircolo, il tempo di attesa ed il lavoro utile, e massimizzare lo sfruttamento della CPU  
    d. massimizzare lo sfruttamento della CPU, il tempo di risposta ed il lavoro utile, e minimizzare il tempo di ricircolo  

11. In un Sistema Operativo multiprocesso, quale ruolo svolge il Dispatcher?  
    a. Esegue lo scheduling dei processi, quando lo scheduler è occupato  
    b. Effettua il cambio di processo, fa transitare da modo supervisore a utente e infine salta alla giusta posizione del programma utente☑️  
    c. Esegue lo scheduling dei processi  
    d. Effettua solo il cambio di processo  

12. Facendo riferimento ai parametri di valutazione per lo scheduler di breve termine, il tempo di attesa risulta essere:  
    a. nessuna delle alternative presenti  
    b. sempre maggiore del tempo di ricircolo  
    c. il tempo totale trascorso dal processo nello stato "in esecuzione"  
    d. il tempo totale trascorso dal processo nella coda dei processi pronti☑️  

13. Facendo riferimento ai parametri di valutazione per lo scheduler di breve termine, il tempo di ricircolo risulta essere:  
    a. nessuna delle alternative presenti  
    b. il tempo totale impiegato dal processo per la sua intera esecuzione☑️  
    c. il tempo totale trascorso dal processo nella coda dei processi pronti  
    d. sempre minore del tempo di attesa  

14. In un Sistema Operativo generale, quali sono gli algoritmi di scheduler che prevedono preemption?  
    a. SRTN (Shortest Remaining Time Next) e RR (Round Robin)  
    b. SRTN (Shortest Remaining Time Next), RR (Round Robin) e quelli con code multiple (senza o con retroazione)☑️  
    c. FCFS (First Come First Served) e SJF (Shortest Job First)  
    d. Tutti quelli a priorità  

15. In un Sistema Operativo generale, un thread viene definito come:  
    a. un'unità di esecuzione che condivide la CPU con altri thread correlati  
    b. un'unità di esecuzione che condivide solamente i dati con altri thread correlati  
    c. un'unità di esecuzione che condivide solamente il codice con altri thread correlati  
    d. un'unità di esecuzione che condivide codice e dati con altri thread correlati☑️  

16. Facendo riferimento ai parametri per la valutazione delle prestazioni degli scheduler, in particolare di breve termine, cosa si intende per "lavoro utile o throughput" ?  
    a. Percentuale del tempo di CPU durante il quale la CPU è impegnata  
    b. Percentuale del tempo di CPU durante il quale la CPU è idle  
    c. Numero di processi completati per unità di tempo☑️  
    d. Percentuale del tempo di CPU durante il quale la CPU è impegnata  

17. In un Sistema Operativo quale transizione di stato non può avvenire se si usa un algoritmo di Scheduling di tipo non preemptive?  
    a. attesa/pronto  
    b. pronto/esecuzione  
    c. esecuzione/pronto☑️  
    d. esecuzione/attesa  

18. Se un Sistema Operativo vuole garantire un ragionevole tempo di risposta a tutti i processi, indipendentemente dalle loro caratteristiche, quale fra le seguenti politiche di scheduling è la più adeguata ?  
    a. FIFO  
    b. A priorità non preemptive  
    c. A priorità preemptive  
    d. Round Robin☑️  

19. Facendo riferimento ai parametri per la valutazione delle prestazioni degli scheduler, in particolare di breve termine, cosa si intende per 'sfruttamento della CPU (utilizzo della CPU)'?  
    a. Numero di processi completati per unità  di tempo  
    b. Percentuale del tempo di CPU durante il quale la CPU è impegnata☑️  
    c. Percentuale del tempo di CPU durante il quale la CPU è idle  
    d. Quanto ci mette un processo per essere completato  

20. Facendo riferimento ai parametri di valutazione per lo scheduler di breve termine, nei sistemi interattivi, si dovrebbe:  
    a. cercare di ottenere valori medi accettabili per ogni parametro, minimizzando la varianza del tempo di ricircolo  
    b. cercare di ottenere valori medi accettabili per ogni parametro, minimizzando la varianza del tempo di risposta☑️  
    c. cercare di ottenere valori medi accettabili per ogni parametro, massimizzando la varianza del tempo di ricircolo  
    d. cercare di ottenere valori medi accettabili per ogni parametro, massimizzando la varianza del tempo di risposta  

21. In un Sistema Operativo generale che preveda lo scheduler di lungo termine, tale scheduler cosa influenza?  
    a. Dato che seleziona i job da caricare in memoria centrale, influenza il numero di processi CPU bound attivi  
    b. Dato che seleziona i job da caricare in memoria centrale, influenza il numero di processi attivi  
    c. Dato che seleziona i job da caricare in memoria centrale, influenza il grado di multiprogrammazione☑️  
    d. Dato che seleziona i job da caricare in memoria secondaria, influenza il grado di multiprogrammazione  

22. In un Sistema Operativo multiprogrammato con quale ennupla può essere espresso un processo (pesante)?  
    a. {PC, registri, codice, dati, ...}  
    b. {PC, registri, stack, ...}  
    c. {PC, codice, dati, stack, ...}  
    d. {PC, registri, codice, dati, stack, ...}☑️  

23. In un Sistema Operativo multithreading, qual è la caratteristica dei thread (processi leggeri)?  
    a. Condivisione dei descrittori dei thread  
    b. Dimensione limitata del codice  
    c. Costo limitato del process/context switching unito a uso di memoria condivisa☑️  
    d. Gestione sempre a livello utente  

24. In un Sistema Operativo multithreading con quale ennupla può essere espresso un task?  
    a. {thread1, thread2, ..., threadN, codice, dati, stack}  
    b. {thread1, thread2, ..., threadN, dati}  
    c. {thread1, thread2, ..., threadN, codice, dati}☑️  
    d. {thread1, thread2, ..., threadN}  

25. In un Sistema Operativo multithreading con quale ennupla può essere espresso un processo leggero cioè un thread?  
    a. {PC, registri, codice, dati, ...}  
    b. {PC, registri, stack, ...}☑️  
    c. {PC, codice, dati, stack, ...}  
    d. {PC, registri, codice, dati, stack, ...}  

26. Facendo riferimento agli algoritmi di scheduling di un Sistema Operativo, l'algoritmo di tipo Event-Driven:  
    a. associa sempre valori numerici bassi ad alti livelli di priorità  
    b. prevede sempre 8 livelli di priorità  
    c. associa sempre valori numerici alti ad alti livelli di priorità  
    d. può presentare fenomeni di starvation☑️  

27. Facendo riferimento allo scheduler di breve termine di un Sistema Operativo, la preemption può sempre essere prevista e quindi implementata?  
    a. sì, ma su certe architetture può essere complicato implementarla  
    b. sì, ma su certe architetture bisogna che sia implementata a livello utente e non di Sistema Operativo  
    c. sì, dato che viene implementata solo a livello Sw  
    d. no, dipende dall'architettura☑️  

28. In un Sistema Operativo generale che preveda lo scheduler di lungo termine, tale scheduler su quale coda agisce?  
    a. Sulla coda dei lavori batch☑️  
    b. Sulle code dei processi sospesi  
    c. Sulla coda dei processi pronti  
    d. Sulla coda dei processi swapped  

29. Facendo riferimento agli algoritmi di scheduling di un Sistema Operativo generale, l'algoritmo FCFS presenta, dal punto di vista prestazionale:  
    a. basso sfruttamento della CPU, basso throughput ed elevati tempi di ricircolo☑️  
    b. basso sfruttamento della CPU e bassi tempi di ricircolo, ma alto throughput  
    c. alto sfruttamento della CPU, bassi tempi di ricircolo e basso throughput  
    d. alto sfruttamento della CPU, elevati tempi di ricircolo, e basso throughput  

30. In un Sistema Operativo quale transizione di stato può avvenire se si usa un algoritmo di Scheduling di tipo preemptive?  
    a. attesa/pronto  
    b. esecuzione/attesa  
    c. esecuzione/pronto☑️  
    d. pronto/esecuzione  

31. Nella progettazione di un algoritmo di scheduling, cosa si intende per CPU burst?  
    a. questo termine può essere utilizzato solo se un processo è CPU bound  
    b. si intende un quanto di tempo  
    c. si intende la fase in cui un processo effettua operazioni di I/O  
    d. si intende la fase in cui un processo usa solo la CPU☑️  
  