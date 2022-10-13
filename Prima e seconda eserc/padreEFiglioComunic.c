/*
Scrivere un programma in C, padreEFiglioComunicanti.c, che deve considerare un singolo parametro che 
deve essere il nome di file (F). Il padre deve creare un singolo figlio: il figlio deve leggere dal file F. Si deve 
garantire che F contenga per ogni linea 4 caratteri (oltre al terminatore di linea ‘\n’) e quindi la lettura 
potrà avvenire a 5 caratteri alla volta, CON UNA SINGOLA READ. Ogni volta che il figlio legge 5 caratteri
da F, deve trasformare questo array in una stringa (quindi il carattere ‘\n’ deve essere sostituito con il 
carattere ‘\0’) e tale stringa deve essere inviata al padre, CON UNA SINGOLA WRITE. Una volta terminata 
la lettura di tutto il file, il figlio riporta sullo standard output il numero di informazioni lette (e quindi 
inviate al padre) e termina riportando il valore di successo. Il padre deve ricevere tutte le stringhe inviate 
dal figlio e le deve riportare via via sullo standard output insieme con il numero d’ordine di tali stringhe 
(fatto partire da 0). Una volta terminata la lettura di tutte le stringhe, il padre deve riportare sullo standard 
output il numero totale di informazioni ricevute e quindi deve aspettare il figlio, riportando sullo standard 
output il valore ritornato dal figlio. Provare il funzionamento del programma creando un opportuno file 
di nome input.txt. Dopo avere provato una prima volta il funzionamento, modificare il contenuto del file 
input.txt, aggiungendo o togliendo informazioni, quindi provare di nuovo il funzionamento.
*/

