#include<stdio.h>
#include<pthread.h>
#define NUM_HILOS 4

void *hola(void *pArg){
    int myNum = *((int*)pArg);
    printf("soy el hillo numero  %d \n", myNum);
} 

int main(){
    int i, tNum[NUM_HILOS];
    pthread_t tid[NUM_HILOS];
    for (i = 0; i<NUM_HILOS; i++){
        tNum[i] = i;
        pthread_create(&tid[i], NULL, hola, &tNum[i]);
}
    for (i=0; i<NUM_HILOS; i++)
        pthread_join(tid[i], NULL);

    return 0;
}
