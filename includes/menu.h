/* Functions used to build the program's menu and the wordlist config*/

#include <stdint.h>
#include <stdbool.h>

#define MAX_LENGTH 50

/* Function charged to create a beautiful menu x) */
void displayTitle(int8_t max);

/* Function charged to empty the buffer */
void emptyBuffer();

/* Function charged to force the user to specify a valid length */
int64_t validLength();

/* Function charged to allocate users' values to the wordlist config */
bool allocateConfig(GEN_CONFIG *wordlistConfig);