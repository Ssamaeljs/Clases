#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int myid, numprocs, dato;
    MPI_Status status;
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    switch (myid)
    {
    case 0:
     //Enviar proceso 0 al proceso 1
        MPI_Send(&myid, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Dato enviado del proceso 0 al proceso 1\n");
        break;
    case 2:
        MPI_Send(&myid, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        printf("Dato enviado del proceso 0 al proceso 2\n");
        break;
    default:
        MPI_Recv(&dato, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        printf("Dato recibido en el proceso %d\n", myid);
        break;
    }

    MPI_Finalize();
    return 0;
}
