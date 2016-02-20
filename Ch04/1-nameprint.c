/* nameprint.c -- asks for first name and last name, then prints them */
/* in the format <last name>, <first name> */

#include <stdio.h>

int main(void)
{
    char lastName[30];
    char firstName[30];

    printf("\n\n"); /* Blank lines for readability */

    printf("Please enter your first name: ");
    scanf("%s", firstName);
    printf("\n");
    printf("Please enter your last name: ");
    scanf("%s", lastName);
    printf("\n");

    printf("Your name will be filed as: %s, %s\n", lastName, firstName);


    printf("\n\n"); /* Blank lines for readability */

    return 0;
}
