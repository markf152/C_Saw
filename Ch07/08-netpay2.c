/* 08-netpay.c -- requests hours worked in a week and prints */
/* gross pay, taxes, and net pay                             */

#include <stdio.h>

#define PAYRATE1 8.75  /* $ per hour            */
#define PAYRATE2 9.33  /* $ per hour            */
#define PAYRATE3 10.00 /* $ per hour            */
#define PAYRATE4 11.20 /* $ per hour            */
#define OVERTIME 1.5   /* time and a half       */
#define TAXRATE1 0.15  /* 15% of the first $300 */
#define TAXRATE2 0.20  /* 20% of the next $150  */
#define TAXRATE3 0.25  /* 25% of the rest       */

int showmenu(void);

int main(void)
{
    float hours;
    float taxes;
    float basicpay;
    float grosspay;
    int menu;       /* Menu item chosen */
 
    printf("\n\n");  /* Blank lines for readabiity */

    menu = showmenu();

    while (menu != 5) {
        switch (menu) {
            case 1 :  basicpay = PAYRATE1;
                      break;
            case 2 :  basicpay = PAYRATE2;
                      break;
            case 3 :  basicpay = PAYRATE3;
                      break;
            case 4 :  basicpay = PAYRATE4;
                      break;
        } 
        printf("Enter the number of hours worked: ");
        scanf("%f", &hours);

        if (hours <= 40)
            grosspay = hours * basicpay;
        else
            grosspay = (40 * basicpay) + ((hours - 40) * basicpay * 1.5);

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
        printf("\n");

        menu = showmenu();
    }

    printf("\n\n");  /* Blank lines for readabiity */

    return 0;
}

int showmenu (void)
{
    int choice; 

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr                         2) $9.33/hr\n");
    printf("3) $10.00/hr                        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");
    printf("\n");

    scanf("%d", &choice);

    return choice;
}

