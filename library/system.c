/* Functions used to interact with the operating system */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../includes/struct.h"
#include "../includes/system.h"

/* Function charged to empty the buffer */
void emptyBuffer()
{
    int16_t buffer = 0;
    while (buffer != '\n' && buffer != EOF)
        buffer = getchar();
}

void wordslistFile(GEN_CONFIG * wordlistConfig){

    wordlistConfig->fileName = malloc(SIZE_FILE_NAME * sizeof(char));
    checkSimplePtr(wordlistConfig->fileName);

    printf("File name : \n");
    fgets(wordlistConfig->fileName, SIZE_FILE_NAME, stdin);

    if (wordlistConfig->fileName[strlen(wordlistConfig->fileName) - 1] == '\n')
        wordlistConfig->fileName[strlen(wordlistConfig->fileName) - 1] = '\0';

    verifyExtension(wordlistConfig->fileName);
}

// Check if the file name has only one txt extension (or not)
char * verifyExtension(char * fileName)
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
        {

            strcpy(ptr, ptr + strlen(".txt"));
        }
        else
        {

            ptr++;
        }
    }

    return fileName;
}

// Check if a simple char pointer is NULL
void checkSimplePtr(char *ptr)
{

    if (ptr == NULL)
    {
        printf("Error, not enough memory available, WorgenX will shutdown \n");
        SLEEP(3000);
        exit(0);
    }
}