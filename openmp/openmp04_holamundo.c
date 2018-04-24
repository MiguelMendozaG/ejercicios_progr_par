//compilacion :      gcc openmp03_holamundo.c -o openmp03_holamundo -fopenmp

#include <stdio.h>
int saludo();

int main() {
	saludo();
}

int saludo(){
	int i;
#pragma omp parallel
#pragma omp for //la division de hilos va de acuerdo al numero de nucleos habilitados
	for (i=0; i<=24; i++){
		printf("\n hola mundo desde el hilo ... %d \n",omp_get_thread_num());
		sleep(1);
}
}
