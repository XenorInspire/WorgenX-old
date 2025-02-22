/* Check the values of the configuration file : config.ini */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/struct.h"
#include "../includes/init.h"
#include "../includes/system.h"

/* config.ini values */

#define LOW 1
#define MEDIUM 2
#define HIGH 3

/* default values */
#define MAX_SIZE_DIR 256
#define SIZE_LINE 100
#define CONFIG_PATH "config.ini"
#define NB_PARAM 2
#define SIZE_CONFIG_LINES 30

/* Generate a new config.ini if the file is deleted or corrupted */
void generateConfigFile()
{

    FILE *configFile;
    configFile = fopen(CONFIG_PATH, "wb");
    char **content = malloc(sizeof(char *) * NB_PARAM);
    checkPtrPtr(content);
    char *temp = malloc(SIZE_CONFIG_LINES * sizeof(char));
    checkPtr(temp);

    for (int8_t i = 0; i < NB_PARAM; i++)
    {

        content[i] = malloc(sizeof(char) * SIZE_CONFIG_LINES);
        checkPtr(content[i]);
    }

    sprintf(temp, "MODE = %hd", HIGH);
    strcpy(content[0], temp);

    strcpy(content[0], "RAND_PASSWD_BACKUP = \"randomPasswds.txt\"");

    for (int8_t j = 0; j < NB_PARAM; j++)
    {

        fprintf(configFile, "%s\n", content[j]);
        free(content[j]);
    }

    free(content);
    free(temp);
    fclose(configFile);
}

/* Extract the integer value of the parameter from the configuration file */
int16_t findIntValue(char *lineConfig)
{

    int16_t value;
    char *trash = malloc(sizeof(char) * 20);
    checkPtr(trash);
    sscanf(lineConfig, "%s = %hd", trash, &value);

    free(trash);
    return value;
}

/* Extract the string value of the parameter from the configuration file */
char *findStringValue(char *lineConfig)
{

    char *value = malloc(sizeof(char *) * (MAX_SIZE_DIR + 1));
    checkPtr(value);
    char *trash = malloc(sizeof(char) * 20);
    checkPtr(trash);
    sscanf(lineConfig, "%s = %s", trash, value);

    free(trash);
    return value;
}

/* Check all the values of the configuration file */
int8_t verifyValues(CONFIG *configWorgenX)
{

    if (!(configWorgenX->mode <= HIGH && configWorgenX->mode >= LOW))
        return 2;

    return 0;
}

/* Read WorgenX configuration file */
int8_t init(CONFIG *configWorgenX)
{

    FILE *configFile;
    configFile = fopen(CONFIG_PATH, "r");
    if (configFile == NULL)
        return 1;

    char *buffer;
    buffer = malloc((SIZE_LINE + 1) * sizeof(char));
    checkPtr(buffer);

    while (fgets(buffer, SIZE_LINE, configFile) != NULL)
    {

        if (strstr(buffer, "MODE") != NULL)
            configWorgenX->mode = findIntValue(buffer);

        if (strstr(buffer, "RAND_PASSWD_BACKUP") != NULL)
            configWorgenX->directory = findStringValue(buffer);
    }

    free(buffer);
    fclose(configFile);
    return verifyValues(configWorgenX);
}