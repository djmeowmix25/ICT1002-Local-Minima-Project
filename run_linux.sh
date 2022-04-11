#!/bin/bash
read -p "Enter Function (Test Functions are matyas, himmelblau, beale2d 
and twominima): " function
gcc main.c "functions/$function.c" -o main
./main
python ./visualization.py
