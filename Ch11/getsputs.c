/* getsputs.c -- using gets() and puts() */

#include <stdio.h>
#define STLEN 81

int main(void)
{
    char words[STLEN];

    printf("\n\n");

    puts("Enter a string, please.");
    gets(words);
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");

    printf("\n\n");

    return 0;
}

