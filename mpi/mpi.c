#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int size;
	int r;
	int intRecv = 0;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &r);

	MPI_Status status;

	int tag = 1000; /* Message tag */

	if (r != 0) {
		MPI_Recv(&intRecv, 1, MPI_INT, r - 1, tag, MPI_COMM_WORLD, &status);
		printf("								got value %d in %d from %d\n", intRecv, r, r - 1);
	}

	if (intRecv == r) {
		if (r + 1 < size) {
			printf("Osgood can be stupid  %d time, but not %d\n", r + 1, size);
		} else {
			printf(
					"Ah sorry... it seems that Osgood can really be %d/%d stupid \n",
					r + 1, size);
		}
	}

	intRecv = intRecv + 1;
	if (r != size - 1) {
		MPI_Send(&intRecv, 1, MPI_INT, r + 1, tag, MPI_COMM_WORLD);
		printf("								send value %d from %d to %d\n", intRecv, r, r + 1);
	}
	MPI_Finalize();

	return 0;
}

