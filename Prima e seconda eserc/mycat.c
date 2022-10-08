/*
 STANDARD INPUT ===> fd=0
 STANDARD OUTPUT ===> fd=1
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    int n; //numero di caratteri letti da read()
    char buffer[BUFSIZ]; //buffer di input
    int fd = 0;

    if (argc > 2){
        printf("Error! Too many arguments.\n");
        exit(1);
    }

    if (argc == 2){
        fd = open(argv[1], O_RDONLY);
        //printf("%d",fd);
    }
    
    //no parametri in input
    //while (1){
    while((n = read(fd, buffer, BUFSIZ)) > 0) write(1, buffer, n); //scrive su standard output il contenuto di buffer
        //exit(0);
        
        //write(1, buffer, strlen(buffer)); //scrive su standard output il contenuto di buffer
    //}
}