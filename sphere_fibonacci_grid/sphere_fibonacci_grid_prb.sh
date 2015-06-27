#!/bin/bash
#
gcc -c -I/$HOME/include sphere_fibonacci_grid_prb.c
if [ $? -ne 0 ]; then
  echo "Errors compiling sphere_fibonacci_grid_prb.c"
  exit
fi
#
gcc -o sphere_fibonacci_grid_prb sphere_fibonacci_grid_prb.o /$HOME/libc/$ARCH/sphere_fibonacci_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading sphere_fibonacci_grid_prb.o."
  exit
fi
#
rm sphere_fibonacci_grid_prb.o
#
./sphere_fibonacci_grid_prb > sphere_fibonacci_grid_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running sphere_fibonacci_grid_prb."
  exit
fi
rm sphere_fibonacci_grid_prb
#
echo "Program output written to sphere_fibonacci_grid_prb_output.txt"
