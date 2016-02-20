/* array26.c -- creates an array with 26 elements in it;     */
/*              stores the 26 lowercase letters in it; and   */
/*              prints out the array contents.               */

#include <stdio.h>

int main(void)
{
    char charArray[26];
    int x;

    printf("\n\n");  /* Blank lines for readaility */

    for (x = 0; x < 26; x++) {
        charArray[x] = x + 97;  /* 97 is the ASCII code for 'a' */
        printf("%d: %c\n", x, charArray[x]);
    }

    printf("\n\n");  /* Blank lines for readaility */

    return 0;
}

