/* charcount.c -- use the logical AND operator */

#include <stdio.h>
#include <iso646.h>  /* Allows use of 'and' instead of && -- just to try it */

#define PERIOD '.'

int main(void)
{
    char ch;
    int charcount = 0;

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter some text; end it with a period to get");
    printf("a count of the non-quote characters.\n\n");

    while ((ch = getchar()) != PERIOD) {
        if (ch != '"' and ch != '\'')
            charcount++;
    }

    printf("There are %d non-quote characters.\n", charcount);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}


