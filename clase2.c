#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int myid, numprocs;


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    printf("Número total de procesos: %d\n", numprocs);

    if (myid < numprocs - 1) {
        int data = 20;
        int dest = myid + 1;
        MPI_Send(&data, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
        printf("Proceso %d ha enviado datos al proceso %d.\n", myid, dest);
    }

    if (myid > 0) {
        int received_data;
        int source = myid - 1;
        MPI_Recv(&received_data, 1, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Proceso %d ha recibido datos del proceso %d. Los datos recibidos son: %d\n", myid, source, received_data);
    }

    MPI_Finalize();
    return 0;
}
