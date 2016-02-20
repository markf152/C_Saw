/* nestloops.c -- use nested loops to print a pattern of $ */

#include <stdio.h>

int main(void)
{
    int x;
    int y;

    printf("\n\n");  /* Blank lines for readability */

    for (x = 1; x < 6; x++) {
        for (y = 1; y <= x; y ++)
            printf("$");
        printf("\n");
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

