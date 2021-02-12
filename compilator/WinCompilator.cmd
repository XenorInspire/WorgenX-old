gcc -c ../main.c
gcc -c ../library/menu.c
gcc -c ../library/generator.c
gcc -c ../library/system.c
gcc -c ../library/encrypt.c
gcc -c ../library/init.c
gcc -o WorgenX.exe main.o system.o encrypt.o menu.o init.o generator.o

del *.o
move ./WorgenX.exe ../WorgenX.exe
echo "Compilation terminée"