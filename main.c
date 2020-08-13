/* Main part of WorgenX
Made by Xen0rInspire */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "includes/struct.h"
#include "includes/generator.h"
#include "includes/menu.h"
#include "includes/system.h"

int main(int argc, char const *argv[])
{

    GEN_CONFIG wordlistConfig;
    char choice;

    displayTitle(30);
    printf("\n WorgenX by XenorInspire \n");
    displayTitle(30);

    printf("\n1 : Create a wordlist \n");
    printf("0 : Exit WorgenX\n");
    scanf("%c", &choice);

    while (choice == '1')
    {

        while (allocateConfig(&wordlistConfig) == false)
        {
            printf("Error, you forgot to specify the character's type you want to use \n");
        }

        wordlistConfig.length = validLength();
        wordslistFile(&wordlistConfig);
        generateWordlist(&wordlistConfig);

        free(wordlistConfig.fileName);

        printf("\n Do you want to create another wordlist ?\n");
        printf("1 : Yes\n0 : No \n");
        scanf("%c", &choice);
    }

    return 0;
}
