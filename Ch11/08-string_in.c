/* 08-string_in.c -- takes 2 string pointers as arguments; returns address */
/* if 2nd string is found within the 1st, otherwise a null pointer */
/* Text Location: 13941 */
/* char * strstr(const char * s1, const char * s2) */

#include <stdio.h>
#include <string.h>

char * string_in(char * s1, char * s2);
int check_word(char * s1, char * s2);
char * s_gets(char * st, int n);

int main(void)
{
    char * s1;
    char * s2;
    char * s3;
    char str1[40];
    char str2[40];

    s1 = str1;
    s2 = str2;

    puts("\n");

    printf("Enter a string: ");
    s_gets(s1, 40);
    printf("Enter a string to search for within the first string: ");
    s_gets(s2, 40);
    
    printf("\n");

    s3 = string_in(s1, s2);
    printf("s3 - %p\n", s3);
    printf("String 1 address is:                               %p\n", s1);
    if (s3)
        printf("String 2 found within String 1 starting at address %p\n", s3);
    else
        printf("String 2 was not found within String 1\n");

    puts("\n");

    return 0;
}

char * string_in(char * s1, char * s2)
{
    int i;
    int loop = (1 + (int)(strlen(s1) - strlen(s2)));
    int found;

    for (i = 0; i < loop; i++, s1++) {
        printf("------------\n");
        if (check_word(s1, s2))  {
            return s1;
        }
    }
    return (NULL);
}

int check_word(char * s1, char * s2)
{
    int ret_val = 0;

    if (*s1++ == *s2++)
        if (*s2 == '\0')
            return 1;
        else 
            check_word(s1, s2);
    else 
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

