#!/bin/bash
#SBATCH --job-name=ap7982_c4
#SBATCH --nodes=1
#SBATCH --cpus-per-task=1
#SBATCH --time=00:30:00
#SBATCH --mem=3GB
#SBATCH --output=%x.out
#SBATCH --mail-type=END
#SBATCH --mail-user=ap7982@nyu.edu

module purge
module load anaconda3/2020.07
eval "$(conda shell.bash hook)"
conda activate idle
cd /scratch/ap7982/lab1

# Run the program with N=1000000 and R=1000
python c4.py 1000000 1000

# Run the program with N=300000000 and R=20
python c4.py 300000000 20