/* 5-nestloops.c -- uses nested loops to print a pyramid of characters */
/*  starting with 'A' and ending with a character entered by the user. */
/*        Output looks like this . . . (user entered an 'E')           */
/*                                   A                                 */
/*                                  ABA                                */
/*                                 ABCBA                               */
/*                                ABCDCBA                              */
/*                               ABCDEDCBA                             */

#include <stdio.h>

int main(void)
{

    int rows;     /* loop cuonter for the outer 'rows' loop */
    int spaces;   /* loop counter to print the spaces preceding the first letter */
    int altrs;    /* loop counter to print the letters in ascending order */
    int dltrs;    /* loop counter to print the letters in descending order */
    char ch;      /* holds the letter that ends the series */
    int x = 1;    /* flag variable to help use 'while' as an 'if' statement */
                  /*   . . . since we haven't got to that in the book yet */

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter an uppercase letter (A-Z): ");
    scanf("%c", &ch);

    /* This loop checks the user's input to see that it is a valid uppercase character */
    while (((ch < 65) | (ch > 90)) && x) {
        printf("You did not enter an uppercase character (A-Z).  Bye.");
        x = 0;
    } 

    /* This outer while loop ensures that the program only attempts to produce output */
    /*    if the user entered a valid uppercase character                           */
    while (((ch >= 'A') && (ch <= 'Z')) && x) {
        /* Print row by row */
        for (rows = 0; rows <= (ch - 'A'); rows++) {
            /* Print leading spaces on a given row */
            for (spaces = 1; spaces <= (ch - 'A' - rows); spaces++)
                printf(" ");
            /* Print the ascending characters, e.g. ABCDE */
            for (altrs = 0; altrs <= rows; altrs++)
                printf("%c", ('A' + altrs));
            /* Print the descending characters, e.g. DCBA */
            for (dltrs = 1; dltrs <= rows; dltrs++)
                printf("%c", ('A' + rows - dltrs));
            printf("\n");
        }
        x = 0;  /* set flag to false to make while loop to function as 'if' statement */
    }
    
    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
