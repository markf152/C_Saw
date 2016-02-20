/* 03-firstword.c -- reads the first word from a line of input */
/* - ignores leading white space characters */
/* - discards rest of line after first word */

#include <stdio.h>
#include <ctype.h>

char * firstword(char * str);

int main(void)
{

    char * str;
    char string[80];

    str = string;

    puts("\n"); 

    puts("Type a line of text . . .");
    
    firstword(str);

    puts(str);

    return 0;

}

char * firstword(char * str)
{
    int i = 0;
    char c = ' ';

    while (isspace(c)) {
        c = getchar();
//        printf("%c", c);
    }
//    printf("\n");

    while (! isspace(c)) {
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



