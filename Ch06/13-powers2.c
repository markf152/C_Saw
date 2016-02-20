/* 13-powers2.c -- sets an array to the first 8 powers of 2, then prints them */

#include <stdio.h>

int main(void)
{
    int powers[8];
    int total = 1;
    int x;

    printf("\n\n");  /* Blank lines for readability */

    for (x = 0; x < 8; x++) {
        total *= 2;
        powers[x] = total;
    }

    x = 0;
    printf("The first 8 powers of 2:\n");
    do {
        printf("Power %d = %d\n", (x + 1), powers[x]);
        x++;
    } while (x < 8);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

