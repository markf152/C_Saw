/* print_a-g.c -- prints letters a-g in columns 5 chars wide */

#include<stdio.h>

#define CHAR_LIMIT 'G'
#define TEN 10

int main(void)
{
    char c = ('a' - 1);
    int n = 0;

    printf("\n\n");  /* Blank lines for readability */

    while (c++ < 'g')
        printf("%5c", c);
    printf("\n");

    while (n++ < TEN)
        printf("%5d", n);
    printf("\n");

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
