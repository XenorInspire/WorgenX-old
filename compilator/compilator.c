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
        //system("gcc -c ../functions/generate.c");
        system("gcc -o WorgenX.exe main.o");

        //system("mv xml.o ../functions/xml.o");
        system("mv main.o ../main.o");
        system("mv WorgenX.exe ../WorgenX.exe");

        printf("Recompiler ? (o/n) \n");
        fflush(stdin);
        scanf("%c", &choice);
    }

    return 0;
}
