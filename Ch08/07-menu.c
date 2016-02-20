/* 07-menu.c -- requests hours worked in a week and prints */
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

char showmenu(void);

int main(void)
{
    float hours;
    float taxes;
    float basicpay;
    float grosspay;
    char menu;       /* Menu item chosen */
 
    printf("\n\n");  /* Blank lines for readabiity */

    menu = showmenu();

    while (menu != 'q') {
        switch (menu) {
            case 'a' :  basicpay = PAYRATE1;
                      break;
            case 'b' :  basicpay = PAYRATE2;
                      break;
            case 'c' :  basicpay = PAYRATE3;
                      break;
            case 'd' :  basicpay = PAYRATE4;
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

char showmenu (void)
{
    char choice; 

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr                         b) $9.33/hr\n");
    printf("c) $10.00/hr                        d) $11.20/hr\n");
    printf("q) quit\n");
    printf("*****************************************************************\n");
    printf("\n");

    scanf("%c", &choice);

    return choice;
}

