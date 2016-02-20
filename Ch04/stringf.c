/* stringf.c -- string formatting */
/* demonstrates string formatting with variations */

#include <stdio.h>
#define BLURB "Authentic imitation!"

int main(void)
{
    printf("\n\n");  /* Blank lines for readability */

    printf("[%2s]\n", BLURB);
    printf("[%24s]\n", BLURB);
    printf("[%24.5s]\n", BLURB);
    printf("[%-24.5s]\n", BLURB);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
