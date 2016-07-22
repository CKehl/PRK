#!/bin/bash -l
#SBATCH -p debug
#SBATCH -N 8
#SBATCH -t 00:03:00
#SBATCH -J transpose_mpi_0008
#SBATCH -o transpose_mpi_0008.out

# Run 25 iterations
date
srun -n 192 ../../../MPI1/Transpose/transpose 25 49152
date