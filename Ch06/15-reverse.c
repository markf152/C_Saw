/* 15-reverse.c -- reads a line (255 chars max) and prints it out in reverse order */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[255];
    char ltr;
    int x = 0;

    printf("\n\n");  /* Blank lines for readability */

/*    for (x = 0; x < 255; x++) */
/*        line[x] = '*'; */
/*    x = 0; */

    printf("Enter a line of text, 255 charactrers max.\n");
    do {
        scanf("%c", &ltr);
        line [x] = ltr;
        x++;
    } while (ltr != '\n');
/*    printf("%c  |  %d\n", line[x], line[x]); */
    line[x - 1] = '\0'; 

    x = (int)strlen(line) - 1;

    do {
        printf("%c", line[x]);
        x--;
    } while (x != -1);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
