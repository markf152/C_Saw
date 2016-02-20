/* 16-interest.c -- compares simple and compound interest */

#include <stdio.h>

#define INITINVEST 100.0

int main(void)
{
    int year = 0;
    float daphne = INITINVEST; 
    float deidre = INITINVEST;

    printf("\n\n");  /* Blank lines for readability */

    printf("Daphne invests $100 at 10%% simple interest.  Deidre invests\n");
    printf("$100 at 5%% compounded annually.  This program determines the\n");
    printf("number of years it takes for Deidre's investment to exceed Daphne's.\n\n");

    do {
        daphne += (INITINVEST * 0.10);
        deidre += (daphne * 0.05);
        year ++;
    } while (deidre <= daphne);

    printf("It takes %d years for Deidre's investment to exceed the value of Daphne's.\n", year);
    printf("At the end of that period, Deidre's investment is %.2f and Daphne's is %.2f.\n", deidre, daphne);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
