#!/bin/bash
#
cp cc_to_st.h /$HOME/include
#
gcc -c -I/$HOME/include cc_to_st.c
if [ $? -ne 0 ]; then
  echo "Errors compiling cc_to_st.c"
  exit
fi
#
mv cc_to_st.o ~/libc/$ARCH/cc_to_st.o
#
echo "Library installed as ~/libc/$ARCH/cc_to_st.o"
