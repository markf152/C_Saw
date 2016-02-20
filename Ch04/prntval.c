/* prntval.c -- finding printf()'s return value */

#include <stdio.h>

int main(void)
{
    int bph2o = 212;
    int rv;

    printf ("\n\n"); /* Blank lines for readability */

    rv = printf("%d F is water's boiling point.\n", bph2o);
    printf("The printf() function printed %d characters.\n",
             rv);

    printf ("\n\n"); /* Blank lines for readability */

    return 0;
}
