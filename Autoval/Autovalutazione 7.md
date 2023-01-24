2022-11-09  

1. La fase di detection del deadlock del metodo a posteriori deve essere attivata:  
    a. ogni volta che una richiesta per una risorsa non può essere soddisfatta.  
    b. come caso limite ogni volta che una richiesta per una risorsa non può essere soddisfatta oppure quando l'utilizzo della CPU scende sotto una certa soglia.☑️  
    c. solo quando lo richiede l'utente.  
    d. solo quando l'utilizzo della CPU scende sotto una certa soglia.  

2. Facendo riferimento ai grafi di allocazione delle risorse, è possibile affermare che:  
    a. l'esistenza di un ciclo è condizione sufficiente per il verificarsi di situazioni di deadlock  
    b. l'esistenza di un ciclo è condizione necessaria e sufficiente per il verificarsi di situazioni di deadlock  
    c. l'esistenza di un ciclo è condizione necessaria per il verificarsi di situazioni di deadlock☑️  
    d. l'esistenza di un ciclo è condizione necessaria per il verificarsi di situazioni di starvation  

3. Facendo riferimento al metodo di prevenzione statica per il trattamento del deadlock, è possibile adottare determinate metodologie affinché non si verifichi almeno una delle condizioni necessarie; in particolare, il verificarsi di quale tra le seguenti condizioni è più facilmente evitabile?  
    a. attesa circolare☑️  
    b. trattenimento e attesa  
    c. mancanza di preemption  
    d. mutua esclusione  

4. Facendo riferimento ai metodi per il trattamento del deadlock, il meccanismo dei checkpoint viene utilizzato:  
    a. negli algoritmi di deadlock detection  
    b. negli algoritmi di prevenzione dinamica  
    c. nei metodi di deadlock recovery, che adottano soluzioni basate su terminazione dei processi  
    d. nei metodi di deadlock recovery, che adottano soluzioni basate su prelazione delle risorse☑️  

5. Se fossimo in uno stato non sicuro che cosa può succedere?  
    a. Il sistema potrebbe essere in deadlock☑️  
    b. Il sistema dovrebbe uccidere i processi che sono in deadlock  
    c. Il sistema, di conseguenza, sarebbe in deadlock  
    d. Il sistema potrebbe avere dei processi in starvation  

6. La fase di recovery del deadlock del metodo a posteriori implica:  
    a. sempre l'uccisione di uno o più processi coinvolti nel deadock.  
    b. l'uccisione di uno o più processi coinvolti nel deadock oppure la preemption delle risorse ad uno o più processi coinvolti nel deadock.☑️  
    c. sempre la preemption delle risorse ad uno o più processi coinvolti nel deadock.  
    d. l'uccisione di uno o più processi coinvolti nel deadock perchè questo consente la preemption delle risorse.  

7. Quante e quali condizioni devono essere verificare prima di poter applicare l'algoritmo del banchiere, supponendo che il processo Pk sottoponga al sistema la richiesta RICHIESTAk?  
    a. Le condizioni che devono essere soddisfatte sono 2 e sono:  
    RICHIESTAk < NECESSITÀk  
    RICHIESTAk < DISPONIBILI  
    b. La condizione che deve essere soddisfatta è solo 1 ed è:  
     
    c. Le condizioni che devono essere soddisfatte sono 2 e sono:  
    RICHIESTAk <= NECESSITÀk  
    RICHIESTAk <= DISPONIBILI☑️  
    d. Le condizioni che devono essere soddisfatte sono 2 e sono:  
    RICHIESTAk < NECESSITÀk  
    RICHIESTAk <= DISPONIBILI  

8. Facendo riferimento all'algoritmo del banchiere (metodo di prevenzione dinamica per il trattamento del deadlock) applicato a n processi e m tipi di risorse, è possibile affermare che:  
    a. l'algoritmo si basa su 4 strutture dati: il vettore DISPONIBILI (di dimensione n), la matrice NECESSITÀ_MAX (di dimensione mxn), la matrice ALLOCAZIONE (di dimensione mxn) e la matrice NECESSITÀ (di dimensione mxn).  
    b. l'algoritmo si basa su 3 strutture dati: il vettore DISPONIBILI (di dimensione m), la matrice ALLOCAZIONE (di dimensione nxm) e la matrice NECESSITÀ (di dimensione nxm).  
    c. l'algoritmo si basa su 3 strutture dati: la matrice NECESSITÀ_MAX (di dimensione nxm), la matrice ALLOCAZIONE (di dimensione nxm) e la matrice NECESSITÀ (di dimensione nxm).  
    d. l'algoritmo si basa su 4 strutture dati: il vettore DISPONIBILI (di dimensione m), la matrice NECESSITÀ_MAX (di dimensione nxm), la matrice ALLOCAZIONE (di dimensione nxm) e la matrice NECESSITÀ (di dimensione nxm).☑️  

9. Facendo riferimento ai metodi di prevenzione dinamica per il trattamento del deadlock, è possibile affermare che:  
    a. nessuna delle alternative presenti  
    b. se non si è in presenza di deadlock allora lo stato è sicuro  
    c. se lo stato è non sicuro allora si è in presenza di deadlock  
    d. se lo stato è sicuro allora esiste sicuramente almeno una sequenza sicura☑️  

