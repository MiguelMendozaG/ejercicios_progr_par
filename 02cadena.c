#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#define NUM_HILOS 10

pthread_t tabla_thr[NUM_HILOS];

typedef struct{
    int id;
    char *cadena;
}thr_param_t;

thr_param_t param[NUM_HILOS];

void *hilo(thr_param_t *p){
    printf("%s %d \n", p->cadena, p->id);
    pthread_exit(&p->id);
} 

int main(int argc, char *argv[]){
    int i, *res;
    printf ("Creando hilos... \n");
    for (i = 0; i<NUM_HILOS; i++){
        param[i].cadena=strdup("Hola, soy el hilo ");
        param[i].id = i;
        pthread_create(&tabla_thr[i],NULL, (void *)&hilo, (void *)&param[i]);
    }

    printf("Hilos creados. Esperando que terminen... \n");
    for(i=0; i<NUM_HILOS; i++){
        pthread_join(tabla_thr[i], (void *)&res);
        printf("El hilo %d devolvio el valor %d \n", i,*res);
    }
    printf ("Todos los hilos finalizados... \n");
    return 0;
}
