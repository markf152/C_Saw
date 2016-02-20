/* 07-mystrncpy.c -- tests my version of the strncpy() function */

#include <stdio.h>
#include <string.h>

#define NUM 10

char * mystrncpy(char * s1, char * s2, int n);
char * s_gets(char * st, int n);

int main(void)
{
    char string1[100] = "xxxxxxxxxxxx";
    char string2[100];

    char * test1 = string1; 
    char * test2 = string2;
 
    int x;

    puts("\n");

    while (s_gets(test2, NUM)) {
 
        printf("test1 = %s\n", test1);
        printf("test2 = %s\n\n", test2);
    
        printf("mystrncpy(test1, test2, %d)\n\n", NUM);
        mystrncpy(test1, test2, NUM);

        printf("test1 = %s\n", test1);
        for (x = 0; x < NUM; x++)
            printf("%d ", *(test1++));
        printf("\n");
        printf("test2 = %s\n", test2);
    }

    puts("\n");
    return 0;
}

char * mystrncpy(char * s1, char * s2, int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++) {
//        printf("%d", i);
        if (*s2 == '\0' || *s2 == '\n' || *s2 == EOF) {
            *s1 = '\0';
            s1++;
            for (j = (i+1); j < n; j++)
                *(s1++) = 0; 
//            printf("break\n");
            break;
        }
//        else
//            printf("else\n");
        *s1++ = *s2++;
        if (i == (n - 1)) {
//            printf("9\n");
            *s1 = '\0';
        }
    }
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

