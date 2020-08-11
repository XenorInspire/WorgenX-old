#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* Function charged to empty the buffer */
void emptyBuffer()
{
    int16_t buffer = 0;
    while (buffer != '\n' && buffer != EOF)
        buffer = getchar();
}

int main(int argc, char const *argv[])
{
    bool buffer = false;
    char choice = 'o';
    while (choice == 'o')
    {
        if ((argv[1] != NULL) && ((strncmp(argv[1], "-c", 2)) == 0))
            system("clear");

        system("gcc -c ../main.c");
        system("gcc -c ../library/menu.c");
        system("gcc -c ../library/generator.c");
        system("gcc -c ../library/system.c");
        system("gcc -o WorgenX main.o system.o menu.o generator.o -lm");

        system("rm *.o");
        system("mv WorgenX ../WorgenX");

        printf("Recompiler ? (o/n) \n");

        if(buffer == true)
            emptyBuffer();

        scanf("%c",&choice);

        if (buffer == false)
            buffer = true;
    }

    return 0;
}
