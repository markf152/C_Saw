//testequal.c -- a quick program to test something I'm not sure I understand
// about assigning values to variables . . . .

#include<stdio.h>
#include<string.h>

char * s_gets(char * st, int n);

int main(void)
{
    int a = 3;
    int b = 4;
    int c = 0;
    char del[5];
    
    puts("\n");

    printf("a = %d   b = %d   c = %d\n\n", a, b, c);

    printf("Setting c = (b = a) . . .\n\n");
    if ((c = (b = a)) == 3)
        printf("Test passed . . . c == %d\n\n", c);
    else 
        printf("Something went wrong\n\n");
    
    printf("Type 'del' to remove this book from the list or\n");
    printf("hit <return> to continue.\n");
    if (s_gets(del, 4) != NULL && !strcmp(del, "del"))
        printf("It worked . . . del = %s", del);
    else
        printf("It did not work . . . del = %s", del);

    puts("\n");
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
