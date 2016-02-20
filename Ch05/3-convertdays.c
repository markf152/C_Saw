/* 3-daysconvert -- input number of days, output is equivalent weeks and days */

#include <stdio.h>

int main(void)
{
    int days = 0;

    printf("\n\n");  /* Blank lines for readability */
   
    printf("This program inputs a number of days and expresses\n");
    printf("that in weeks and days.\n\n");

    printf("Please enter the number of days.\n");
    printf("Enter 0 or a negative number to quit\n"); 
    scanf("%d", &days);
    printf("\n");

    while (days > 0) {
        printf("%d days are %d weeks, %d days.\n\n",
               days, (days / 7), (days % 7));
        printf("Please enter the number of days.\n");
        printf("Enter 0 or a negative number to quit\n"); 
        scanf("%d", &days);
        printf("\n");
    }        

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

