/* iswithin.c -- searches specified string and returns a true (non-zero) value */
/* if the string containes a specified character; null if character not found */
//13918

#include <stdio.h>
#include <string.h>


_Bool findchar(char * str, char ch);

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
    _Bool found; 
    int i;

    for (i = 0; i < 10; i++) {
        found = findchar(string[i], 'x');
        printf("%15s . . .  x ", string[i]);
        if (!found)
            printf("not ");
        printf("found.\n");
    }

    puts("\n");

    return 0;

}

_Bool findchar(char * str, char ch)
{

//    printf("%c\n", ch);
//    puts(str);
    while (*str != '\0' && *str != '\n' && *str != EOF) {
        if (*str == ch)
            return 1;
//        printf("%c", *str);
        str++;
    }
    printf("\n");
    
    return 0;

}

