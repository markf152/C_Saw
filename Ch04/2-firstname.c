/* firstname.c -- takes user's first name and displays it various ways */

#include <stdio.h>

int main(void)
{
    char firstName[30];

    printf("\n\n");  /* Blank lines for readability */

    printf("Please enter your first name: ");
    scanf("%s", firstName);
    printf("\n");

    printf("Your name . . .\n\n");

    printf(". . . in double quotes:\n \"%s\"\n\n", firstName);

    printf(". . . in field 20 chars wide, whole field in quotes, name at right end of field:\n");
    printf("\"%20s\"\n", firstName);
    printf(" 123456789|123456789|\n\n");

    printf(". . . in field 20 chars wide, whole field in quotes, name at left end of field:\n");
    printf("\"%-20s\"\n", firstName);
    printf(" 123456789|123456789|\n\n");

    printf(". . . in a field 3 chars wider than the name:\n");
    printf("%*s\n", (strlen(firstName) + 3), firstName);
    printf("123");

    printf("\n\n");  /*Blank lines for readability */
}
