#!/bin/bash
#
gcc -c -O2 -I$HOME/include blas0_prb.c >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling blas0_prb.c"
  exit
fi
rm compiler.txt
#
gcc blas0_prb.o $HOME/libc/$ARCH/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading blas0_prb.o."
  exit
fi
#
rm blas0_prb.o
#
mv a.out blas0_prb
./blas0_prb > blas0_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running blas0_prb."
  exit
fi
rm blas0_prb
#
echo "Program output written to blas0_prb_output.txt"
