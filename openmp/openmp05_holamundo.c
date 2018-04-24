//compilacion :      gcc openmp03_holamundo.c -o openmp03_holamundo -fopenmp

#include <stdio.h>
int saludo();

int main() {
	saludo();
}

int saludo(){
	int i;
	//int a[24], b[24], c[24];
int a[30] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50};
int b[30] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51};
int c[30]={};
#pragma omp parallel
#pragma omp for //la division de hilos va de acuerdo al numero de nucleos habilitados
	for (i=0; i<=16; i++){ 
		//a[i] = i;
		//b[i] = i;
		c[i] = a[i] + b[i];
		printf("\n hola mundo desde el hilo ... %d, res = %d \n",omp_get_thread_num(),c[i]);
		sleep(1);
}
}
