/* 10-sum_arr.c -- sets each element in an array to the sum of the */
/* corresponding elements in two other arrays */

#include <stdio.h>

#define ROWS 3
#define COLS 5


void sum_arrs(int r, int c, int arr1[r][c], int arr2[r][c], int tot[r][c]);
void print_arr(int r, int c, int arr[r][c]);

int main(void)
{

    int array1[ROWS][COLS] = { {1,7,3,9,6},
                               {5,2,9,6,2},
                               {6,6,1,2,9}
    };

    int array2[ROWS][COLS] = { {5,5,3,9,1},
                               {9,8,4,6,2},
                               {1,1,7,4,3}
    };

    int array3[ROWS][COLS];

    printf("\n\n");

    printf("Array1 . . .\n");
    print_arr(ROWS, COLS, array1);

    printf("Array2 . . . \n");
    print_arr(ROWS, COLS, array2);

    printf("\n");
    printf("Adding elements of Array1 to Array2 and storing in Array3 . . .\n");
    printf("\n");
    sum_arrs(ROWS, COLS, array1, array2, array3);

    printf("Array3 . . .\n");
    print_arr(ROWS, COLS, array3);

    printf("\n\n");
    
    return 0;
}

void sum_arrs(int r, int c, int arr1[r][c], int arr2[r][c], int tot[r][c])

{
    int x; 
    int y;

    for (x = 0; x < r; x++)
        for (y = 0; y < c; y++)
            tot[x][y] = arr1[x][y] + arr2[x][y];
}

void print_arr(int r, int c, int arr[r][c])
{
    int x;
    int y;

    for (x = 0; x < r; x++) {
        for (y = 0; y < c; y++)
            printf("[%d][%d]: %2d  ", x, y, arr[x][y]);
        printf("\n");
    }
    printf("\n");
}

