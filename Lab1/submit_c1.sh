#!/bin/bash
#SBATCH --job-name=ap7982_c1
#SBATCH --nodes=1
#SBATCH --cpus-per-task=1
#SBATCH --time=00:10:00
#SBATCH --mem=1GB
#SBATCH --output=%x.out

module purge
module load anaconda3/2020.07
eval "$(conda shell.bash hook)"
conda activate idle
cd /scratch/ap7982/lab1

# Compile the C program
gcc -O3 -Wall -o c1 c1.c

# Run the program with N=1000000 and R=1000
./c1 1000000 1000

# Run the program with N=300000000 and R=20
./c1 300000000 20