/* ch_rev_qs.c -- Tests code from Chapter 4 Review Questions */

#include <stdio.h>
#include <string.h>

#define Q "His Hamlet was funny without being vulgar."

int main(void)
{
    printf("\n\n");  /* Blank lines for readability */

    printf("He sold the painting for $%2.2f.\n", 2.345e2);

    printf("\n");

    printf("%c%c%c\n", 'H', 105, '\41');

    printf("\n");

    printf("\"%s\"\nhas %d characters.\n", Q, (int)strlen(Q));

    printf("\n");

    printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

