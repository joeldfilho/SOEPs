#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

static int count = 0;
static int vez = 0;
pthread_mutex_t mutexCount;


void secaoCritica(){
    pthread_mutex_lock(& mutexCount);
    count++;
    printf("Count = %i. \n", count);
    pthread_mutex_unlock(& mutexCount);
}

void *p0 (){
    int meuId = 0;
    int outro = 1;
    int abacates = 0;
    while(count < MAX){
        while(vez != meuId){
            abacates++;
        }

        secaoCritica();
        vez = outro;
        printf("Eu tenho %i abacates \n", abacates);

    }
}

void* p1(){
    int meuId = 1;
    int outro = 0;
    int bananas = 0;
    while(count < MAX){
        while(vez != meuId){
            bananas++;
        }
        secaoCritica();
        vez = outro;
        printf("Eu tenho %i bananas! \n", bananas);
        
    }
}

int main(){
    pthread_t id1;
    pthread_create(&id1, NULL, p0, NULL);

    pthread_t id2;
    pthread_create(&id1, NULL, p1, NULL);
    
    int vezes = 0;
    


    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    return 0;
}