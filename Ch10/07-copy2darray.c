/* 07-copy2darray.c -- one 2D array to another */

#include <stdio.h>

void copy_2darr(double targ[][5], double sourc[][5], int d1, int d2);
void copy_arr(double targ[][5], double sourc[][5], int n, int d2);

int main(void)
{
    double source[][5] = { {1.1, 2.2, 3.3, 4.4, 5.5},
                           {6.6, 7.7, 8.8, 9.9, 1.2},
                           {2.3, 3.4, 4.5, 5.6, 6.7}
    };

    double target[3][5];

    int x;
    int y;

    printf("\n\n");
    printf("Before (source / target). . .\n");
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 5; y++) {
            printf("%.1f  / ", source[x][y]);
            printf("%.1f    ", target[x][y]);
        }
        printf("\n");
    }
    printf("\n"); 

    copy_2darr(target, source, 3, 5);

    printf("After (source / target) . . .\n");
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 5; y++) {
            printf("%.1f  / ", source[x][y]);
            printf("%.1f    ", target[x][y]);
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}

void copy_2darr(double targ[][5], double sourc[][5], int d1, int d2)
{
    int x;
    // printf("Processing . . .\n");
    for (x = 0; x < d1; x++) 
        copy_arr(targ, sourc, x, d2);
    // printf("\n");
}

void copy_arr(double targ[][5], double sourc[][5], int n, int d2)
{
    int x;

    for (x = 0; x < d2; x++) {
        // printf("%d:%d  %.1f         ", n, x, sourc[n][x]);
        targ[n][x] = sourc[n][x];
    }
    // printf("\n");
}


