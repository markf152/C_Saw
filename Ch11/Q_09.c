/* Q_09.c -- test re-written s_gets function */
/* uses pointer vs array notation */

#include <stdio.h>

char * s_gets(char * st, int n);

int main(void)
{
    char string[80];

    puts("\n");

    puts("Enter a string . . .");
    s_gets(string, 80);

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
