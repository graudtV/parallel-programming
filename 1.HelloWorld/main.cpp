#include <mpi.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>

constexpr auto MAXBUF = 1024;

int main(int argc, char *argv[]) {
  int commsize = 0, rank = 0;
  char hostname[MAXBUF] = "";

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &commsize);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (gethostname(hostname, MAXBUF - 1) == -1)
    strcpy(hostname, "<uknown_host_name>");

  std::cout << "host " << hostname << ": commsize = " << commsize << ", rank = " << rank << std::endl;

  if (rank == 2)
    std::cerr << "Stderr also works. This is a greeting from executor #2" << std::endl;

  MPI_Finalize();
}
