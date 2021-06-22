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
    bool encrypt;
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

/* Password configuration */
typedef struct passwdConfig
{

    bool numbers;
    bool specialCharacters;
    bool uppercaseLetters;
    bool lowercaseLetters;
    int64_t length;
    int64_t nbPassword;
    char *content;

} PASSWD_CONFIG;

/* Password content */
typedef struct passwdChars
{

    int8_t *constArrays;
    int8_t sizeConstArrays;
    PASSWD_CONFIG *passwordConfig;

} PASSWD_CHARS;

/* Configuration file content */
typedef struct config
{

    int16_t mode;
    char *directory;

} CONFIG;