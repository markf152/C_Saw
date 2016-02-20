/* 07-char_report.c -- reads characters from stdin until EOF */
/* reports whether each character is a letter or number */
/* if a letter, it reports the letters place in the alphabet */
/* e.g. 'c' would be reported as 3 */

#include <stdio.h>

int charnum(char ch);

int main(void)
{
    char ch;
    int chnum;

    printf("\n\n");
    
    printf("Enter a series of characters.  Terminate\nyour input with ");
    printf("Ctrl+D twice\n\n");
    while ((ch = getchar()) != EOF) {
        chnum = charnum(ch);
        printf("Character %c is ", ch);
        if (chnum == -1)
            printf("not ");
        printf("a letter.\n");
        if (chnum != -1)
            printf("The letter's numer in the alphabet is %d.\n", chnum);
        printf("\n");
    }

    printf("\n\n");

    return 0;
}




int charnum(char ch)
{
    int chnum;
 
    if ((ch >= 65) && (ch <= 90)) 
        chnum = ch - 64;
    else if ((ch >= 97) && (ch <= 122))
        chnum = ch - 96;
    else
        chnum = -1;
    
    return chnum;

}

