/* variable_test.c -- test sizes, etc for variable types as needed */

#include <stdio.h>

int main(void)
{
    unsigned char charTest = 1;
    unsigned char lastChar = 0;

    printf("\n\n");  /* Blank lines for readability */

    while (charTest > lastChar)
    {
        printf("Char = %d", charTest);
        lastChar = charTest;
        charTest++;
        printf("   charTest++ = %d\n", charTest);
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}    
    
