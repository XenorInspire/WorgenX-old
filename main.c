/* Main part of WorgenX
Made by Xen0rInspire */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "includes/struct.h"

#define MAX_LENGTH 50

void emptyBuffer()
{
    int16_t buffer = 0;
    while (buffer != '\n' && buffer != EOF)
        buffer = getchar();
}

int64_t validLength(char **length)
{
    int8_t lock = 0;
    int64_t size;

    while (lock == 0)
    {
        printf("Specify a valid length \n");
        emptyBuffer();
        fgets(*length, MAX_LENGTH, stdin);

        if (*length[strlen(*length) - 1] == '\n')
            *length[strlen(*length) - 1] = '\0';

        if (atoi(*length) != 0)
        {
            size = atoi(*length);
            lock = 1;
        }
    }

    return size;
}

void displayTitle(int8_t max)
{
    printf("\n");
    for (int8_t i = 0; i < max; i++)
        printf("#");

    printf("\n");
}

int main(int argc, char const *argv[])
{
    GEN_CONFIG wordlistConfig;
    char choice;
    char *length;

    length = malloc(MAX_LENGTH * sizeof(char));

    displayTitle(30);
    printf("\n WorgenX by XenorInspire \n");
    displayTitle(30);

    printf("\nWish type of character you want to use ? \n");
    printf("Letters ? y/n \n");

    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
        wordlistConfig.letters = true;
    else
        wordlistConfig.letters = false;

    printf("Numbers ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
        wordlistConfig.numbers = true;
    else
        wordlistConfig.numbers = false;

    printf("Special characters ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
        wordlistConfig.specialCharacters = true;
    else
        wordlistConfig.specialCharacters = false;

    wordlistConfig.length = validLength(&length);

    return 0;
}
