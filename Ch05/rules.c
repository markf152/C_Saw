/* rules.c -- precedence test for math operators */

#include <stdio.h>

int main(void)
{
    int top;
    int score;

    printf("\n\n");  /* Blank lines for readability */

    top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
    printf("top = %d, score = %d\n", top, score);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
