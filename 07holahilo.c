#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define NUM_HILOS 4

void *hola(void *pArg){
    printf("soy el hillo numero  %d \n", (int)pthread_self());
    pthread_exit(NULL);
} 

int main(){
    int i, tNum[NUM_HILOS];
    pthread_t tid[NUM_HILOS];
    for (i = 0; i<NUM_HILOS; i++){
        if(pthread_create(&tid[i], NULL, hola, &tNum[i])){
            printf("\n error al crear el hilo \n ");
            exit(0);
        }
    }
    for (i=0; i<NUM_HILOS; i++)
        pthread_join(tid[i], NULL);

    return 0;
}
