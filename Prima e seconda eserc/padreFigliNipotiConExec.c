/*Scrivere un programma padreFigliNipotiConExec.c che deve prevedere un numero variabile N di 
parametri (con N maggiore o uguale a 3, da controllare) che rappresentano nomi di file (F1, F2. ... FN). Il 
processo padre deve generare N processi figli (P0, P1, … PN-1): i processi figli Pi (con i che varia da 0 a N1) sono associati agli N file Ff (con f = i+1). Ogni processo figlio Pi deve, per prima cosa, creare un file FOut
il cui nome deve risultare dalla concatenazione del nome del file associato Ff con la stringa “.sort”. Quindi, 
ogni processo figlio Pi deve creare a sua volta un processo nipote PPi: ogni processo nipote PPi esegue 
concorrentemente e deve ordinare il file Ff secondo il normale ordine alfabetico usando in modo 
opportuno il filtro sort di UNIX/Linux riportando il risultato di tale comando sul file FOut.
Al termine, ogni processo nipote PPi deve ritornare al figlio il valore ritornato dal comando sort (in caso 
di insuccesso nella esecuzione del sort deve essere tornato il valore -1) e, a sua volta, ogni processo figlio 
Pi lo deve ritornare al padre. Il padre deve stampare, su standard output, i PID di ogni figlio con il 
corrispondente valore ritornato.
*/
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
            fwrite=malloc(sizeof(argv[i+1])+6); //creo una nuova stringa a cui aggiungerò il suffisso .sort
            strcpy(fwrite,argv[i+1]); //copio il contenuto di argv[i+1] in essa (il nome del file)
            strcat(fwrite,".sort"); //e aggiungo il prefisso
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