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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    char buffer[5];
    int pid=0;
    int pipe_fd[2];
    int fd=0;
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
        fd = open(argv[1], O_RDONLY);
        if (fd<0) {
            printf("Error! File not exists.\n");
            perror("Error");
            exit(1);
        }
        while(read(fd, buffer, 5) != 0){
            strcpy(&buffer[4],"\0");
            write(pipe_fd[1],buffer,5);
            read_count++;
        }
        printf("Ho letto %d volte\n",read_count);
    }

    while(read(pipe_fd[0], buffer, 5) != 0){
            //buffer[4]="\0";
            write(1,buffer,5);

    }
}