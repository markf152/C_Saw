/* review5.c -- test Ch 6 review question 5 code */

#include <stdio.h>

int main(void)
{
    int i;
    int j;
    int list[10];

    printf("\n\n");  /* Blank lines for readability */

    for (i = 0; i < 10; i++) {
        list[i] = 2 * i + 3;
        for (j = 1; j <= i; j++)
            printf(" %d", list[j]);
        printf ("\n");
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
