#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>

void * rotina(void *arg);

int main(int argc, char *argv[]){
    pthread_t threadA;
    pthread_t threadB;
    pthread_t threadC;
    pthread_t threadD;
    pthread_t threadE;
    void *thread_res;
    int rstatus;

    /* Inicializa a thread A */
    rstatus = pthread_create(&threadA, NULL,rotina,(void*)("Thread A"));

    /* Se o status for diferente de 0 houve algum erro na craição da thread*/
    if(rstatus != 0){
        printf("Erro ao criar thread \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread A criada com sucesso");

    /* Inicializa a thread B */
    rstatus = pthread_create(&threadB, NULL,rotina,(void*)("Thread B"));

    /* Se o status for diferente de 0 houve algum erro na craição da thread*/
    if(rstatus != 0){
        printf("Erro ao criar thread \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread B criada com sucesso. \n");

    /* Inicializa a thread C */
    rstatus = pthread_create(&threadC, NULL,rotina,(void*)("Thread C"));

    /* Se o status for diferente de 0 houve algum erro na craição da thread*/
    if(rstatus != 0){
        printf("Erro ao criar thread \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread C criada com sucesso. \n");

    /* Inicializa a thread D */
    rstatus = pthread_create(&threadD, NULL,rotina,(void*)("Thread D"));

    /* Se o status for diferente de 0 houve algum erro na craição da thread*/
    if(rstatus != 0){
        printf("Erro ao criar thread. \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread D criada com sucesso. \n");

    /* Inicializa a thread E */
    rstatus = pthread_create(&threadE, NULL,rotina,(void*)("Thread E"));

    /* Se o status for diferente de 0 houve algum erro na craição da thread*/
    if(rstatus != 0){
        printf("Erro ao criar thread. \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread E criada com sucesso. \n");

    /*  Aqui aguardamos o encerramento das threads, uma a uma*/
    rstatus = pthread_join(threadA, &thread_res);

    if (rstatus != 0){
        printf("Erro na finalização da thread A. \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread A finalizada. Retorno =%s \n", (char*) thread_res);

    rstatus = pthread_join(threadB, &thread_res);

    if (rstatus != 0){
        printf("Erro na finalização da thread B. \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread B finalizada. Retorno =%s \n", (char*) thread_res);
    
    rstatus = pthread_join(threadC, &thread_res);

    if (rstatus != 0){
        printf("Erro na finalização da thread C. \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread C finalizada. Retorno =%s \n", (char*) thread_res);

    rstatus = pthread_join(threadD, &thread_res);

    if (rstatus != 0){
        printf("Erro na finalização da thread D. \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread D finalizada. Retorno =%s \n", (char*) thread_res);

    rstatus = pthread_join(threadE, &thread_res);

    if (rstatus != 0){
        printf("Erro na finalização da thread E. \n");
        exit(EXIT_FAILURE);
    }

    printf("Thread E finalizada. Retorno =%s \n", (char*) thread_res);

    return 0;
}

void * rotina(void *arg){
    int repeticoes = 5;

    while(repeticoes >= 0){
        printf("%s: Saída número %i.\n", (char*)arg, repeticoes);
        repeticoes--;
        /*  Comando para ceder o controle da thread, deixando outra assumir a vez  */
        sched_yield();
    }
    pthread_exit(arg);
}