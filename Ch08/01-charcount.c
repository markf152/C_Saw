/* 01-charcount.c -- counts characters in input up to end-of-file */

#include <stdio.h>

int main(void)
{
    char ch;
    int charcount = 0;

    printf("\n\n");  // Blank lines for readability
    
    while ((ch = getchar()) != EOF) 
       charcount++; 

    printf("\n");
    printf("The number of characters in the input stream was: %d", charcount);
    
    printf("\n\n");  // Blank lines for readability

    return 0;
}

