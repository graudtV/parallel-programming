#pragma once

#include <mpi.h>

namespace mympi {

template <class T> struct DataType {};

#define DECLARE_MAPPING(type, mpitype)                                         \
  template <> struct DataType<type> { static constexpr MPI_Datatype value = mpitype; };

DECLARE_MAPPING(char, MPI_CHAR)
DECLARE_MAPPING(unsigned char, MPI_UNSIGNED_CHAR)
DECLARE_MAPPING(short, MPI_SHORT)
DECLARE_MAPPING(unsigned short, MPI_UNSIGNED_SHORT)
DECLARE_MAPPING(int, MPI_INT)
DECLARE_MAPPING(unsigned, MPI_UNSIGNED)
// ...
DECLARE_MAPPING(float, MPI_FLOAT)
DECLARE_MAPPING(double, MPI_DOUBLE)

#undef DECLARE_MAPPING

} // namespace mympi