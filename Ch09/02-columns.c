/* 02-columns -- prints a requested character in the columns specified */

#include <stdio.h>

void min(char ch, int i, int j);

int main(void)
{
    char ch;
    int i;
    int j;

    printf("\n\n");  // Blank lines for readability
    
    printf("Enter the desired character to print: ");
    ch = getchar(); 
    printf("Enter the beginning and ending column numbers: ");
    scanf("%d %d", &i, &j);
    
    min(ch, i, j);

    printf("\n\n");  // Blank lines for readability
 
    return 0;
}

void min(char ch, int i, int j)
{
    int x;

    for (x = 1; x <= j; x++) {
        if (x < i)
            printf(" ");
        else
            putchar(ch);
    }
    printf("\n");
}

