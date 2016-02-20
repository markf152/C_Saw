/* 01-getnchar.c -- fetches the next n characters from input */
/* incl blanks, tabs and newlines; stores the results in an */
/* array whose address is passed as an argument */

#include <stdio.h>

#define NUM 10

char * get_n_char(char * str, int n);

int main(void)
{
    char string[80];
    char * str = string;

    puts("\n");

    get_n_char(str, NUM);

    puts(str);

    puts("\n");
    
    return 0;
}


char * get_n_char(char * str, int n)
{
    int x;

    for (x = 0; x < n; x++) {
        str[x] = getchar();
//        printf("%d ", x);
        if (str[x] == EOF) {
            printf("<EOF . . . break>\n");
            break;
        }
    }
//    printf("%d", x);
//    printf("\n");

    str[x] = '\0';

    return (str);
}

