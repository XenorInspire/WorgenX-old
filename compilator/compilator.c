#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char choice = 'o';
    while (choice == 'o')
    {

        if ((argv[1] != NULL) && ((strnicmp(argv[1], "-c", 2)) == 0))
            system("clear");

        system("gcc -c ../main.c");
        system("gcc -c ../library/menu.c");
        system("gcc -c ../library/generator.c");
        system("gcc -c ../library/system.c");
        system("gcc -o WorgenX.exe main.o system.o menu.o generator.o");

        system("mv main.o ../main.o");
        system("mv menu.o ../library/menu.o");
        system("mv generator.o ../library/generator.o");
        system("mv system.o ../library/system.o");
        system("mv WorgenX.exe ../WorgenX.exe");

        printf("Recompiler ? (o/n) \n");
        fflush(stdin);
        choice = getchar();
    }

    return 0;
}
