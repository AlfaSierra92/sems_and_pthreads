2022-10-17 08:55

1. Il modello dei processi ad ambiente globale:  
	a. rappresenta la naturale astrazione del funzionamento di un sistema multiprogrammato privo di memoria comune, nel quale si possono avere interazioni tra processi basate su cooperazione  
	b. rappresenta la naturale astrazione del funzionamento di un sistema multiprogrammato a memoria comune, nel quale si possono avere interazioni tra processi basate su competizione e cooperazione ☑️   
	c. rappresenta la naturale astrazione del funzionamento di un sistema multiprogrammato a memoria comune, nel quale si possono avere interazioni tra processi basate su cooperazione  
	d. rappresenta la naturale astrazione del funzionamento di un sistema multiprogrammato privo di memoria comune, nel quale si possono avere interazioni tra processi basate su competizione e cooperazione

2. Partendo dal presupposto che solitamente il modello ad ambiente globale viene implementato su un'architettura mono/multi processore, mentre il modello ad ambiente locale viene implementato su di un'architettura distribuita, è possibile anche:  
	a. implementare il modello ad ambiente locale su un'architettura mono/multi processore, ma non il modello ad ambiente globale anche su un'architettura distribuita  
	b. implementare il modello ad ambiente globale su un'architettura distribuita, ma non il modello ad ambiente locale su un'architettura mono/multi processore  
	c. non è possibile alcun tipo di implementazione alternativa  
	d. implementare il modello ad ambiente globale su un'architettura distribuita ed il modello ad ambiente locale su un'architettura mono/multi processor ☑️ 

3. In un Sistema Operativo che usa un modello dei processi ad ambiente locale, l'identificazione diretta simmetrica prevede che:
	a. il canale venga stabilito automaticamente fra la coppia di processi che desidera comunicare, che il canale sia associato ad una sola coppia di processi, e che sia bidirezionale☑️  
	b. il canale venga stabilito automaticamente fra la coppia di processi che desidera comunicare, che il canale sia associato ad una sola coppia di processi, e che sia unidirezionale  
	c. il canale venga stabilito automaticamente fra la coppia di processi che desidera comunicare, che il canale sia associato a più coppie di processi, e che sia bidirezionale  
	d. il canale venga stabilito automaticamente fra la coppia di processi che desidera comunicare, che il canale sia associato a più coppie di processi, e che sia unidirezionale

4. In un Sistema Operativo che usa un modello dei processi ad ambiente locale, cosa significa usare identificazione diretta asimmetrica nello scambio di messaggi fra un processo mittente S e un processo destinatario R?
	a. Che S deve bloccarsi fino a che R non ha ricevuto il messaggio spedito  
	b. Che S deve indicare il nome di R nella primitiva send e che, a sua volta, R deve indicare il nome di S nella primitiva receive  
	c. Che S si blocca fino a che R non ha inviato un messaggio speciale di acknowledgement  
	d. Che S deve indicare il nome di R nella primitiva send e che, invece, R può non indicare il nome di S nella primitiva receive ☑️ 

5. In un Sistema Operativo basato sul modello dei processi ad Ambiente Locale, quale meccanismo di sincronizzazione si deve usare per regolare le interazioni fra processi?  
	a. il meccanismo di semaforo (con wait e signal)  
	b. il meccanismo di lock/unlock  
	c. il meccanismo di monitor  
	d. il meccanismo dello scambio di messaggio/segnali ☑️ 

6. Facendo riferimento ad un generico problema di competizione in Ambiente Globale, che cosa significa usare un meccanismo di risveglio a cascata?
	a. Non significa nulla dato che non può esistere un meccanismo di risveglio a cascata.  	b. Significa che un processo segnalante risveglia un solo processo degli N che possono essere stati sospesi a causa sua, e poi il processo segnalato a sua volta risveglia un altro processo sospeso e così via. Tale meccanismo viene usato ad esempio nella soluzione del problema lettori-scrittori facendo uso del costrutto monitor. ☑️   
	c. Significa che un processo segnalato risveglia un solo processo degli N che possono essere stati sospesi a causa sua, e poi il processo segnalante a sua volta risveglia un altro processo sospeso e così via. Tale meccanismo viene usato ad esempio nella soluzione del problema lettori-scrittori facendo uso del costrutto monitor.  
	d. Significa che un processo, prima di sospendersi, risveglia un solo processo degli N che possono essere stati sospesi a causa sua, e poi il processo segnalato a sua volta risveglia un altro processo sospeso e così via. Tale meccanismo viene usato ad esempio nella soluzione del problema lettori-scrittori facendo uso del costrutto monitor.

7. In un Sistema Operativo che usa un modello dei processi ad ambiente locale, cosa significa 'rendez-vous' fra un processo mittente S e un processo destinatario R (che esegue sempre una receive bloccante)?  
	a. significa che siamo in presenza di bufferizzazione di canale e quindi che S usa una send sincrona e perciò deve aspettare l'esecuzione della receive da parte di R  
	b. significa che siamo in assenza di bufferizzazione di canale e quindi che S usa una send asincrona e perciò deve aspettare l'esecuzione della receive da parte di R  
	c. significa che siamo in assenza di bufferizzazione di canale e quindi che S usa una send sincrona e perciò deve aspettare l'esecuzione della receive da parte di R ☑️   
	d. significa che siamo in assenza di bufferizzazione di canale e quindi che S usa una send asincrona e perciò non deve aspettare l'esecuzione della receive da parte di R

