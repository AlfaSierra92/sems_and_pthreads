/*
 Scrivere un programma padreFigliConConteggioOccorrenze.c che deve prevedere un numero variabile 
N+1 di parametri: i primi N (con N maggiore o uguale a 2, da controllare) che rappresentano N nomi di 
file (F1, F2. ... FN), mentre l’ultimo rappresenta un singolo carattere Cx (da controllare). Il processo padre 
deve generare N processi figli (P0, P1, … PN-1): i processi figli Pi (con i che varia da 0 a N-1) sono associati 
agli N file Ff (con f = i+1). Ogni processo figlio Pi deve leggere dal file associato contando le occorrenze del 
carattere Cx. 
Al termine, ogni processo figlio Pi deve ritornare al padre il numero di occorrenze (NOTA BENE: si può 
supporre minore di 255) e il padre deve stampare su standard output il PID di ogni figlio e il valore 
ritornato.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    int i;
    int fd = 0;
    int pid;
    char buffer; //buffer di input
    int occurrency = 0;
    int status, pidFiglio;

    if (argc == 1){
        printf("Error! Wrong arguments number.\n");
        exit(1);
    }
    if (strlen(argv[argc-1]) > 1){
        printf("Error! Wrong char inserted.\n");
        exit(1);
    }
    //char temp[] = argv[0];
    //char Cr = argv[argc-1][0];
    int nchildren = argc-2;
    //char Cx = malloc(sizeof(argv[argc-1]));
    char Cx = argv[argc-1][0];
    //printf("%c", Cx);

    for(i=0; i<nchildren; i++){
        if ((pid=fork()) < 0){
        	printf("Fork error!");
		    exit(4);
        }
        if(pid == 0){ //codice da eseguire solo nel processo figlio
            //char file=argv[i+1];
            //occurrency[i]=0;
            fd = open(argv[i+1], O_RDONLY);
            if (fd<0) {
                printf("Error! File not exists.\n");
                exit(1);
            }
            while(read(fd, &buffer, 1) != 0){
                //if(buffer == Cx) occurrency[i] = occurrency[i] + 1;
                if(buffer == Cx) occurrency = occurrency + 1;
            }
            //printf("Il numero %d e': %d", i, occurrency);
            exit(occurrency);
        }
    }
    
    for(i=0; i<nchildren; i++){
        pidFiglio = wait(&status); //nella variabile status vengono messe alcune informazioni sulla chiusura del processo
        if (pidFiglio < 0){
            printf("Errore in wait\n");
		    //perror(error);
            exit(4);
        }
        int prova = (status >> 8) & 0xFF;
        if ((status & 0xFF) != 0) printf("Figlio con pid %d terminato in modo anomalo\n", pidFiglio);
        else{
            int ritorno=(int)((status >> 8) & 0xFF);
            printf("Il figlio con pid=%d ha ritornato %d (se 255 problemi!)\n", pidFiglio, ritorno);
        }   
    }
}