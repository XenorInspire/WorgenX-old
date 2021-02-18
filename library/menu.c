/* Functions used to build the program's menu and the wordlist config*/

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "../includes/struct.h"
#include "../includes/menu.h"
#include "../includes/system.h"

#define SIZE_BUFFER 256

/* Function charged to force the user to specify a valid numeric value */
int64_t validNumericValue()
{
    int64_t size;
    char *buffer;
    bool lock = true;
    
    while (lock == true)
    {
        printf("Enter a value \n");
        buffer = malloc(sizeof(char) * SIZE_BUFFER);
        fgets(buffer, SIZE_BUFFER, stdin);

        if (buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';

        size = atoi(buffer);
        if (size > 0)
            lock = false;

        free(buffer);
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

    printf("\nChoose what your password is composed of : \n");
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

    printf("\nChoose what your wordlist is composed of : \n");
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