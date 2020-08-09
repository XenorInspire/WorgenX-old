/* functions used to generate wordlist */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/struct.h"
#include "../includes/generator.h"
#include "../includes/system.h"

const char lowChar[SIZE_LOWER_CHAR] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char upperChar[SIZE_UPPER_CHAR] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const char digits[SIZE_DIGITS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const char specialCharacters[SIZE_SPE_CHAR] = {'~', '"', '\'', '{', '(', '[', '-', '|', '`', '_', '\\', '^', '@', ')', ']', '=', '+', '}', '$', '%', '*', '!', ':', '/', ';', '.', ',', '?', '<', '>'};

/* Main function of wordlist generation */
int8_t generateWordlist(GEN_CONFIG *wordlistConfig, int8_t mode)
{

    WDL_CHARS wordlistContent = createContent(wordlistConfig);

    // for (int64_t i = 0; i < wordlistContent.size; i++)
    // {
    //     printf("|%c|",wordlistContent.content[i]);
    // }
    // printf("\n");

    if (mode == FIXED_LENGTH)
    {

        createPasswd(&wordlistContent);
    }
    else if (mode == VARIABLE_LENGTH)
    {
    }

    free(wordlistContent.content);

    return 0;
}

/* Function charged to create the wordlist content */
WDL_CHARS createContent(GEN_CONFIG *wordlistConfig)
{

    WDL_CHARS wordlistContent;
    int64_t size = 0;
    wordlistContent.wordlistConfig = wordlistConfig;

    if (wordlistConfig->numbers == true)
    {

        wordlistContent.content = allocateNumbers(wordlistContent.content, size);
        size += SIZE_DIGITS;
    }

    if (wordlistConfig->uppercaseLetters == true)
    {

        wordlistContent.content = allocateUppercase(wordlistContent.content, size);
        size += SIZE_UPPER_CHAR;
    }

    if (wordlistConfig->lowercaseLetters == true)
    {

        wordlistContent.content = allocateLowercase(wordlistContent.content, size);
        size += SIZE_LOWER_CHAR;
    }

    if (wordlistConfig->specialCharacters == true)
    {

        wordlistContent.content = allocateSpecialChar(wordlistContent.content, size);
        size += SIZE_SPE_CHAR;
    }

    wordlistContent.size = size;

    return wordlistContent;
}

/* Call the function allocateChar with uppercase characters parameters*/
char *allocateUppercase(char *content, int64_t size)
{

    return allocateChar(content, size, upperChar, SIZE_UPPER_CHAR);
}

/* Call the function allocateChar with lowercase characters parameters*/
char *allocateLowercase(char *content, int64_t size)
{

    return allocateChar(content, size, lowChar, SIZE_LOWER_CHAR);
}

/* Call the function allocateChar with numbers parameters*/
char *allocateNumbers(char *content, int64_t size)
{

    return allocateChar(content, size, digits, SIZE_DIGITS);
}

/* Call the function allocateChar with special characters parameters*/
char *allocateSpecialChar(char *content, int64_t size)
{

    return allocateChar(content, size, specialCharacters, SIZE_SPE_CHAR);
}

/* Function charged to allocate characters from a const array in generator.h to the content of the characters array */
char *allocateChar(char *content, int64_t contentSize, const char *definedArray, int64_t definedArraySize)
{

    if (contentSize == 0)
    {

        content = malloc(definedArraySize * sizeof(char));
        checkSimplePtr(content);

        for (int64_t i = 0; i < definedArraySize; i++)
            content[i] = definedArray[i];
    }
    else
    {

        int64_t i;
        char *newContent = malloc((contentSize + definedArraySize) * sizeof(char));
        checkSimplePtr(newContent);

        for (i = 0; i < contentSize; i++)
            newContent[i] = content[i];

        i = 0;
        for (int64_t j = contentSize; j < definedArraySize + contentSize; j++)
        {

            newContent[j] = definedArray[i];
            i++;
        }

        free(content);
        content = newContent;
    }

    return content;
}

/* Function charged to generate the password from the dictionary */
void createPasswd(WDL_CHARS *wordlistContent)
{

    int16_t count = 0;
    bool end = false;
    char *passwd;
    passwd = malloc((wordlistContent->wordlistConfig->length + 1) * sizeof(char));
    checkSimplePtr(passwd);

    int16_t index[wordlistContent->wordlistConfig->length];

    for (int16_t i = 0; i < wordlistContent->wordlistConfig->length; i++)
    {
        index[i] = 0;
        passwd[i] = wordlistContent->content[index[i]];
    }

    passwd[wordlistContent->wordlistConfig->length] = '\0';

    //envoyer le passwd au fichier et sur stdin

    while (end == false)
    {
        index[wordlistContent->wordlistConfig->length - 1]++;

        for (int j = wordlistContent->wordlistConfig->length - 1; j >= 0; j--)
        {
            if (index[j] == wordlistContent->size)
            {

                index[j] = 0;
                if (j != 0)
                    index[j - 1]++;
            }
        }

        for (int i = 0; i < wordlistContent->wordlistConfig->length; i++)
        {
            passwd[i] = wordlistContent->content[index[i]];
            if (passwd[i] == wordlistContent->content[wordlistContent->size - 1])
                count++;
        }

        if (count == wordlistContent->wordlistConfig->length)
            end = true;
        else
            count = 0;

        //envoyer le passwd au fichier et sur stdin
    }

    free(passwd);
    //fermeture du fichier
}