/* 02-charcode.c -- reads input until a '#' is read. Prints each */
/* character and its corresponding ASCII code (in decimal)       */

#include <stdio.h>

#define STOP '#'

int main(void)
{
    char charlist[512];
    char c;
    int count = 1;

    printf("\n\n");  /* Blank lines for readability */

    while ((c = getchar()) != STOP) {
        printf("%c %3d    ", c, c);
        if (count % 8)
            count++;
        else {
            count = 1;
            printf("\n");
        }
     }    

    printf("\n\n");  /* Blank lines for readability */

    return 0;

}
