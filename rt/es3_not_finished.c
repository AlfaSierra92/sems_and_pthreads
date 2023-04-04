#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 8

sem_t mutex;
sem_t full;
sem_t empty;

typedef struct busta_t{
    char messaggio;
    int priority;
}busta;

