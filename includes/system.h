/* Functions used to interact with the operating system */

#define SIZE_FILE_NAME 256

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(x) Sleep(x)
#else
    #include <unistd.h>
    #define SLEEP(x) sleep(x * 0.001)
#endif

/* Function charged to empty the buffer */
void emptyBuffer();

void wordslistFile(GEN_CONFIG *wordlistConfig);

// Check if the file name has only one SQL extension (or not)
char * verifyExtension(char * fileName);

// Check if a simple char pointer is NULL
void checkSimplePtr(char * ptr);