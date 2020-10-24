cmake_minimum_required(VERSION 3.18)
project(lab10)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab10 main.cpp)
add_executable(lab11 main2.cpp)

find_package(MPI REQUIRED)
message(STATUS "Run: ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} ${MPIEXEC_MAX_NUMPROCS} ${MPIEXEC_PREFLAGS} EXECUTABLE ${MPIEXEC_POSTFLAGS} ARGS")
target_link_libraries(lab10 PUBLIC MPI::MPI_CXX)
