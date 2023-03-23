/*
Scrivere un programma C multi_writerBis-conSimulazioneSemaforo.c che, partendo dal programma 
precedente, vada ad implementare un semaforo di mutua esclusione (come visto a lezione, usando una 
pipe).
Tramite il semaforo di mutua esclusione si vada a proteggere, nel codice dei figli, la sezione critica
rappresentata dal posizionamento alla fine del file e dal ciclo di scrittura degli nblocks caratteri.
Provare il funzionamento del programma, ad esempio con la seguente invocazione [*]:
$ multi_writerBis-conSimulazioneSemaforo 100000 log1
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define PERM 0644

int main(int argc, char **argv){
    /*int n; //numero di caratteri letti da read()
    char buffer[BUFSIZ];*/ //buffer di input
    int fd = 0;
    int pipe_fd[2];
    int pid,i,j,status,ritorno;
    char *buffer;
    char error[200];
    char token;

    if (argc != 3){
        printf("Error! Wrong arguments number.\n");
        exit(1);
    }
    //int nchildren = atoi(argv[1]);
    //int nblocks = atoi(argv[2]);
    int blocksize = atoi(argv[1]);
    buffer = malloc(blocksize);

    //creazione file da parte del padre
    fd = creat(argv[2], PERM);
    close(fd);

    if(pipe(pipe_fd)<0){
        exit(1);
    }
    write(pipe_fd[1], &token, 1);

    for(i=0; i<3; i++){
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
            read(pipe_fd[0], &token, 1);
            lseek(fd, 0L, SEEK_END);

            for(j=0;j<blocksize;j++){
                char c = i + '0';
                if(write(fd, &c, 1) != 1){
                    perror("write");
			        exit(-1);
                }
            }
            write(pipe_fd[1], &token, 1);
        }
    }
    
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    for (j=0; j < 3; j++) 
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