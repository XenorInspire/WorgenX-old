/* Functions used to build the program's menu and the wordlist config*/

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../includes/struct.h"
#include "../includes/menu.h"
#include "../includes/system.h"

/* Function charged to force the user to specify a valid numeric value */
int64_t validNumericValue()
{
    int8_t lock = 0;
    int64_t size;
    char *length;

    while (lock == 0)
    {
        length = malloc(MAX_LENGTH * sizeof(char));

        printf("Enter the value :\n");
        fgets(length, MAX_LENGTH, stdin);

        if (length[strlen(length) - 1] == '\n')
            length[strlen(length) - 1] = '\0';

        if (atoi(length) >= 0)
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

/* Function charged to allocate users' values to the password config */
bool allocatePasswdConfig(PASSWD_CONFIG *passwordConfig)
{

    char choice;
    bool check = false;

    printf("\nWish type of character you want to use ? \n");
    printf("Letters (uppercase) ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {

        passwordConfig->uppercaseLetters = true;
        check = true;
    }

    else
        passwordConfig->uppercaseLetters = false;

    printf("Letters (lowercase) ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {

        passwordConfig->lowercaseLetters = true;
        check = true;
    }

    else
        passwordConfig->lowercaseLetters = false;

    printf("Numbers ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {

        passwordConfig->numbers = true;
        check = true;
    }

    else
        passwordConfig->numbers = false;

    printf("Special characters ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {

        passwordConfig->specialCharacters = true;
        check = true;
    }

    else
        passwordConfig->specialCharacters = false;

    return check;
}

/* Function charged to allocate users' values to the wordlist config */
bool allocateConfig(GEN_CONFIG *wordlistConfig)
{

    char choice;
    bool check = false;

    printf("\nWish type of character you want to use ? \n");
    printf("Letters (uppercase) ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {

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

    if (choice == 'y' || choice == 'Y')
    {

        wordlistConfig->numbers = true;
        check = true;
    }

    else
        wordlistConfig->numbers = false;

    printf("Special characters ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {

        wordlistConfig->specialCharacters = true;
        check = true;
    }

    else
        wordlistConfig->specialCharacters = false;

    printf("Variable size ? (1 -> Max) y/n\n");
    printf("Defaut : fixed size \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')

        wordlistConfig->fixedSize = false;

    else
        wordlistConfig->fixedSize = true;

    printf("Do you want to encrypt the wordlist ? y/n \n");
    emptyBuffer();
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')

        wordlistConfig->encrypt = true;

    else
        wordlistConfig->encrypt = false;

    return check;
}