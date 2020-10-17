/* Functions used to interact with the operating system */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "../includes/struct.h"
#include "../includes/system.h"
#include "../includes/generator.h"

/* Function charged to empty the buffer */
void emptyBuffer()
{
    int16_t buffer = 0;
    while (buffer != '\n' && buffer != EOF)
        buffer = getchar();
}

/* Function charged to get the user's input */
char *userInput()
{
    char *userText = malloc(SIZE_FILE_NAME * sizeof(char));
    checkPtr(userText);

    printf("File name : \n");
    fgets(userText, SIZE_FILE_NAME, stdin);

    if (userText[strlen(userText) - 1] == '\n')
        userText[strlen(userText) - 1] = '\0';

    verifyExtension(userText);

    return userText;
}

/* Check if the file name has only one txt extension (or not) */
char *verifyExtension(char *fileName)
{

    // If there isn't a .txt extension
    if (strstr(fileName, ".txt") == NULL)
    {

        strcat(fileName, ".txt");
        return fileName;
    }

    int8_t counter = 0;
    char *ptr = fileName;

    // If there are several .txt extension in the file name
    while ((ptr = strstr(ptr, ".txt")) != NULL)
    {
        counter++;
        if (counter > 1)
            strcpy(ptr, ptr + strlen(".txt"));
        else
            ptr++;
    }

    return fileName;
}

/* Check if a char pointer is NULL */
void checkPtr(void *ptr)
{

    if (ptr == NULL)
    {
        printf("Error, not enough memory available, WorgenX will shutdown \n");
        SLEEP(3000);
        exit(0);
    }
}

/* Check if a file pointer is NULL */
void checkFile(FILE *log)
{

    if (log == NULL)
    {
        printf("Error, WorgenX is not able to write in the wordlist file\n");
        printf("Check if you have enough memory on your hard drive, if the partition isn\'t in read-only mode or if the file still exists \n");
        SLEEP(3000);
        exit(0);
    }
}

/* This function is used to save and display the password in the wordlist file */
void savePasswd(FILE *log, char *passwd)
{

    printf("%s \n", passwd);
    fprintf(log, "%s \n", passwd);
}

/* This function is charged to calculate how many passwords the CPU is able to generate depending on the system time */
int64_t passwordBenchmark(PASSWD_CONFIG *benchPasswdConfig)
{

    int64_t nbPasswd = 0;
    time_t start, end;

    time(&start);
    end = start + 60;

    while (start < end)
    {
        time(&start);
        benchPasswdConfig->content = randPasswd(benchPasswdConfig);
        free(benchPasswdConfig->content);
        nbPasswd++;
    }

    return nbPasswd;
}