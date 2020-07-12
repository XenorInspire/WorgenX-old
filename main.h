/* Functions used in the menu */

#include <stdint.h>

/* Function charged to create the menu */
void displayTitle(int8_t max);

/* Function charged to empty the buffer */
void emptyBuffer();

/* Function charged to force the user to specify a valid length */
int64_t validLength(char **length);