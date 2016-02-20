/* input.c -- when to use & */

#include <stdio.h>

int main(void)
{
    int age;
    float assets;
    char pet[30];
    
    printf("\n\n");    /* Blank lines for readability */

    printf("Enter your age, assets, and favorite pet.\n");
    scanf("%d %f", &age, &assets);
    scanf("%s", pet);
    printf("%d $%.2f %s\n", age, assets, pet);

    printf("\n\n");    /* Blank lines for readability */
}
