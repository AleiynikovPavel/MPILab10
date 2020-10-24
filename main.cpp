#include <mpi.h>

#define BLOCK_SIZE 15

void initArray(char * data, int offset, int size);
void setMessage(char * data, int rank);

int main( int argc, char **argv ) {
    int rank, size;
    double t1, t2;
    MPI_Status status;
    int errCode = MPI_Init(&argc, &argv);
    if (errCode != 0) {
        printf("Error init %d", errCode);
        return -1;
    }
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size < 2) {
        printf("Requires at least 2 processes\n");
        return -1;
    }
    char *WR;
    if (rank != 0) {
        WR = new char[BLOCK_SIZE];
        setMessage(WR, rank);
        MPI_Send(WR, BLOCK_SIZE, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    } else {
        WR = new char[BLOCK_SIZE * size];
        setMessage(WR, rank);
        t1 = MPI_Wtime();
        for (int i = 1; i < size; i++) {
            MPI_Recv(WR + BLOCK_SIZE * i, BLOCK_SIZE, MPI_CHAR, i, 0, MPI_COMM_WORLD, &status);
        }
        t2 = MPI_Wtime();
        printf("Result: Time=%le\n", (t2 - t1) / 100);
        for (int i = 0; i < size; i++) {
            printf("%s", WR + BLOCK_SIZE * i);
        }

    }
    delete[] WR;
    MPI_Finalize();
    return 0;
}

void setMessage(char * data, int rank) {
    int len = sprintf(data, "My rank %d\n", rank);
    initArray(data, len, BLOCK_SIZE);
}

void initArray(char * data, int offset, int size) {
    for (int i = offset; i < size; i++) {
        data[i] = 0;
    }
}