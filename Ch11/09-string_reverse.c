/* 09-string_reverse.c -- takes string and replaces contents */
/* with the string reversed */

#include <stdio.h>
#include <string.h>

#define MAX 80

char * string_rev(char * str);
char * s_gets(char * st, int n);

int main(void)
{
    char string[MAX];
    char * str = string;

    puts("\n");

    printf("Enter a string: ");
    while (s_gets(string, MAX) && *string !='\0') {
        printf("The original string:   %s\n", str);
        printf("The string in reverse: %s\n", string_rev(str));
        printf("\n");
        printf("Enter another string (blank line to quit): ");
    }
        
    puts("\n");

    return 0;
}

char * string_rev(char * str)
{
    char string[MAX];
    char * str_temp = string;
    int i;
    int length = (int)strlen(str);

    str = str + length - 1;

    for (i = 0; i < length; i++, str_temp++, str--) 
        *str_temp = *str;

    *str_temp = '\0';
    str_temp = str_temp - length;

    return str_temp;
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

