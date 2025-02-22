/* Check the values of the configuration file : config.ini */
#include <stdint.h>

/* Read WorgenX configuration file */
int8_t init(CONFIG *configWorgenX);

/* Extract the integer value of the parameter from the configuration file */
int16_t findIntValue(char *lineConfig);

/* Generate a new config.ini if the file is deleted or corrupted */
void generateConfigFile();

/* Check all the values of the configuration file */
int8_t verifyValues(CONFIG *configWorgenX);

/* Extract the string value of the parameter from the configuration file */
char *findStringValue(char *lineConfig);