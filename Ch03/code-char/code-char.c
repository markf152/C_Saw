/* Code to Character */

#include <stdio.h>

int main(void)
{

    int charCode;

    printf("\n\n"); /* Blank lines for readability */

    printf("Enter an ASCII character code: ");
    scanf("%d", &charCode);
    printf("The ASCII code %d corresponds to the character: %c\n", charCode, charCode);

    printf("\n\n"); /* Blank lines for readability */

    return 0;

}
