/*
Scrivere un programma C padreEFiglioComunicanti1.c che, partendo dal programma 
padreEFiglioComunicanti.c della scorsa esercitazione (si veda il testo relativo), assuma un diverso 
protocollo di comunicazione che consideri la possibilità di scambiare linee/stringhe di lunghezza generica.
In particolare, il figlio, dopo aver letto una linea dal file passato come parametro (supposta non più lunga 
di 512 caratteri, compreso il terminatore di linea) [*], deve:
• trasformare tale linea in stringa (come in padreEFiglioComunicanti.c) 
• mandare per prima cosa la lunghezza della stringa al padre 
• mandare la stringa al padre (con una singola WRITE)
A quel punto il padre, per ogni linea letta dal figlio:
• riceve per prima cosa la lunghezza della stringa 
• deve usare questa informazione per leggere (con una singola READ) i caratteri che costituiscono 
la stringa
• deve poi stamparla analogamente al programma padreEFiglioComunicanti.c della scorsa 
esercitazione.
[*] NOTA BENE: per leggere una linea dal file, il figlio deve leggere un carattere alla volta dal file fino a 
che non incontra il carattere ‘\n’.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MSGSIZE 5

int main(int argc, char **argv){
    char buffer[MSGSIZE];
    int pid=0;
    int pipe_fd[2];
    int fd=0;
    int status;
    int read_count=0;

    if (argc > 2){
        printf("Error! Wrong arguments number.\n");
        exit(1);
    }
    if(pipe(pipe_fd)<0){
        exit(1);
    }
    if ((pid=fork()) < 0){
       	printf("Fork error!");
	    exit(4);
    }

    if(pid == 0){
        close(pipe_fd[0]); 	/* il figlio CHIUDE il lato di lettura: QUINDI SI CLASSIFICA COME SCRITTORE DELLA PIPE */
        fd = open(argv[1], O_RDONLY);
        if (fd<0) {
            printf("Error! File not exists.\n");
            perror("Error");
            exit(1);
        }
        while(read(fd, buffer, MSGSIZE) != 0){
            if(&buffer[0] == "\n") break;
            strcpy(&buffer[MSGSIZE-1],"\0");
            write(pipe_fd[1],buffer,5);
            read_count++;
        }
        printf("Il figlio ha letto %d volte\n",read_count);
    }

    close(pipe_fd[1]); 	/* il padrfe CHIUDE il lato di scrittura: QUINDI SI CLASSIFICA COME lettore DELLA PIPE */
    int pid_nipote = wait(&status);
    int father_read=0;
    while(read(pipe_fd[0], buffer, 5) != 0){
        write(1,buffer,5);
        father_read++;
    }
    if((status & 0xFF) == 0){
        printf("\nIl padre ha letto %d volte\n",father_read);
    }
    exit(0);
}