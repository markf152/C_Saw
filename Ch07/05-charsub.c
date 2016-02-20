/* 05-charsub.c -- reads input until reaching a '#', then replaces each '.' */
/* with a '!' and each '!' with '!!' and reports the number of each         */
/* substitution.                                                            */

#include <stdio.h>

#define STOP '#'

int main(void)
{
    char ch;
    char string[512];   /* string to hold characters read in     */
    int count = 0;      /* index of characters read              */
    int numperiod = 0;  /* count of number of periods            */
    int numexclam = 0;  /* count of number of exclamation points */

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter text; end with a # character\n");

    while ((ch = getchar()) != STOP) {
        switch (ch) {
            case '.' :
                string[count] = '!';
                string[count + 1] = '\0';
                numperiod++;
                count++;
                break;
            case '!' :
                string[count] = '!'; 
                string[count + 1] = '!';
                string[count + 2] = '\0';
                numexclam++;
                count += 2;
                break;
            default :
                string[count] = ch;
                string[count + 1] = '\0';
                count ++;
        } 
    }
    printf("\n");
    printf("The string now looks like this:\n");
    printf("%s\n\n", string);
    printf("The number of periods replaced with exclamtion points ");
    printf("is: %d\n", numperiod);
    printf("The number of exclamation points replaced with 2 exclamation points ");
    printf("is %d\n", numexclam);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
