/* 16-input_echo.c -- reads input up to EOF and echoes it to the display */
/* subject to the following command line argumenets: */
/*  -p  print input as is */
/*  -u  print input in upper case */
/*  -l  print input in lower case */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char * argv[])
{

    char ch;
    char action;

    puts("\n");

//    printf("argv[1] = %s\n", argv[1]);
//    printf("argv[1][0] = %c\n", argv[1][0]);

    if (argv[1][0] == '-')
        if (argv[1][1] == 'u')
            action = 'u';
        else if (argv[1][1] == 'l')
            action = 'l';
        else
            action = 'p';

//    printf("action = %c\n", action);

    while ((ch = getchar()) != EOF) {
        switch (action) {
            case 'u' :
                ch = toupper(ch);
                break;
            case 'l' :
                ch = tolower(ch);
                break;
        }
        printf("%c", ch);
    }

    puts("\n");

}

