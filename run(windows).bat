@echo off
set /p function="Enter Function (Test Functions are matyas, himmelblau, beale2d and twominima): "
gcc main.c functions\%function%.c -o main
start main.exe
pause
py .\visualization.py
