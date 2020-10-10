#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int main(){

    int id =fork();
    if(id == 0){
        printf("Fork filho. \n");
    }
    else{
        printf("Fork pai. \n");
    }

    return 0;
}