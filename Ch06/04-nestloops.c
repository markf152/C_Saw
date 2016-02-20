/* 4-nestloops.c -- print a pattern of characters using nested loops */

#include <stdio.h>

int main(void)
{
    int x;
    int y;
    char ch = 'A';

    printf("\n\n");  /* Blank lines for readability */
    
    for (x = 1; x < 7; x++) {
        for (y = 1; y <= x; y++) 
            printf ("%c", ch++);
        printf ("\n");
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

