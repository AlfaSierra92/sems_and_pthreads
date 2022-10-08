#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define PERM 0644

int main(int argc, char **argv){
    int fd=0;
    int i;
    int n;
    int pid;
    int pid_nipote;
    char buffer[BUFSIZ];
    char error[BUFSIZ]; 
    char *fwrite;

    if (argc < 3){
        printf("Error! Wrong arguments number.\n");
        exit(1);
    }

    int nchildren = argc-1;

    for(i=0; i<nchildren; i++){
        if ((pid=fork()) < 0){
        	printf("Fork error!");
		    exit(4);
        }
        if(pid == 0){
            //processo figlio
            fwrite=malloc(sizeof(argv[i+1])+6);
            strcpy(fwrite,argv[i+1]);
            strcat(fwrite,".sort");
            fd = creat(fwrite, PERM);
            close(fd);

            if ((pid_nipote=fork()) < 0){
        	    printf("Fork error!");
		        exit(4);
            }
            if(pid_nipote == 0){
                //processo nipote
                close(0);
                if (open(argv[i+1], O_RDONLY)<0){ //file in lettura
                    sprintf(error, "Errore: FILE %s NON ESISTE\n", argv[i+1]);
				    perror(error);
                    exit(-1);
                } 
                
                close(1);
                if (open(fwrite, O_WRONLY)<0){ //file in scrittura
                    sprintf(error, "Errore: FILE NON si riesce ad aprire in scrittura\n");
				    perror(error);
                    exit(-1);
                } 

                execlp("sort","sort",(char *)0);

                perror("Problemi di esecuzione del sort da parte del nipote");
                exit(-1);
            }
        }
    }


}