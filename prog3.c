#include<stdio.h>
#include<pthread.h>
#define NUM_HILOS 4

void *hola(void *arg){
    printf("hola mundo\n");
    printf("soy el hillo %lu \n", pthread_self());
} 

int main(){
    int i;
    pthread_t tid[NUM_HILOS];
    for (i = 0; i<NUM_HILOS; i++)
        pthread_create(&tid[i], NULL, hola, NULL);

    for (i=0; i<NUM_HILOS; i++)
        pthread_join(tid[i], NULL);

    return 0;
}
