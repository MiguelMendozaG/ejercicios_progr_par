/*04holamundo.c*/
#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

int main(int argc, char*argv[]){
	int err, s, mirank, np;
	err = MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &s);
	MPI_Comm_rank(MPI_COMM_WORLD,&mirank);
	if (s<=1){
		printf("Este programa corre solo con mas de un procesador\n");	
		exit(0);
	}
	if (mirank==0)
		printf("soy el procesador maestro, ranking = %d \n", mirank);
	if (mirank!=0)
		printf("Hola, soy cualquier otro procesador, ranking = %d \n", mirank);

	err = MPI_Finalize();


	return 0;
}
