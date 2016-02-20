/* 3-nestloops.c -- uses nested loops to print a pattern of letters */

#include <stdio.h>

int main(void)
{
    int x;
    int y;

    printf("\n\n");  /* Blank lines for readability */


    /* First loop gets 6 lines printed */
    /* Inner loop starts printing "F" and decrements down to "A" on the last run through */
    for (x = 0; x < 6; x++) {
        for (y = 0; y <= x; printf("%c", (70 - y)), y++)
            ;
        printf("\n");
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

