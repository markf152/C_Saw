/* Q_13.c -- modified version of listing 11.21 (compare.c)  */
/* to use ctype.h functions to recognize a correct answer */
/* regardless of uppercase / lowercase usage in the answer */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ANSWER "Grant"
#define SIZE 40

char * s_gets(char * st, int n);
char * strtolwr(char * st);

int main(void)
{
    char try[SIZE];
    int x = 0;
    char answer[80];

    strcpy(answer, ANSWER);
    strtolwr(answer);

    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    strtolwr(try);
    while (strcmp(try, answer) != 0) {
        puts("No, that's wrong.  Try again.");
        s_gets(try, SIZE);
        strtolwr(try);
    }
    puts("That's right!");

    puts("\n");

    return 0;
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

char * strtolwr(char * st)
{
    int x = 0;

    while (st[x]) {
        st[x] = tolower(st[x]);
        x++;
    }
    return (st);
}

