#!/bin/bash
#
gcc -c -g -I/$HOME/include bernstein_polynomial_prb.c >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling bernstein_polynomial_prb.c"
  exit
fi
rm compiler.txt
#
gcc bernstein_polynomial_prb.o /$HOME/libc/$ARCH/bernstein_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading bernstein_polynomial_prb.o."
  exit
fi
#
rm bernstein_polynomial_prb.o
#
mv a.out bernstein_polynomial_prb
./bernstein_polynomial_prb > bernstein_polynomial_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running bernstein_polynomial_prb."
  exit
fi
rm bernstein_polynomial_prb
#
echo "Program output written to bernstein_polynomial_prb_output.txt"
