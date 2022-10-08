/*Scrivere un programma in C, multi-writer.c, che deve considerare 3 parametri (strettamente
maggiori di 0): numero di processi (nchildren), numero di blocchi (nblocks) e dimensione del
blocco (blocksize). Il padre deve creare nchildren figli; ognuno dei figli deve scrivere, CON UNA
SINGOLA WRITE, un blocco di byte di dimensione blocksize per nblocks volte sullo standard
output. Una volta che tutti i figli abbiano terminato la scrittura (e quindi siano terminati), il padre
deve verificare che la lunghezza dello standard output sia uguale a quella attesa
(nblocks*blocksize). Provare il funzionamento del programma utilizzando esclusivamente la
ridirezione in output; si suggerisce la seguente invocazione
$ multi_writer 10 10000 1000 > log
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    /*int n; //numero di caratteri letti da read()
    char buffer[BUFSIZ]; //buffer di input
    int fd = 0;*/
    int pid,i,j,status;
    char *buffer;

    if (argc != 4){
        printf("Error! Wrong arguments number.\n");
        exit(1);
    }
    int nchildren = atoi(argv[1]);
    int nblocks = atoi(argv[2]);
    int blocksize = atoi(argv[3]);
    buffer = malloc(blocksize);

    for(i=0; i<nchildren; i++){
        if ((pid=fork()) < 0){
        	printf("Fork error!");
		    exit(4);
        }
        if(pid == 0){ //codice da eseguire solo nel processo figlio
            for(i=0; i<blocksize; i++) buffer[i] = 'a' + getpid() % 26;
            for(i=0; i<nblocks; i++) write(1, buffer, blocksize);
        }
    }
    
    for (j=0; j < nchildren; j++) 
    {
     	pid = wait(&status);
        /*if (pid < 0){
        	perror("Errore in wait\n");
            exit(5);
        }*/
    /*
        if ((status & 0xFF) != 0)
    	{
                sprintf(error, "Figlio con pid %d terminato in modo anomalo\n", pid);
	    	perror(error);
        }
        else
        { 
		ritorno=(int)((status >> 8) & 0xFF);
                sprintf(error,"Il figlio con pid=%d ha ritornato %d (se 255 problemi nel figlio)\n", pid, ritorno);
                perror(error);
        }*/
    }

    int expected =  blocksize * nblocks * nchildren;
    printf("La dimensione che dovrebbe essere: %d", expected);
    int calculated = lseek(1, 0, SEEK_END);
    printf("La dimensione invece è: %d", calculated);
}