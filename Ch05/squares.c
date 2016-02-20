/* squares.c -- produces table of the first 20 integer squares */

#include <stdio.h>

int main(void)
{
    int num = 1;

    printf("\n\n");  /* Blank lines for readability */

    while (num < 21)
    {
        printf("%4d %6d\n", num, (num * num));
        num = num +1;
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

