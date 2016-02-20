/* 10-tax.c -- calculates a tax based on 1988 tax categories and income */

#include <stdio.h>

#define SINGLE        17850.00
#define HEAD_OF_HOUSE 23900.00
#define MARRIED_JOINT 29750.00
#define MARRIED_SEP   14875.00

int getcategory(void);

int main(void)
{
    int category;
    float rate;
    float taxableincome;
    float firstlimit;
    float tax;

    printf("\n\n");  // Blank lines for readability

    printf("This program calculates tax due, based on category and taxable income.\n\n");

    category = getcategory();

    if (category < 5) {
        printf("Enter the taxable income: ");
        scanf("%f", &taxableincome);
    }

    while (category < 5) {

        switch (category) {
            case 1 :
                firstlimit = SINGLE;
                break;
            case 2 :
                firstlimit = HEAD_OF_HOUSE;
                break;
            case 3 :
                firstlimit = MARRIED_JOINT;
                break;
            case 4 :
                firstlimit = MARRIED_SEP;
                break;
            default :
                break;
        }  

        tax = (.15 * firstlimit) + (.28 * (taxableincome - firstlimit));

        printf("The tax due is: %.2f\n\n", tax); 

        category = getcategory();
        if (category < 5) {
            printf("Enter the taxable income: ");
            scanf("%f", &taxableincome);
        }
    }

    printf("\n\n");  // Blank lines for readability

    return 0;
}

int getcategory(void)
{
    int cat;

    printf("*****************************************************\n");
    printf("Enter the number corresponding to the tax category:\n");
    printf("Enter 5 to quit\n");
    printf("1) Single           2) Head of Household\n");
    printf("3) Married, Joint   4) Married, separate\n");
    printf("5) quit\n");
    printf("*****************************************************\n");
    printf("\n");
    scanf("%d", &cat);

    return cat;
}
