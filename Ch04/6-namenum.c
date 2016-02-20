/* namenum.c -- user inputs first and last name; program outputs names with */
/*               number of letters in each, formatted 2 different ways      */

#include <stdio.h>
#include <string.h>

int main(void)
{

    char firstname[30];
    char lastname[30];

    printf("\n\n");  /*  Blank lines for readability */

    printf("Please enter your first name: ");
    scanf("%s", firstname);
    printf("Please enter your last name: ");
    scanf("%s", lastname);
    printf("\n");

    printf("%s %s\n", firstname, lastname);
    printf("%*d %*d\n", (int)strlen(firstname), (int)strlen(firstname), (int)strlen(lastname), (int)strlen(lastname));
    printf("%s %s\n", firstname, lastname);
    printf("%-*d %-*d\n", (int)strlen(firstname), (int)strlen(firstname), (int)strlen(lastname), (int)strlen(lastname));

    printf("\n\n");  /*  Blank lines for readability */

    return 0;
}
