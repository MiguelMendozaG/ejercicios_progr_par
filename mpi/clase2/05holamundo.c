#include <stdio.h>
#include <mpi.h>

int main (int argc, char *argv[]){
	int np, rank;

	MPI_Request envio;
	MPI_Status estado;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &np);
	MPI_Comm_size(MPI_COMM_WORLD, &rank);
	if (rank==0)
		printf("Hola desde procesador %d \n", rank);
	if (rank==1)
		printf("Hola desde procesador %d \n", rank);
	MPI_Finalize();

	return 0;
}
