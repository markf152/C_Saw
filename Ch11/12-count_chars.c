/* 12-count_chars.c -- reads input up to EOF; reports number of: */
/* - words                                                       */
/* - uppercase letters                                           */
/* - lowercase letters                                           */
/* - punctuation characters                                      */
/* - digits                                                      */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char input[1025];
    int ct = 0;
    int words = 0;
    int ucase_ltrs = 0;
    int lcase_ltrs = 0;
    int punct_chars = 0;
    int digits = 0;
    int new_word = 1;

    puts("\n");

    printf("Enter characters (up to 1024). Terminate input with Ctrl-D\n");
    while ((input[ct] = getchar()) != EOF && ct < 1024)
        ct++;
    input[ct] = '\0';
    puts("\n");

//    puts(input);

    ct = 0;

    while (input[ct] != '\0') {
//        printf("input[%d] = %c\n", input[ct], input[ct]);
        if (!isspace(input[ct])) {
            if (new_word) {
                new_word = 0;
                words++;
            }
        }
        if (isspace(input[ct]) && !new_word)
            new_word = 1;
        else if (isupper(input[ct]))
            ucase_ltrs++;
        else if (islower(input[ct]))
            lcase_ltrs++;
        else if (ispunct(input[ct]))
            punct_chars++;
        else if (isdigit(input[ct]))
            digits++;
//        printf("ct = %d\n", ct);
        ct++;
    }

    printf("The number of words in the input is: %d\n", words);
    printf("The number of uppercase characters in the input is: %d\n", ucase_ltrs);
    printf("The number of lowercase characters in the input is: %d\n", lcase_ltrs);
    printf("The number of punctuation characters in the input is: %d\n", punct_chars);
    printf("The number of digits in the input is: %d\n", digits);

    puts("\n");

    return 0;
}



