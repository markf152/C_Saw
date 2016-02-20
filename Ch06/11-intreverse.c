/* intreverse.c -- reads  8 integers into an array and prints them out in reverse order */

#include <stdio.h>

int main(void)
{
    int numArray[8];
    int x;

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter 8 integers: ");
    for (x = 0; x < 8; x++)
        scanf("%d", &numArray[x]);

    printf("Here are your numbers in reverse order:\n");
    for (x = 7; x >= 0; x--)
        printf("%d ", numArray[x]);
    printf("\n");

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
