/* Q_12.c -- program to test a function that takes a string pointer */
/* and returns a pointer to the first space character in the string */
/* if no space characters found in the string, it returns NULL */

#include <stdio.h>
#include <ctype.h>

#define SPACE 32

char * s_gets(char * st, int n);
char * find_space(char * st);

int main(void)
{
    char string[80];
    char * loc;

    puts("\n");

    puts("Enter a string . . .");
    s_gets(string, 80);

    loc = find_space(string);

    printf("The memory location of the beginning of your string is: %p\n", string);

    if (loc)
        printf("The memory location of the first space character in that string is: %p\n", loc);
    else
        printf("There are no space characters in that string.\n");

    printf("\n");

    puts(string);

    puts("\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;

    ret_val = fgets(st, n, stdin);
    
    if (ret_val) {
        while (*st !='\n' && *st != '\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

char * find_space(char * st)
{
    char * loc = NULL;

    if (st)  {
        do {
            if (*st == ' ') {
                loc = st;
            }
            st++;
        } while (*st !='\n' && *st != '\0');
    }
    return loc;
}

