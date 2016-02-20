/* floaterr.c - demonstrates roundoff error */
#include <stdio.h>
int main(void)
{
    float a, b;

    b = 2.0e20 +1.0;
    a = b - 2.0e20;

    printf("\nb = 2.0e20 +1.0 = %f \n", b);    
    printf("a = b - 2.0e2 = %f \n", a);
    printf("Obviously, 'a' should = 0 . . . .\n\n");
    return 0;
}


