/* 11-2x_arr.c -- displays values in a 3x5 array; doubles the values */
/* and displays the new values */

#include <stdio.h>

#define ROWS 3
#define COLS 5

int main(void)
{


    void x2_arr(int arr[][COLS], int r);
    void print_arr(int arr[][COLS], int r);

    int array[ROWS][COLS] = { {1,7,3,9,6},
                              {5,2,9,6,2},
                              {6,6,1,2,9}
    };

    printf("\n\n");

    printf("Array . . .\n");
    print_arr(array, ROWS);

    printf("\n");
    printf("Doubling the value of each element in Array . . .\n");
    printf("\n");
    x2_arr(array, ROWS);

    printf("Array with values doubled . . .\n");
    print_arr(array, ROWS);

    printf("\n\n");
    
    return 0;
}

void x2_arr(int arr[][COLS], int r)

{
    int x; 
    int y;

    for (x = 0; x < r; x++)
        for (y = 0; y < COLS; y++)
            arr[x][y] = 2 * arr[x][y];
}

void print_arr(int arr[][COLS], int r)
{
    int x;
    int y;

    for (x = 0; x < r; x++) {
        for (y = 0; y < COLS; y++)
            printf("[%d][%d]: %2d  ", x, y, arr[x][y]);
        printf("\n");
    }
    printf("\n");
}

