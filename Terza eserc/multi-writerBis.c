/*
Scrivere un programma C multi_writerBis.c che, partendo dal programma multi-writer1.c della prima
esercitazione (si veda il testo relativo), deve considerare solo 2 parametri: 
• numero di blocchi (nblocks, strettamente maggiore di 0)
• nome di un file.
Il padre deve:
• per prima cosa creare il file (che poi deve subito chiudere) 
• poi creare 10 figli
Ognuno dei figli deve 
• posizionarsi alla fine del file
• poi scrivere sul file il carattere numerico corrispondente al proprio numero d’ordine ripetendo 
questa scrittura per nblocks volte. 
Provare il funzionamento del programma, ad esempio con la seguente invocazione [*]:
$ multi_writerBis 100000 log
[*] NOTA BENE: non c’è alcuna garanzia che i 100000 caratteri scritti da ogni processo sul file siano ‘adiacenti’
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define PERM 0644

int main(int argc, char **argv){
    /*int n; //numero di caratteri letti da read()
    char buffer[BUFSIZ];*/ //buffer di input
    int fd = 0;
    int pid,i,j,status,ritorno;
    char *buffer;
    char error[200];

    if (argc != 3){
        printf("Error! Wrong arguments number.\n");
        exit(1);
    }
    //int nchildren = atoi(argv[1]);
    //int nblocks = atoi(argv[2]);
    int blocksize = atoi(argv[1]);
    buffer = malloc(blocksize);

    //creazione file da parte del padre
    fd = creat(fwrite, PERM);
    close(fd);
    for(i=0; i<10; i++){
        if ((pid=fork()) < 0){
        	printf("Fork error!");
		    exit(4);
        }
        if(pid == 0){ //codice da eseguire solo nel processo figlio
            //for(i=0; i<blocksize; i++) buffer[i] = 'a' + getpid() % 26;
            //for(i=0; i<nblocks; i++) write(1, buffer, blocksize);
            if ((fd = open(argv[2], O_WRONLY)) < 0 ){
        		perror("open");
			    exit(-1); /* torniamo -1 che sara' interpretato come errore (dato che se va tutto bene i figli tornano 0) */
        	}
            lseek(fd, 0L, SEEK_END);

            for(j=0;j<blocksize;j++){
                if(write(fd, i, 1) != 1){
                    perror("write");
			        exit(-1);
                }
            }
        }
    }
    
    for (j=0; j < 10; j++) 
    {
     	pid = wait(&status);
        if (pid < 0){
        	perror("Errore in wait\n");
            exit(5);
        }
    
        if ((status & 0xFF) != 0){
            sprintf(error, "Figlio con pid %d terminato in modo anomalo\n", pid);
	    	perror(error);
        } else { 
		ritorno=(int)((status >> 8) & 0xFF);
                sprintf(error,"Il figlio con pid=%d ha ritornato %d (se 255 problemi nel figlio)\n", pid, ritorno);
                perror(error);
        }
    }
    exit(0);
    /*int expected =  blocksize * nblocks * nchildren;
    printf("La dimensione che dovrebbe essere: %d", expected);
    int calculated = lseek(1, 0, SEEK_END);
    printf("La dimensione invece è: %d", calculated);*/
}