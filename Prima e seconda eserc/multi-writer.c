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