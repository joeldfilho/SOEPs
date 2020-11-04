#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define FOME 1
#define COMER 2
#define left (nFilosofo + 4) % 5
#define right (nFilosofo + 1) % 5

void *filosofo(void *quantidade);
void pegaGarfo(int);
void deixaGarfo(int);
void inicio(int);

sem_t mutex;
sem_t Semaforo[5];
int estado[5];
int nFilosofo[5]={0, 1, 2, 3, 4};

void *filosofo(void *quantidade) {
    while(FOME) {
        int *i = quantidade;
        sleep(rand() % 10 + COMER);
        pegaGarfo(*i);
        sleep(rand() % 10 + FOME);
        deixaGarfo(*i);
    }
}
void pegaGarfo(int nFilosofo) {
    sem_wait(&mutex);
    estado[nFilosofo] = FOME;
    printf("Filosofo %d esta com fome.\n", nFilosofo + 1);
    inicio(nFilosofo);
    sem_post(&mutex);
    sem_wait(&Semaforo[nFilosofo]);
    sleep(FOME);
}
void deixaGarfo(int nFilosofo) {
    sem_wait(&mutex);
    estado[nFilosofo] = 0;
    printf("Filosofo %d deixou os garfos %d e %d.\n", nFilosofo + 1, left + 1, nFilosofo + 1);
    printf("Filosofo %d esta pensando.\n", nFilosofo + 1);
    inicio(left);
    inicio(right);
    sem_post(&mutex);
}
void inicio(int nFilosofo) {
    if(estado[nFilosofo] == FOME && estado[left] != COMER && estado[right] != COMER) {
        estado[nFilosofo]= COMER;
        sleep(COMER);
        printf("Filosofo %d pegou os garfos %d e %d.\n", nFilosofo + 1, left + 1, nFilosofo + 1);
        printf("Filosofo %d esta comendo.\n", nFilosofo + 1);
        sem_post(&Semaforo[nFilosofo]);
    }
}
int main() {
    int i, j, k;
    pthread_t thread_id[5];
    sem_init(&mutex, 0, 1);
    for(i = 0; i < 5; i++) {
        sem_init(&Semaforo[i], 0, 0);
    }
    for(j = 0; j < 5; j++) {
        pthread_create(&thread_id[j], NULL, filosofo, &nFilosofo[j]);
        printf("Filosofo %d esta pensando.\n", j + 1);
    }
    for(k = 0; k < 5; k++) {
        pthread_join(thread_id[k],NULL);
    }
    return 0;
}
