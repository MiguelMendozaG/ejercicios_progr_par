#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define NUM_HILOS 4

void *hola(void *pArg){
    int myNum = *((int*)pArg);
    printf("soy el hillo numero  %d con id %d\n", myNum, (int)pthread_self());
    pthread_exit(NULL);  // ((void*)&cuenta)  cuenta es un entero que lleva el valor de la suma
} 

int main(){
    int i, tNum[NUM_HILOS];
    pthread_t tid[NUM_HILOS];
    for (i = 0; i<NUM_HILOS; i++){
        tNum[i] = i;
        if(pthread_create(&tid[i], NULL, hola, &tNum[i])){
            printf("\n error al crear el hilo \n ");
            exit(0);
        }
    }
    for (i=0; i<NUM_HILOS; i++)
        pthread_join(tid[i], NULL);  //en el join se recibe el valor que se pasa como referencia en el pthread_exit

    return 0;
}
