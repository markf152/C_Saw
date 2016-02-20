/* 05-findchar.c -- searches specified string and returns pointer to */
/* the first occurence of a specified character; null if character not found */

#include <stdio.h>
#include <string.h>


char * findchar(char * str, char ch);

int main(void)
{
    char * string[10] = { "frghanjies",
                          "fxergerkmgkrg",
                          "plwefplweplplpx",
                          "x",
                          "123gegx",
                          "gttf5ggx",
                          "sdfvg xxg5",
                          "kmfvkkmvvx",
                          "sfdbdfgfdxvfx",
                          "wefgergerxx12" };
    char * chr;
    int i;

    for (i = 0; i < 10; i++) {
        chr = findchar(string[i], 'x');
        printf("%15s  %p  %p\n", string[i], string[i], chr);
    }

    puts("\n");

    return 0;

}

char * findchar(char * str, char ch)
{

//    printf("%c\n", ch);
//    puts(str);
    while (*str != '\0' && *str != '\n' && *str != EOF) {
        if (*str == ch)
            return str;
//        printf("%c", *str);
        str++;
    }
    printf("\n");
    
    return (NULL);

}

