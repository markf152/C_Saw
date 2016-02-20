/* scanftest.c -- test return value of scanf() */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int result;
    int num;
    int sets = 0;
    char numstr[100];
    char * ptr;
    int i = 0;

    printf("Enter an integer: ");
    result = scanf("%d", &num);
    printf("Got the input\n");
//
//    printf("scanf() return value is: %d\n", result);
//    printf("Value read by scanf is: %d\n", num);

    do {
        printf("Enter the number of sets; enter q to stop: ");
        i = 0;
//        if (scanf("%d", &sets) != 1);
            numstr[i] = getchar();
            if (numstr[i] == '\n')
                numstr[i] = getchar();

//            putchar(124);
//            putchar(numstr[i]);
//            putchar(124);

            while (numstr[i] != '\n') {
                i++;
                numstr[i] = getchar();
            }
        printf("End while loop:\n");
        if (numstr[0] == 'q')
            sets = 'q';
        else
            sets = strtol(numstr, &ptr, 10);
        printf("sets = %d\n", sets);
    } while (sets < 1 && sets != 'q'); 
}

