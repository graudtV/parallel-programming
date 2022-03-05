#include "../mympi/mympi.hpp"

namespace mpi = mympi;

int main() {
  mpi::MPIContext Ctx;
  std::cout << "size = " << mpi::commSize() << ", rank = " << mpi::commRank() << std::endl;
}