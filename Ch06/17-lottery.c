/* 17-lottery.c -- prorgam calculates how long it takes to deplete a savings */
/* account with an initial deposit of $1,000,000, an interest rate of 8%     */
/* and $100,000 withdrawn every year.                                        */

#include <stdio.h>

#define INTRATE 0.08
#define INITINVEST 1000000

int main(void)
{

    int years = 0;
    double chuckie = INITINVEST;
    
    printf("\n\n");  /* Blank lines for readability */    

    while (chuckie > 0.0) {
        chuckie += (chuckie * 0.08);
        chuckie -= 100000;
        ++years;
    }

    printf("Chuckie's initial deposit was $1,000,000.  The interest rate is 8%%.\n");
    printf("On the last day of each year, Chuckie withdraws $100,000.\n");
    printf("It will take %d years for Chuckie to empty his account.\n", years);
    printf("At the end of the last year, Chuckie had $%.2lf.\n", (chuckie + 100000));

    printf("\n\n");  /* Blank lines for readability */    

    return 0;
}
