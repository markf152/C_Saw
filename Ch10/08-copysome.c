/* 08-copysome.c -- copies arrays using functions with different */
/* methods of passing information from the main program */

#include <stdio.h>

#define BEGIN 3

void copy_arr(double * targ, double * sourc, int b);

int main(void)
{
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target1[3];

    int x;
    int begin = BEGIN - 1;

    printf("\n\n");
    
    copy_arr(target1, source, begin);
    for (x = 0; x < 3; x++) {
       printf("source[%d]: %.1f\n", (x + begin), (source[(x + begin)]));
       printf("target1[%d]: %.1f\n", x, (target1[x]));
       printf("\n");
    }
    printf("\n");

    printf("\n\n");

    return 0;
}

void copy_arr(double * targ, double * sourc, int b)
{
    int x;

    for (x = 0; x < 3; x++) 
        targ[x] = sourc[x + b];
} 
