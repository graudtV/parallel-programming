#pragma once

#include "DataType.hpp"
#include "util/ArrayRef.hpp"

namespace mympi {

struct MPIContext {
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

template <class T>
void send(util::ArrayRef<T> data, int dst, int tag = 0,
          MPI_Comm comm = MPI_COMM_WORLD) {
  (void)MPI_Send(data.data(), data.size(), DataType<T>::value, dst, tag, comm);
}

template <class T>
void recv(util::MutableArrayRef<T> data, int src, int tag = MPI_ANY_TAG, MPI_Comm comm = MPI_COMM_WORLD, MPI_Status *status = MPI_STATUS_IGNORE) {
  (void)MPI_Recv(data.data(), data.size(), DataType<T>::value, src, tag, comm, status);
}

double wtime() { return MPI_Wtime(); }
double wtick() { return MPI_Wtick(); }

class Timer {
public:
  Timer() : InitialTime(wtime()) {}
  double getElapsedTimeInSeconds() const { return wtime() - InitialTime; }

private:
  double InitialTime;
};

} // namespace mympi