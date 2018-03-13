#include<stdio.h>
#include<pthread.h>
#define NUM_HILOS 4

void *hola(void *pArg){
    int* p = (int*)pArg;
    int myNum = *p;
    printf("soy el hillo numero  %d \n", myNum);
} 

int main(){
    int i;
    pthread_t tid[NUM_HILOS];
    for (i = 0; i<NUM_HILOS; i++)
        pthread_create(&tid[i], NULL, hola, &i);

    for (i=0; i<NUM_HILOS; i++)
        pthread_join(tid[i], NULL);

    return 0;
}
