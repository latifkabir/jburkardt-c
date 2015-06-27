#!/bin/bash
#
gcc -c -g -I/$HOME/include hypercube_integrals_prb.c >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling hypercube_integrals_prb.c"
  exit
fi
rm compiler.txt
#
gcc hypercube_integrals_prb.o /$HOME/libc/$ARCH/hypercube_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading hypercube_integrals_prb.o."
  exit
fi
#
rm hypercube_integrals_prb.o
#
mv a.out hypercube_integrals_prb
./hypercube_integrals_prb > hypercube_integrals_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running hypercube_integrals_prb."
  exit
fi
rm hypercube_integrals_prb
#
echo "Program output written to hypercube_integrals_prb_output.txt"
