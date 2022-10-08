#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    int n; //numero di caratteri letti da read()
    int fd = 0;
    int n_head = 0;
    char buffer; //buffer di input
    // una stringa è un array di caratteri, qui creo una variabile anzichè un array quindi un solo carattere
    
    switch (argc)
    {
    case 1:
        n_head = 10;
        break;
    
    case 2:
        if (argv[1][0] == '-'){
            char parametro[strlen(argv[1])-1]; //rimuovo il carattere - dal parametro
            for(int i=1;i<strlen(argv[1]);i++){ //appoggiandomi ad una variabile temporanea (parametro)
                parametro[i-1]=argv[1][i];
            }
            //n_head = argv[1][1] - '0'; //secondo carattere del secondo parametro passato
            n_head = atoi(parametro); //converto il numero in stringa in intero
        } else{
            n_head = 10;
            fd = open(argv[1], O_RDONLY); //se non c'è il trattino allora è il nome del file da aprire
            if (fd<0) printf("Error! File not exists.\n");
        }
        break;
    
    case 3:
        if (argv[1][0] == '-'){
            char parametro[strlen(argv[1])-1]; //rimuovo il carattere - dal parametro
            for(int i=1;i<strlen(argv[1]);i++){ //appoggiandomi ad una variabile temporanea (parametro)
                parametro[i-1]=argv[1][i];
            }
            n_head = atoi(parametro); //converto il numero in stringa in intero
            fd = open(argv[2], O_RDONLY); //apro il file dato come secondo parametro
        } else{
            n_head = 10;
            fd = open(argv[1], O_RDONLY); //se passo due file come parametri, apre solo il primo
            if (fd<0) printf("Error! File not exists.\n");
        }        
        break;

    default:
        printf("Error!\n");
        break;
    }

    int i = 1;
    while(read(fd, &buffer, 1) != 0) {
        if (buffer == '\n') i++;     /* se troviamo un terminatore di linea incrementiamo il conteggio */
        write(1, &buffer, 1);        /* scriviamo comunque il carattere qualunque sia */
        if (i > n_head) break;       /* se il conteggio supera n allora usciamo dal ciclo di lettura */
        // ricorda che alla write (ma anche alla read) va passato il buffer come parametro per riferimento e non per valore;
        // di norma, essendo un array di caratteri, viene passato in maniera predefinita
        // tranne in questo caso che, essendo un singolo carattere, non è un array quindi non viene passato in automatico
    }

}