10. In un Sistema Operativo Unix, il problema del deadlock per i processi utente viene risolto tramite:  
    a. l'utilizzo di algoritmi di detection and recovery, che adottano soluzioni basate su prelazione delle risorse  
    b. non viene trattato☑️  
    c. l'utilizzo di algoritmi di prevenzione dinamica  
    d. l'utilizzo di algoritmi di detection and recovery, che adottano soluzioni basate su terminazione dei processi  

11. In un Sistema Operativo generale ad ambiente locale, dati i processi P: { send(Q,msg); receive(Q,msg); } e Q: { send(P,msg); receive(P,msg); } supponendo che la primitiva receive sia sempre bloccante, è possibile incorrere in situazioni di deadlock in caso si utilizzino:  
    a. primitive send asincrone, e primitive send sincrone con limitata capacità di bufferizzazione  
    b. solo primitive send sincrone  
    c. primitive send sincrone, e primitive send asincrone con limitata capacità di bufferizzazione☑️  
    d. primitive send sincrone e asincrone  

12. Nel caso di grafi di allocazione delle risorse in cui ogni tipo di risorsa abbia una singola istanza è possibile affermare che:  
    a. l'esistenza di un ciclo è condizione necessaria e sufficiente per il verificarsi di situazioni di starvation  
    b. l'esistenza di un ciclo è condizione sufficiente per il verificarsi di situazioni di deadlock  
    c. l'esistenza di un ciclo è condizione sufficiente per il verificarsi di situazioni di starvation  
    d. l'esistenza di un ciclo è condizione necessaria e sufficiente per il verificarsi di situazioni di deadlock☑️  

13. Facendo riferimento alla fase di detection del deadlock (metodo a posteriori per il trattamento del deadlock) applicato a n processi e m tipi di risorse, è possibile affermare che:  
    a. l'algoritmo si basa su 2 strutture dati: il vettore DISPONIBILI (di dimensione n) e la matrice ALLOCAZIONE (di dimensione nxm).  
    b. l'algoritmo si basa su 3 strutture dati: il vettore DISPONIBILI (di dimensione n), la matrice ALLOCAZIONE (di dimensione mxn) e la matrice RICHIESTE (di dimensione mxn).  
    c. l'algoritmo si basa su 3 strutture dati: la matrice NECESSITÀ_MAX (di dimensione nxm), la matrice ALLOCAZIONE (di dimensione nxm) e la matrice NECESSITÀ (di dimensione nxm).  
    d. l'algoritmo si basa su 3 strutture dati: il vettore DISPONIBILI (di dimensione m), la matrice ALLOCAZIONE (di dimensione nxm) e la matrice RICHIESTE (di dimensione nxm).☑️  

14. Uno stato viene considerato sicuro nell'algoritmo del banchiere se:  
    a. almeno un processo che ha già ottenuto delle risorse è in grado di completare la propria esecuzione (caso migliore).  
    b. tutti i processi che hanno già ottenuto delle risorse sono in grado di completare la propria esecuzione, anche se ciascun processo intendesse usare tutte le risorse di cui ha bisogno contemporaneamente (caso migliore).  
    c. tutti i processi che non hanno già ottenuto delle risorse vegono fatti terminare forzatamente (caso peggiore).  
    d. tutti i processi che hanno già ottenuto delle risorse sono in grado di completare la propria esecuzione, anche se ciascun processo intendesse usare tutte le risorse di cui ha bisogno contemporaneamente (caso peggiore).☑️  

15. Quali sono gli svantaggi dell'algoritmo del banchiere?  
    a. Gli svantaggi sono 3:  
    bisogna conoscere le necessità massime di ogni processo;  
    presuppone che, in un certo istante, ogni processo richieda tutte le ulteriori risorse di cui ha bisogno e che le mantenga fino a che non ha terminato (caso peggiore);  
    molto pesante computazionalmente (m x n2 operazioni).☑️  
    b. Gli svantaggi sono 3:  
    bisogna conoscere le necessità minime di ogni processo;  
    presuppone che, in un certo istante, ogni processo richieda tutte le ulteriori risorse di cui ha bisogno e che le mantenga fino a che non ha terminato (caso peggiore);  
    molto pesante computazionalmente (m x n2 operazioni).  
    c. Gli svantaggi sono 2:  
    bisogna conoscere le necessità massime di ogni processo;  
    presuppone che, in un certo istante, ogni processo richieda tutte le ulteriori risorse di cui ha bisogno e che le mantenga fino a che non ha terminato (caso peggiore).  
    d. Gli svantaggi sono 2:  
    bisogna conoscere le necessità massime di ogni processo;  

16. In un Sistema Operativo generale, si possono verificare situazioni di deadlock:  
    a. nel caso di utilizzo di interazione indiretta, ma non diretta  
    b. nel caso si adotti un modello ad ambiente globale, ma non ad ambiente locale  
    c. nel caso di utilizzo di interazione diretta, ma non indiretta  
    d. nel caso di utilizzo di interazione diretta e indiretta☑️  

17. Facendo riferimento alle condizioni necessarie per il verificarsi di situazioni di deadlock, è possibile affermare che:  
    a. la condizione di "mutua esclusione" implica la condizione di "trattenimento e attesa"  
    b. la condizione di "mutua esclusione" implica la condizione di "attesa circolare"  
    c. la condizione di "attesa circolare" implica la condizione di "trattenimento e attesa"☑️  
    d. nessuna delle alternative presenti  