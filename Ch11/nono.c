/* nono.c -- no! */

#include <stdio.h>

int main(void)
{
    char side_a[] = "Side A";
    char dont[] = {'W', 'O', 'W', '!' };
    char side_b[] = "Side B";

    printf("\n\n");

    puts(dont);   /* dont is not a string */

    printf("\n\n");
    
    return 0;
}

