/* All the structs of the program are defined here */

#include <stdbool.h>
#include <stdint.h>

/* Configuration of the wordlist */
typedef struct genConfig {

    bool numbers;
    bool specialCharacters;
    bool letters;
    int64_t length;

} GEN_CONFIG;