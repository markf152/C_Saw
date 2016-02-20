/* sizeof.c -- uses sizeof operator */
/* uses C99 %z modifier -- try %u or %lu if you lack %zd */

#include <stdio.h>

int main(void)
{
    int n = 0;
    size_t intSize;

    printf("\n\n");  /* Blank lines for readability */

    intSize = sizeof(int);

    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n",
           n, (sizeof (n)), intSize);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

