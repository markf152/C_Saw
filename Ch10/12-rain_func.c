/* 12-rain_func.c -- change listing 10.7 to use pointers instead */
/* of subscripts in its calculations */

#include <stdio.h>

#define MONTHS 12
#define YEARS 5
#define BASE_YR 2010

int main(void)
{

    float yearly_total(const float rain[][12], int year_inc);
    void print_yr_totals(const float rain[][12]);
    float years_total(const float rain[][12]);
    void monthly_avg(const float rain[][12]);
    float yearly_avg(const float rain[][12]);

    // initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    printf("\n\n");

    print_yr_totals(rain);

    printf("The yearly average is %.1f inches.\n", (yearly_avg(rain)));
    printf("\n");

    monthly_avg(rain);
    
    printf("\n\n");

    return 0;
}

float yearly_total(const float rain[][12], int year_inc)
{
    int mo;
    float yr_total = 0;

    for (mo = 0; mo < MONTHS; mo++)
       yr_total += rain[year_inc][mo];

    return yr_total;
}

void print_yr_totals(const float rain[][12])
{
    int yr;

    printf(" YEAR     RAINFALL (inches)\n");

    for (yr = 0; yr < YEARS; yr++)
        printf("%5d %15.1f\n", (BASE_YR + yr), yearly_total(rain,yr));
    printf("\n");
}

float years_total(const float rain[][12])
{
    int yr;
    float yrs_total = 0;

    for (yr = 0; yr < YEARS; yr++)
        yrs_total += yearly_total(rain, yr);

    return yrs_total;
}

void monthly_avg(const float rain[][12]) 
{
    int month;
    int year;
    float subtot;

    printf("MONTHLY AVERAGES:\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");

    for (month = 0; month < MONTHS; month++) {
        for (year = 0, subtot = 0; year < YEARS; year++)
            subtot += rain[year][month];
        printf("%4.1f ", (subtot / YEARS));
    }
}


float yearly_avg(const float rain[][12])
{
    // printf("Years Total: %f\n", years_total(rain));
    return (years_total(rain) / YEARS);
}

