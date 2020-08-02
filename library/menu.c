/* Functions used to build the program's menu and the wordlist config*/

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../includes/struct.h"
#include "../includes/menu.h"
#include "../includes/system.h"

/* Function charged to force the user to specify a valid length */
int64_t validLength()
{
    int8_t lock = 0;
    int64_t size;
    char *length;
    emptyBuffer();

    while (lock == 0)
    {
        length = malloc(MAX_LENGTH * sizeof(char));

        printf("Specify a valid length \n");
        fgets(length, MAX_LENGTH, stdin);

        if (length[strlen(length) - 1] == '\n')
            length[strlen(length) - 1] = '\0';

        if (atoi(length) != 0)
        {
            size = atoi(length);
            lock = 1;
        }

        free(length);
    }

    return size;
}

/* Function charged to create a beautiful menu x) */
void displayTitle(int8_t max)
{
    printf("\n");
    for (int8_t i = 0; i < max; i++)
        printf("#");

    printf("\n");
}

/* Function charged to allocate users' values to the wordlist config */
bool allocateConfig(GEN_CONFIG * wordlistConfig){

    char choice;
    bool check = false;

    printf("\nWish type of character you want to use ? \n");
    printf("Letters (uppercase) ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y'){

        wordlistConfig->uppercaseLetters = true;
        check = true;
    }
        
    else
        wordlistConfig->uppercaseLetters = false;

    printf("Letters (lowercase) ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {

        wordlistConfig->lowercaseLetters = true;
        check = true;
    }

    else
        wordlistConfig->lowercaseLetters = false;

    printf("Numbers ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y'){

        wordlistConfig->numbers = true;
        check = true;
    }
        
    else
        wordlistConfig->numbers = false;

    printf("Special characters ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y'){

        wordlistConfig->specialCharacters = true;
        check = true;
    }
        
    else
        wordlistConfig->specialCharacters = false;

    return check;

}