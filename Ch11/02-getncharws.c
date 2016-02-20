/* 02-getncharws.c -- fetches the next n characters from input */
/* stops at the first blank, tab or newline if before the nth char */
/* stores the results in an array whose address is passed as an argument */

#include <stdio.h>
#include <ctype.h>

#define NUM 10

char * get_n_char(char * str, int n);

int main(void)
{
    char string[80];
    char * str = string;

    puts("\n");

//    printf("str = %p\n", str);

    if (get_n_char(str, NUM))
        puts(str);
    else
        puts("Input error");

    puts("\n");
    
    return 0;
}

char * get_n_char(char * str, int n)
{
    int x;

    for (x = 0; x < n; x++, str++) {
//        printf("str = %p\n", str);
        *str = getchar();
//        printf("str = %p  x = %d\n", str, x);
        if (*str == EOF) {
            str = NULL;
//            printf("str = %p\n", str);
            break;
        }
        if (*str == '\t' || *str == ' ' || *str == '\n')  {
            *str = '\0';
            break;
        } 
    }
                
//    printf("\nstr = %p  x = %d\n", str, x);

    if (str && *str != '\0') {
        *str = '\0';
//        puts("*(++str) = '\\0'");
    }
//    printf("str = %p\n", str);
    return (str);
}

