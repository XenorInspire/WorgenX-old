/* Main part of WorgenX
Made by Xen0rInspire */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "includes/main.h"
#include "includes/struct.h"
#include "includes/generator.h"
#include "includes/menu.h"
#include "includes/system.h"

/* This function is charged to load the password encryption */
void encryptFeature()
{

    char choice = '1';
    while(choice == '1'){

        printf("Please enter your password : \n");
        char *plainText = userInput();
    }

}

/* This function is charged to load wordlist generation functionality */
void wordlistFeature()
{
    char choice = '1';
    GEN_CONFIG wordlistConfig;

    while (choice == '1')
    {

        while (allocateConfig(&wordlistConfig) == false)
        {
            printf("Error, you forgot to specify the character's type you want to use \n");
        }

        printf("Specify a valid length or a valid max if it's a variable size\n");
        emptyBuffer();
        wordlistConfig.length = validNumericValue();
        wordlistConfig.fileName = userInput();
        generateWordlist(&wordlistConfig);

        free(wordlistConfig.fileName);

        printf("\n Do you want to create another wordlist ?\n");
        printf("1 : Yes\n0 : No \n");
        scanf("%c", &choice);
    }
}

/* This function is charged to load the password generation functionality */
void passwordFeature()
{

    char choice = '1';
    PASSWD_CONFIG passwordConfig;

    while (choice == '1')
    {

        while (allocatePasswdConfig(&passwordConfig) == false)
        {

            printf("Error, you forgot to specify the character's type you want to use \n");
        }

        printf("Specify a valid length\n");
        emptyBuffer();
        passwordConfig.length = validNumericValue();
        printf("How many passwords do you want to generate ?\n");
        passwordConfig.nbPassword = validNumericValue();

        for (int64_t m = 0; m < passwordConfig.nbPassword; m++)
        {

            passwordConfig.content = randPasswd(&passwordConfig);
            printf("Your password : %s\n", passwordConfig.content);
            free(passwordConfig.content);
        }

        printf("\n Do you want to generate another password ?\n");
        printf("1 : Yes\n0 : No \n");
        scanf("%c", &choice);
    }
}

/* This function is charged to load the benchmark functionality */
void benchFeature()
{
    PASSWD_CONFIG benchPasswdConfig;
    int64_t nbPasswd;
    char choice = '1';
    while (choice == '1')
    {
        printf("The benchmark is loading... Wait a minute.. \n");
        createBenchPasswd(&benchPasswdConfig);
        nbPasswd = passwordBenchmark(&benchPasswdConfig);
        printf("Number of passwords generated in a minute : %d \n", nbPasswd);

        printf("\n Do you want to make another benchmark ?\n");
        printf("1 : Yes\n0 : No \n");
        scanf("%c", &choice);
    }
}

int main(int argc, char const *argv[])
{

    char choice = 1;
    while (choice != '0')
    {

        displayTitle(30);
        printf("\n WorgenX by XenorInspire \n");
        displayTitle(30);

        printf("\n1 : Create a wordlist \n");
        printf("2 : Generate a random password \n");
        printf("3 : Encrypt a password (sha256) \n");
        printf("4 : Benchmark \n");
        printf("0 : Exit WorgenX\n");
        scanf("%c", &choice);

        switch (choice)
        {
        case '1':
            wordlistFeature();
            break;

        case '2':
            passwordFeature();
            break;

        case '3':
            encryptFeature();
            break;

        case '4':
            benchFeature();
            break;
        }


    emptyBuffer();
}

return 0;
}
