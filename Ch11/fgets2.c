/* fgets2.c -- using fgets() and fputs() */

#include <stdio.h>

#define STLEN 10

int main(void)
{
    char words[STLEN];

    printf("\n\n");

    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Done.");


    printf("\n\n");

    return 0;
}

