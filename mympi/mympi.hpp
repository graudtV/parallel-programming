#pragma once

#include <mpi.h>

namespace mympi {

struct MPIContext {
  MPIContext() : MPIContext(nullptr, nullptr) {}
  MPIContext(int *argc, char ***argv) { (void)MPI_Init(argc, argv); }
  ~MPIContext() { (void)MPI_Finalize(); }
};

bool initialized() {
  int res;
  (void)MPI_Initialized(&res);
  return res;
}

int commSize(MPI_Comm comm = MPI_COMM_WORLD) {
  int res;
  (void)MPI_Comm_size(comm, &res);
  return res;
}

int commRank(MPI_Comm comm = MPI_COMM_WORLD) {
  int res;
  (void)MPI_Comm_rank(comm, &res);
  return res;
}

} // namespace mympi