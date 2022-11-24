#!/bin/bash

#SBATCH --job-name=singlecpu
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

# Your script goes here
sleep 30
echo "hello"