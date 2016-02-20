/* 2-print10.c -- takes an integer as input and prints that number and */
/*                the next 10 higher integers.                         */

#include <stdio.h>

int main(void)
{
    int intNum = 0;
    int x = 0;

    printf("\n\n");  /* Blank lines for readability */

    printf("Please enter an integer: ");
    scanf("%d", &intNum);
    printf("\n");
   
    x = intNum;
 
    printf("%d  ", intNum);

    while (x++ < (intNum + 10))
        printf("%d  ", x);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

