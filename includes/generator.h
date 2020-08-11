/* functions used to generate wordlist */

#include <stdint.h>

#define SIZE_UPPER_CHAR 26
#define SIZE_LOWER_CHAR 26
#define SIZE_DIGITS 10
#define SIZE_SPE_CHAR 30

#define FIXED_LENGTH 0
#define VARIABLE_LENGTH 1

/* Main function of wordlist generation */
int8_t generateWordlist(GEN_CONFIG *wordlistConfig, int8_t mode);

/* Function charged to create the wordlist content */
WDL_CHARS createContent(GEN_CONFIG *wordlistConfig);

/* Call the function allocateChar with uppercase characters parameters*/
char *allocateUppercase(char *content, int64_t size);

/* Call the function allocateChar with lowercase characters parameters*/
char *allocateLowercase(char *content, int64_t size);

/* Call the function allocateChar with numbers parameters*/
char *allocateNumbers(char *content, int64_t size);

/* Call the function allocateChar with special characters parameters*/
char *allocateSpecialChar(char *content, int64_t size);

/* Function charged to allocate characters from a const array in generator.h to the content of the characters array */
char *allocateChar(char *content, int64_t contentSize, const char *definedArray, int64_t definedArraySize);

/* Function charged to generate the password from the dictionary */
void createPasswd(WDL_CHARS *wordlistContent);

/* Display the size of the wordlist */
double calculateSize(int64_t wordlistSize, int64_t length);