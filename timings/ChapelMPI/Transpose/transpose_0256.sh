#!/bin/bash -l
#SBATCH -p debug
#SBATCH -N 256
#SBATCH -t 00:10:00
#SBATCH -J transpose_chapel_0256
#SBATCH -o transpose_chapel_0256.out

# Run 25 iterations
export AMMPI_MPI_THREAD=multiple
export MPICH_MAX_THREAD_SAFETY=multiple
date
srun --nodes=256 --ntasks=256 --tasks-per-node=1 --cpus-per-task=48 ../../../CHAPEL/ChapelMPI/Transpose/transpose.x -nl 256 --iterations=50 --order=49152 --tile=32
date