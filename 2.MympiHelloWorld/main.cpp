#include "mympi/mympi.hpp"

namespace mpi = mympi;

int main(int argc, char *argv[]) {
  mpi::MPIContext Ctx{&argc, &argv};
  std::cout << "size = " << mpi::commSize() << ", rank = " << mpi::commRank() << std::endl;
}