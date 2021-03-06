#!/bin/bash
#
gcc -c -I/$HOME/include polygon_monte_carlo_prb.c >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling polygon_monte_carlo_prb.c"
  exit
fi
rm compiler.txt
#
gcc polygon_monte_carlo_prb.o /$HOME/libc/$ARCH/polygon_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading polygon_monte_carlo_prb.o."
  exit
fi
#
rm polygon_monte_carlo_prb.o
#
mv a.out polygon_monte_carlo_prb
./polygon_monte_carlo_prb > polygon_monte_carlo_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running polygon_monte_carlo_prb."
  exit
fi
rm polygon_monte_carlo_prb
#
echo "Program output written to polygon_monte_carlo_prb_output.txt"
