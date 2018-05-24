/*03holamundo.c*/
#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

int main(int argc, char*argv[]){
	int err, s, mirank;
	err = MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &s);
	MPI_Comm_rank(MPI_COMM_WORLD,&mirank);
	if (s<=1){
		printf("Este programa corre solo con mas de un procesador\n");	
		exit(0);
	}
	printf("hola MPI; bienvenido. El rank o posicion es: %d\n",mirank);
	err = MPI_Finalize();

	return 0;
}
