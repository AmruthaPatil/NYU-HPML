#!/bin/bash
#SBATCH --job-name=c3
#SBATCH --nodes=1
#SBATCH --cpus-per-task=1
#SBATCH --time=00:10:00
#SBATCH --mem=3GB
#SBATCH --output=%x.out

module purge
module load anaconda3/2020.07
module load python/intel/3.8.6
eval "$(conda shell.bash hook)"
conda activate idle
cd /scratch/username/lab1

# Compile the C program with MKL
gcc -O3 -Wall -o c3 c3.c -DMKL_ILP64  -m64  -I"${MKLROOT}/include" -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -lmkl_intel_ilp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl

# Run the program with N=1000000 and R=1000
./c3 1000000 1000

# Run the program with N=300000000 and R=20
./c3 300000000 20