/* Main part of WorgenX
Made by Xen0rInspire */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "includes/struct.h"
#include "includes/menu.h"

int main(int argc, char const *argv[])
{
    GEN_CONFIG wordlistConfig;

    displayTitle(30);
    printf("\n WorgenX by XenorInspire \n");
    displayTitle(30);

    while (allocateConfig(&wordlistConfig) == false)
    {
        printf("Error, you forgot to specify the character's type you want to use \n");
    }

    wordlistConfig.length = validLength();

    printf("numbers : %d", wordlistConfig.numbers);
    printf("specialCharacters : %d", wordlistConfig.specialCharacters);
    printf("letters : %d", wordlistConfig.letters);
    printf("length : %ld", wordlistConfig.length);

    return 0;
}
