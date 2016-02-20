/* 05-guessnum.c -- uses binary search to 'guess' a user-selected */
/* number between 1 and 100 */

#include <stdio.h>

int main(void)
{
    int guess = 50;
    int upperlim = 100;
    int lowerlim = 1;
    char ch;

    printf("\n\n");  // Blank lines for readability

    printf("Pick an integer from 1 to 100.  I will try to guess it\n");
    printf("Respond with a 'h' if my guess is high, with a 'l'\n");
    printf("if it is low or with a 'y' if it is correct.\n\n");
    
    printf("Is your number %d?\n", guess);
    while ((ch = getchar()) != 'y') {
        if (ch == 'h') 
            upperlim = guess;
        else if (ch == 'l')
            lowerlim = guess;            
        guess = lowerlim + ((upperlim - lowerlim) / 2);
        while ((ch = getchar()) != '\n')
            continue;
        printf("Ok.  Is your number %d?\n", guess);
    }
    printf("Good . . . I guessed it!");

    printf("\n\n");  // Blank lines for readability
        
    return 0;
}
