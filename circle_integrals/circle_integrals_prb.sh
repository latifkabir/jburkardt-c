#!/bin/bash
#
gcc -c -g -I/$HOME/include circle_integrals_prb.c >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling circle_integrals_prb.c"
  exit
fi
rm compiler.txt
#
gcc circle_integrals_prb.o /$HOME/libc/$ARCH/circle_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading circle_integrals_prb.o."
  exit
fi
#
rm circle_integrals_prb.o
#
mv a.out circle_integrals_prb
./circle_integrals_prb > circle_integrals_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running circle_integrals_prb."
  exit
fi
rm circle_integrals_prb
#
echo "Program output written to circle_integrals_prb_output.txt"
