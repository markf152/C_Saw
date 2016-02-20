/* age_in_secs -- takes an age in years and converts to seconds */

#include <stdio.h>
#include <locale.h>  /* enables use of thousands separator comma in numbers */

int main(void)
{

int age_years;
long int age_seconds;

setlocale(LC_NUMERIC, "");  /* enables use of thousands separator comma in numbers */

printf("\n\n"); /* blank lines for readability */

printf("Enter your age in years: ");
scanf("%d/n", &age_years);

age_seconds = age_years * 365.25 * 24 * 60 * 60;

printf("Your age in seconds is approximately: %'ld\n", age_seconds);

printf("\n\n"); /* blank lines for readability */

}