8. Il costrutto Monitor viene tradotto dal compilatore in:
	a. Un semaforo MUTEX inizializzato a 0, un semaforo URGENT inizializzato a 0, e n semafori CONDSEM inizializzati a 0, dove n è il numero di variabili condizione del Monitor  
	b. Un semaforo MUTEX inizializzato a 1, un semaforo URGENT inizializzato a 0, e n semafori CONDSEM inizializzati a 0, dove n è il numero di variabili condizione del Monitor ☑️   
	c. Un semaforo MUTEX inizializzato a 0, un semaforo URGENT inizializzato a 0, e n semafori CONDSEM inizializzato a 1, dove n è il numero di variabili condizione del Monitor  
	d. Un semaforo MUTEX inizializzato a 1, un semaforo URGENT inizializzato a 0, e un semaforo CONDSEM inizializzato a 0

9. In un Sistema Operativo che usa un modello dei processi ad ambiente locale, quale è il principale svantaggio dell'identificazione diretta, sia simmetrica che asimmetrica?  
	a. lo svantaggio è la necessità  di avere un canale dedicato per ogni processo  
	b. lo svantaggio è la scarsa modularità ☑️   
	c. lo svantaggio è la unidirezionalità  del canale  
	d. lo svantaggio è di poter usare solo primitive sincrone

10. Il modello ad ambiente locale, per la gestione dell'interazione tra processi interagenti, prevede l'utilizzo di politiche basate su:  
	a. nessuna delle alternative presenti  
	b. competizione, ma non cooperazione  
	c. cooperazione, ma non competizione ☑️   
	d. cooperazione e competizione

11. Nel Sistema Operativo Unix, è possibile far comunicare due processi (creati con la primitiva fork) attraverso variabili condivise usando uno strumento tipo monitor?  
	a. No, perchè Unix non supporta operazioni tipo wait()/signal() per i semafori  
	b. No, perchè in Unix i processi non condividono memoria ☑️   
	c. Sì, se i due processi condividono un'area dati  
	d. Sì, se i due processi sono figli dello stesso padre

12. In un Sistema Operativo che usa un modello dei processi ad ambiente locale, l'identificazione indiretta prevede che:
	a. il canale venga stabilito automaticamente fra la coppia di processi che desidera comunicare, che il canale sia associato ad una sola coppia di processi, e che sia bidirezionale  
	b. il canale venga stabilito solo se la coppia di processi che desidera comunicare utilizza la stessa mailbox, che il canale possa essere associato a più coppie di processi, e che sia unidirezionale o bidirezionale ☑️   
	c. il canale venga stabilito automaticamente fra la coppia di processi che desidera comunicare, che il canale sia associato a più coppie di processi, e che sia bidirezionale  
	d. il canale venga stabilito automaticamente fra la coppia di processi che desidera comunicare, che il canale sia associato a più coppie di processi, e che sia unidirezionale

13. Nel Sistema Operativo Unix, di quante pipe c'è bisogno per fare in modo che due processi P1 e P2 (figli dello stesso padre) possano inviare una serie di informazioni al padre?  
	a. Sempre una sola pipe creata dal processo padre prima di creare i due processi figli P1 e P2 che viene usata da entrambi  
	b. nessuna delle alternative presenti  
	c. Sempre due pipe create dal processo padre prima di creare i due processi figli P1 e P2 
	d. Una sola pipe creata dal processo padre prima di creare i due processi figli P1 e P2 che viene usata da entrambi oppure due pipe create dal processo padre prima di creare i due processi figli P1 e P2, dipende dalle specifiche ☑️ 

14. Quale semantica viene utilizzata nel meccanismo primitivo di 'monitor' di Java?
	a. La semantica 'segnala e aspetta'  
	b. nessuna delle alternative presenti, dato che Java non implementa in modo primitivo il 'monitor'  
	c. La semantica 'segnala e continua' ☑️   
	d. In alcuni casi la semantica 'segnala e aspetta' e in altri la semantica 'segnala e continua'

15. Il modello ad ambiente locale:
	a. rappresenta la naturale astrazione del funzionamento di un sistema multiprogrammato a memoria comune, nel quale si possono avere interazioni tra processi basate su cooperazione  
	b. rappresenta la naturale astrazione del funzionamento di un sistema multiprogrammato a memoria comune, nel quale si possono avere interazioni tra processi basate su competizione e cooperazione  
	c. rappresenta la naturale astrazione del funzionamento di un sistema multiprogrammato privo di memoria comune, nel quale si possono avere interazioni tra processi basate su competizione e cooperazione  
	d. rappresenta la naturale astrazione del funzionamento di un sistema multiprogrammato privo di memoria comune, nel quale si possono avere interazioni tra processi basate su cooperazione ☑️ 

16. Nell'ambito della programmazione multiprocesso, il linguaggio C per UNIX può essere definito come:  
	a. Un linguaggio di programmazione sequenziale  
	b. Un linguaggio di programmazione non sequenziale ☑️   
	c. Un linguaggio di programmazione interpretato  
	d. Un linguaggio di programmazione concorrente

17. Nel Sistema Operativo Unix, di quante pipe c'è bisogno per fare in modo che due processi P1 e P2, figli dello stesso padre, possano scambiarsi una serie di informazioni da P1 a P2 e viceversa da P2 a P1?  
	a. Due pipe, ciascuna delle quali create da ognuno dei due processi figli P1 e P2, ognuna delle quali viene usata in modo unidirezionale  
	b. Due pipe create dal processo padre prima di creare i due processi figli P1 e P2 ognuna delle quali viene usata in modo unidirezionale ☑️   
	c. Una sola pipe creata dal processo padre prima di creare i due processi figli P1 e P2 che viene da essi usata in modo bidirezionale  
	d. Due pipe create dal processo padre subito dopo aver creato i due processi figli P1 e P2 ognuna delle quali viene usata in modo unidirezionale