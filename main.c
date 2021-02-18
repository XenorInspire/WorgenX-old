/* Main part of WorgenX
Made by Xen0rInspire */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "includes/struct.h"
#include "includes/main.h"
#include "includes/generator.h"
#include "includes/menu.h"
#include "includes/system.h"
#include "includes/encrypt.h"
#include "includes/init.h"

/* This function is charged to check the configuration file when WorgenX start */
CONFIG checkConfigFile()
{

    CONFIG configWorgenX;
    int8_t value;
    char choice = '1';
    while ((value = init(&configWorgenX)) != 0)
    {

        switch (value)
        {
        case 1:
            printf("WorgenX can't find any configuration file \n");
            break;

        case 2:
            printf("Incorrect performance value, select 1 (LOW), 2 (MEDIUM) or 3 (HIGH)\n");
            break;
        }

        printf("\n Do you want to generate a new configuration file ?\n");

        if (value != 1)
            printf("If not, WorgenX can't start untill you don't correct the value\n");

        printf("1 : Yes\n0 : No \n");
        scanf("%c", &choice);
        emptyBuffer();
        choice == '1' ? generateConfigFile() : exit(0);
    }
    return configWorgenX;
}

/* This function is charged to load the password encryption */
void encryptFeature()
{

    char choice = '1';
    while (choice == '1')
    {

        printf("Please enter your password : \n");
        emptyBuffer();
        char *plainText = userInput(NO_EXT);

        char *finalHash = mainEncrypt(plainText);
        printf("Hash (sha256) : \n%s\n", finalHash);

        free(finalHash);
        free(plainText);

        printf("\n Do you want to hash another password ?\n");
        printf("1 : Yes\n0 : No \n");
        scanf("%c", &choice);
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
            printf("Please, select at least one type of character.\n");
        }

        wordlistConfig.fixedSize == true ? printf("Specify a valid length \n") : printf("Specify a valid max length\n");
        emptyBuffer();
        wordlistConfig.length = validNumericValue();

        printf("File name : \n");
        wordlistConfig.fileName = userInput(EXT);
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

            printf("Please, select at least one type of character.\n");
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
    CONFIG configWorgenX = checkConfigFile();
    while (choice != '0')
    {

        displayTitle(30);
        printf("\n   WorgenX by Xen0rInspire \n");
        displayTitle(30);

        printf("\n1 : Create a wordlist \n");
        printf("2 : Generate a random password \n");
        printf("3 : Hash plaintext (sha256) \n");
        printf("4 : Benchmark CPU\n");
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
