/* 06-nonwhite.c -- returns the first non-whitespace character entered*/

#include <stdio.h>
#include <ctype.h>

char get_first_nonwhitechar(void);

int main(void)
{
    char ch;

    printf("\n\n");  // Blank lines for readability

    printf("Type in some characters.. I will identify the first\n");
    printf("non-whitespace character you enter.\n\n");

    ch = get_first_nonwhitechar();
    
    printf("The first non-whistespace character entered is %c\n", ch);

    printf("\n\n");  // Blank lines for readability
        
    return 0;
}

char get_first_nonwhitechar(void)
{
    char ch;
    
    while (isspace(ch = getchar())) 
        continue;

    return ch;
}

