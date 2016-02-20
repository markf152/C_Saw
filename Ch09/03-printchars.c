/* 03-printchars -- prints a specified character a specified number */
/* of times on each of a specified number of lines */

#include <stdio.h>

void printchars(char ch, int numchars, int numlines);

int main(void)
{

    char ch;
    int numchars;
    int numlines;

    printf("\n\n");  // Blank lines for readability
    
    printf("Enter the character you want to print: ");
    scanf("%c", &ch);
    printf("Enter the number of times you want to print it on each line: ");
    scanf("%d", &numchars);
    printf("Enter the number of lines you want to print the characters: ");
    scanf("%d", &numlines);

    printchars(ch, numchars, numlines);

    printf("\n\n");  // Blank lines for readability
    
    return 0;
}

void printchars(char ch, int numchars, int numlines)
{
    int x;
    int y;

    for (x = 1; x <= numlines; x++) {
        for (y = 1; y <= numchars; y++) 
            putchar(ch);
            printf("\n");
        }
}

