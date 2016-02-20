/* Q_09.c -- test re-written s_gets function */
/* function re-written in pointer notation vs array notation */

#include <stdio.h>
#include <string.h>

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
        if (strchr(st, '\n'))
            *(strchr(st, '\n')) = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
