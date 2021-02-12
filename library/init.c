/* Check the values of the configuration file : config.ini */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/struct.h"
#include "../includes/init.h"
#include "../includes/system.h"

#define SIZE_LINE 100

/* Extract the value of the parameter from the configuration file */
int16_t findIntValue(char *lineConfig)
{

    int16_t value;
    char *trash = malloc(sizeof(char) * 20);
    checkPtr(trash);
    sscanf(lineConfig, "%s = %hd", trash, &value);

    free(trash);
    return value;
}

/* Read WorgenX configuration file */
int8_t init(CONFIG *configWorgenX)
{

    FILE *configFile;
    configFile = fopen("config.ini", "r");
    if (configFile == NULL)
        return 1;

    char *buffer;
    buffer = malloc((SIZE_LINE + 1) * sizeof(char));
    checkPtr(buffer);

    while (fgets(buffer, SIZE_LINE, configFile) != NULL)
    {

        if (strstr(buffer, "MODE") != NULL)
            configWorgenX->mode = findIntValue(buffer);
    }

    fclose(configFile);
    return 0;
}