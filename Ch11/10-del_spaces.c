/* 10-del_spaces.c -- takes a string as input and removes any spaces */

#include <stdio.h>
#include <string.h>

#define MAX 80

char * del_spaces(char * str);
char * s_gets(char * st, int n);

int main(void)
{
    char string[MAX];
    char * str;

    puts("\n");

    printf("Enter a string: ");

    while (s_gets(str, MAX) && (str[0] != '\0')) {
        printf("Here is your string with spaces removed . . .\n");
        puts(del_spaces(str));
        printf("--------------\n\n");
        printf("Enter another string: ");
    }

    puts("\n");

    return 0;
}

char * del_spaces(char * str)
{
    int i = 0;
    int j;

    while (str[i] != '\0') 
        if (str[i] == ' ') 
            for (j = i; j < ((int)(strlen(str))); j++) 
                str[j] = str[j + 1];
        else
            i++;
    return str;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

