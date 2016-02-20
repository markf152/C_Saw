/* Q_10.c -- create a function that duplicates the function of strlen() */

#include <stdio.h>

int stringlen(const char * str);

int main(void)
{
    char string[80];

    puts("\n");

    printf("Enter a line of text . . . \n");
    scanf("%s", string);
    printf("The length of that string is : %d", stringlen(string));
   
    puts("\n");

    return 0;
}
 
int stringlen(const char * str)
{

    int x = 0;

    while (str[x] != EOF && str[x] != '\0' && str[x] != '\n') 
        x++;

    return x;

}

