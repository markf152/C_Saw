/* 07-netpay.c -- requests hours worked in a week and prints */
/* gross pay, taxes, and net pay                             */

#include <stdio.h>

#define BASICPAY 10.00 /* $ per hour            */
#define OVERTIME 1.5   /* time and a half       */
#define TAXRATE1 0.15  /* 15% of the first $300 */
#define TAXRATE2 0.20  /* 20% of the next $150  */
#define TAXRATE3 0.25  /* 25% of the rest       */

int main(void)
{
    float hours;
    float taxes;
    float grosspay;
 
    printf("\n\n");  /* Blank lines for readabiity */

    printf("Enter the number of hours worked: ");
    scanf("%f", &hours);

    if (hours <= 40)
        grosspay = hours * BASICPAY;
    else
        grosspay = (40 * BASICPAY) + ((hours - 40) * BASICPAY * 1.5);

    printf("\n");
    printf("For %.1f hours . . . \n", hours);
    printf("The gross pay is: %8.2f\n", grosspay);
    if (grosspay < 300)
        taxes = grosspay * TAXRATE1;
    else {
        taxes = 300 * TAXRATE1; 
        if ((grosspay > 300) && (grosspay < 450))
            taxes += (grosspay - 300) * TAXRATE2;
        else
            taxes += 150 * TAXRATE2;
        if (grosspay > 450)
            taxes += (grosspay - 450) * TAXRATE3;
    }

    printf("The taxes are:    %8.2f\n", taxes);
    printf("The net pay is:   %8.2f\n", (grosspay - taxes));

    printf("\n\n");  /* Blank lines for readabiity */

    return 0;
}

