#!/bin/bash
#
gcc -c -I/$HOME/include wedge_grid_prb.c
if [ $? -ne 0 ]; then
  echo "Errors compiling wedge_grid_prb.c"
  exit
fi
#
gcc -o wedge_grid_prb wedge_grid_prb.o /$HOME/libc/$ARCH/wedge_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading wedge_grid_prb.o."
  exit
fi
#
rm wedge_grid_prb.o
#
./wedge_grid_prb > wedge_grid_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running wedge_grid_prb."
  exit
fi
rm wedge_grid_prb
#
echo "Program output written to wedge_grid_prb_output.txt"
