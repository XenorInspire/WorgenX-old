#!/bin/bash

echo "Compilation..."
gcc -c ../main.c
gcc -c ../library/menu.c
gcc -c ../library/generator.c
gcc -c ../library/system.c
gcc -c ../library/encrypt.c
gcc -c ../library/init.c
gcc -o WorgenX main.o system.o menu.o encrypt.o generator.o init.o -lm
rm *.o
mv WorgenX ../WorgenX
echo "WorgenX is ready to use !"