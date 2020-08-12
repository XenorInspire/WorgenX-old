/* All the structs of the program are defined here */

#include <stdbool.h>
#include <stdint.h>

/* Configuration of the wordlist */
typedef struct genConfig
{

    bool numbers;
    bool specialCharacters;
    bool uppercaseLetters;
    bool lowercaseLetters;
    bool fixedSize;
    int64_t length;
    char *fileName;
    FILE *log;

} GEN_CONFIG;

/* Wordlist content*/
typedef struct wordlistChars
{

    char *content;
    int64_t size;
    GEN_CONFIG *wordlistConfig;

} WDL_CHARS;