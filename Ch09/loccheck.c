/* loccheck.c -- checks to see where variables are stored */

#include <stdio.h>

void mikado(int);

int main(void)
{
    int pooh = 2;
    int bah  = 5;

    printf("\n\n");  // Blank lines for readability
    
    printf("In main(), pooh = %d and &pooh = %p\n",
            pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n",
            bah, &bah);

    mikado(pooh);

    printf("\n\n");  // Blank lines for readability

    return 0;
}

void mikado(int bah)
{
    int pooh = 10;

    printf("In mikado(), pooh = %d and &pooh = %p\n",
            pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n",
            bah, &bah);
}

