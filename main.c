/* Main part of WorgenX
Made by Xen0rInspire */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void displayTitle(int8_t max)
{
    for (int8_t i = 0; i < max; i++)
        printf("#");

    printf("\n");
}

int main(int argc, char const *argv[])
{
    displayTitle(30);
    printf("WorgenX by XenorInspire \n");
    displayTitle(30);

    return 0;
}
