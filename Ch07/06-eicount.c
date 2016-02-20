/* 06-eicount.c -- counts the number of times that the character sequence 'ei' */
/* occurs in a string entered by the user.                                     */

#include <stdio.h>

#define STOP '#'

int main(void)
{
    char ch;
    int eicount;
    char lastch = ' ';

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter a line of text; end it with a '#'\n\n");

    while((ch = getchar()) != STOP) {
        if (lastch == 'e')
            if (ch == 'i')
                eicount++;
        lastch = ch;
    }

    printf("\n");
    printf("There were %d instances of the character sequence 'ei'\n", eicount);
    printf("in the text you entered."); 

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
