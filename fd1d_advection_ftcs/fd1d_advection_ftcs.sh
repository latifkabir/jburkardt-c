#!/bin/bash
#
gcc -c fd1d_advection_ftcs.c >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling fd1d_advection_ftcs.c"
  exit
fi
rm compiler.txt
#
gcc fd1d_advection_ftcs.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking fd1d_advection_ftcs.o"
  exit
fi
#
rm fd1d_advection_ftcs.o
mv a.out ~/binc/$ARCH/fd1d_advection_ftcs
#
echo "Executable installed as ~/binc/$ARCH/fd1d_advection_ftcs"
