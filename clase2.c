#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int myid, numprocs, dato;
    MPI_Status status;
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    if (myid == 0){

        MPI_Send(&myid, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Dato enviado del procesos 0 al proceso 1");
        MPI_Send(&myid, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        printf("Dato enviado del procesos 0 al proceso 2");
        MPI_Send(&myid, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        printf("Dato enviado del procesos 0 al proceso 3");
    
    }else{
        MPI_Recv(&dato, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        printf("Dato recibido del procesos 0 al proceso 1");
        MPI_Recv(&dato, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
        printf("Dato recibido del procesos 0 al proceso 2");
        MPI_Recv(&dato, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, &status);
        printf("Dato recibido del procesos 0 al proceso 3");
        
    }
    MPI_Finalize();
    return 0;
}
