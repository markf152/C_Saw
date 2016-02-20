/* scan_str.c -- using scanf() */

#include <stdio.h>

int main(void)
{
    char name1[11];
    char name2[11];
    int count;

    printf("\n\n");

    printf("Please enter 2 names.\n");
    count = scanf("%5s %10s", name1, name2);
    printf("I read the %d names %s and %s.\n",
           count, name1, name2);

    printf("\n\n");
    
    return 0;
}

