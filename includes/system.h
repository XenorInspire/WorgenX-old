/* Functions used to interact with the operating system */

#define SIZE_FILE_NAME 256
#define EXT 1
#define NO_EXT 0

#ifdef _WIN32
#include <windows.h>
#define SLEEP(x) Sleep(x)
#else
#include <unistd.h>
#define SLEEP(x) sleep(x * 0.001)
#endif

/* Function charged to empty the buffer */
void emptyBuffer();

/* Function charged to get the user's input */
char *userInput(int8_t mode);

/* Check if the file name has only one txt extension (or not) */
char *verifyExtension(char *fileName);

/* Check if a char pointer is NULL */
void checkPtr(void *ptr);

/* Check if a char * pointer is NULL */
void checkPtrPtr(char **ptr);

/* Check if a file pointer is NULL */
void checkFile(FILE *log);

/* This function is used to save and display the password in the wordlist file */
void savePasswd(FILE *log, char *passwd);

/* This function is charged to calculate how many passwords the CPU is able to generate depending on the system time */
int64_t passwordBenchmark(PASSWD_CONFIG *benchPasswdConfig);

/* This function is charged to save the password(s) randomly generated */
void saveRandomPasswd(char **content, int64_t size, char *directory);