#include <stdio.h>
#include <mpi.h>

int main (int argc, char *argv[]){
	int np, rank, dato, dato1;

	MPI_Request envio;
	MPI_Status estado;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank==0){
		dato = 20;
		MPI_Send(&dato, 1, MPI_INT, 1,0,MPI_COMM_WORLD);
//		printf("Hola desde procesador %d \n", rank);
	}
	if (rank==1){
		MPI_Recv(&dato1,1,MPI_INT,0,0,MPI_COMM_WORLD,&estado);
		printf("Se recibio el dato %d desde procesador: %d \n", dato1, estado.MPI_SOURCE);
		
	}
	MPI_Finalize();

	return 0;
}
