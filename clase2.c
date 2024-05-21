#include <stdio.h>
#include <mpi.h>

int main(int argc, char const *argv[])
{
    int myid, numprocs, dato;
    MPI_Status status;
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    if (myid == 0){
        MPI_Send(&myid, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }else{
        MPI_Recv(&dato, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        printf("Dato recibido del procesos 0 al proceso 1");
    }

    MPI_Finalize();


    return 0;
}
