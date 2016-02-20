/* 04-firstwordn.c -- reads the first word from a line of input */
/* - ignores leading white space characters */
/* - discards rest of line after first word */
/* - stops after a specified number of characters is read */

#include <stdio.h>
#include <ctype.h>

#define NUM 15

char * firstword(char * str, int n);

int main(void)
{

    char * str;
    char string[80];

    str = string;

    puts("\n"); 

    puts("Type a line of text . . .");
    
    firstword(str, NUM);

    puts(str);

    return 0;

}

char * firstword(char * str, int n)
{
    int i = 0;
    char c = ' ';

    while (isspace(c)) {
        c = getchar();
//        printf("%c", c);
    }
//    printf("\n");

    while (! isspace(c) && i < n) {
        str[i] = c;
        i++;
//        printf("%d", i);
        c = getchar();
    }

    str[i] = '\0'; 

    if (c != '\n')
        while (getchar() != '\n')
            continue;

    return (str);

}



