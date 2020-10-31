#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

/*
Cinco filósofos estão sentados em uma mesa, cada um com um prato de espaguete à sua frente. Entre os pratos existem 5 garfos para pegar macarrão
Cada filósofo precisa usar dois garfos para conseguir pegar o macarrão e se alimentar.
Os filósofos devem alternar entre duas atividades: comer e pensar.
Quando ele quer comer ele tenta pegar os garfos à sua direita e à sua esquerda, se conseguir ele come por um tempo e depois solta os garfos e volta a pensar.
os filósofos devem realizar suas duas atividades sem travar (ficar parados)
*/

//Para representar os garfos vou criar 5 mutex, pois os garfos serão nossa seção crítica (recurso compartilhado)
pthread_mutex_t garfo[5];

//Para representar a vida de cada filósofo será utilizada uma thread diferente
pthread_t filosofo[5];

//
int id[5];

void pegarGarfos(int * filosofo){
    pthread_mutex_lock(&(garfo[*filosofo]));
    if(*filosofo > 0){
        pthread_mutex_lock(&(garfo[*filosofo - 1]));
    }else{
        pthread_mutex_lock(&(garfo[4]));
    }
}

void soltarGarfos(int* filosofo){
    pthread_mutex_unlock(&(garfo[*filosofo]));
    if(*filosofo > 0){
        pthread_mutex_unlock(&(garfo[*filosofo - 1]));
    }else{
        pthread_mutex_unlock(&(garfo[4]));
    }

    printf("Filosofo %d terminou de comer. \n", *filosofo);
}


void * vidaFilosofo(void * var){
    while(TRUE){
        int * filosofo = (int*) (var);

        int pensar = (rand() %10 + 2);
        printf("Filosofo %d: pensando. \n", filosofo);
        sleep(pensar);

        pegarGarfos(filosofo);
        int tempoComendo =(rand()%10 + 3);
        printf("Filosofo %d comendo por %i segundos. \n", filosofo, tempoComendo);
        sleep(tempoComendo);
        soltarGarfos(filosofo);
    }
    pthread_exit(NULL);
}

int main(){
    for( int i = 0; i <= 4; i++){
        pthread_mutex_init(&(garfo[i]));
    }
    for(int j = 0; j <= 4; j++){
        id[j] = j;
        pthread_create(&filosofo[j], NULL, &vidaFilosofo, (void*)&id[j]);
    }

    while(TRUE){

    }
    return 0;
}
