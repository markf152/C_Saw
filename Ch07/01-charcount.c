/* 01-charcunt.c -- counts (1) spaces, (2) newline chars, and (3) all other chars */
/* stops counting when it reads a '#'                                             */

#include <stdio.h>

int main(void)
{
    char ch;
    int spaces = 0;
    int newlines = 0;
    int otherchars = 0;

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter text to count (1) spaces, (2) newlines and\n");
    printf("(3) other characters (enter '#' after the last character)\n\n");

    while ((ch = getchar()) != '#')
        switch (ch) {
            case ' '  : spaces++;
                        break;
            case '\n' : newlines++;
                        break;
            default   : otherchars++;
        }
    
    printf("\n");
    printf("The count is . . .\n");
    printf("   %d spaces\n", spaces);
    printf("   %d new line characters\n", newlines);
    printf("   %d other characters\n", otherchars);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
