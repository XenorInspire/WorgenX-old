/* functions used to generate wordlist */

#include <stdint.h>

#define SIZE_UPPER_CHAR 26
#define SIZE_LOWER_CHAR 26
#define SIZE_DIGITS 10
#define SIZE_SPE_CHAR 30
#define NB_CHARS_TYPE 4

/* Main function of wordlist generation */
void generateWordlist(GEN_CONFIG *wordlistConfig);

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

/* Return the size of the wordlist */
double calculateSize(int64_t wordlistSize, int64_t length);

/* Generate a random password */
char *randPasswd(PASSWD_CONFIG *passwordConfig);

/* Create the possible content for the password */
PASSWD_CHARS createPasswdContent(PASSWD_CONFIG *passwordConfig);

/* Return a random character from one of the originals arrays */
char randChar(int8_t type);

/* Convert a number in array which contains all its digits */
int8_t *convertNbIntoArray(int32_t number, PASSWD_CHARS *passwordChars);

/* Create the password configuration for the benchmarl */
void createBenchPasswd(PASSWD_CONFIG *benchPasswdConfig);