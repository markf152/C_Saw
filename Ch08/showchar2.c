/* showchar2.c -- prints characters in rows and columns */

#include <stdio.h>

void display(char cr, int lines, int width);

int main(void)
{
    int ch;  // characters to be printed
    int rows; // number of rows to be printed
    int cols; // number of columns to be printed

    printf("\n\n");  // Blank lines for readability

    printf("Enter a character and two integers: \n");
    while ((ch = getchar()) != '\n') {
        if (scanf("%d %d", &rows, &cols) != 2)
            break;
        display(ch, rows, cols);
        while (getchar() != '\n')
            continue;
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");

    printf("\n\n");  // Blank lines for readability

    return 0;
}

void display(char cr, int lines, int width)
{
    int row;
    int col;

    for (row = 1; row <= lines; row++) {
        for (col = 1; col <= width; col++) 
            putchar(cr);
        putchar('\n');  // End line and start a new one
    }
}
 
