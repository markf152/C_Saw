/* review6.c -- code to answer ch 6 review question 6 */

#include <stdio.h>

int main(void)
{
    int x;
    int y;

    printf("\n\n");  /* Blank lines for readability */

    for (x = 1; x < 5; x++) {
        for (y = 1; y < 9; y++)
            printf("$");
        printf ("\n");
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

