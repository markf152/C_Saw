/* pound.c -- defines a function with an argument */

#include <stdio.h>

void pound(int n);  /* ANSI function prototype declaration */

int main(void)
{
    int times = 5;
    char ch = '!';   /* ASCII code for ! is 3 */
    float f = 6.0f;
    
    printf("\n\n");  /* Blank lines for readability */

    pound( times );  /* int argument */
    pound( ch );    /* same as pound( (int)ch ) */
    pound( f );      /* same as pound( (int)f ) */

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}


void pound(int n)   /* ANSI style function header */
{
    while (n-- > 0)
        printf("#");
    printf("\n");
}

