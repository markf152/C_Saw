/* echo_eof.c -- repeats input to end of file */

#include <stdio.h>

int main(void)
{
    int ch;

    printf("\n\n");  /* Blank lines for readability */

    while ((ch = getchar()) != EOF)
        putchar(ch);

    // printf("%d", EOF);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
