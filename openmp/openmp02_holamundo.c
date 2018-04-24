#include <stdio.h>
int saludo();

int main(int arg, char *argv[]) {
#pragma omp parallel //habilita el numero de nucleos en nuestro maquina y ejecuta tantas veces lo que esta dentro de las llaves como nucleos habilitados
{
	printf ("Hola mundo con OpenMP \n");
}
return 0;
}


