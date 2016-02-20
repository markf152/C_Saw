/* 13-double.c -- takes user input to fill a 3x5 arrray of double */
/* -- computes the average of each set of five values */
/* -- computes the average of all of the values */
/* -- determines the largest value of all fifteen */
/* -- reports the results */

#include <stdio.h>

#define ROWS 3
#define COLS 5


void print_arr(double array[][COLS], int r);
void row_avg(double array[COLS], int r);
void all_avg(double array[][COLS], int r);
void largest(double array[][COLS], int r);

int main(void)
{
//    double array[3][5];
    double array[3][5] = { {1.1, 1.2, 1.3, 1.4, 1.5},
                           {2.1, 2.2, 2.3, 2.4, 2.5},
                           {3.1, 3.2, 3.3, 3.4, 3.5}
    };
    int y;
    int x;

    printf("\n\n");

//    printf("Enter the first series of 5 floating point values. Separate each with a space\n");
//    for (y = 0; y < 3; y++) {    
//        for (x = 0; x < 5; x++)
//            scanf("%lf", (array[y] + x));
//        printf("Enter the next series of 5 floating point values. Separate each with a space\n");
//    }

    print_arr(array, ROWS);
    
    for (x = 0; x < ROWS; x++)
        row_avg(array[x], x);
    printf("\n");

//    row_avg(array, ROWS);

    all_avg(array, ROWS);

    largest(array, ROWS);

    printf("\n\n");

    return 0;
}

void print_arr(double array[][COLS], int r)
{
    int y;
    int x;

    printf("Contents of 'array' . . .\n");
    for (y = 0; y < r; y++) {
        for (x = 0; x < COLS; x++)
            printf("[%d][%d]: %.1f  ", x, y, array[y][x]);
        printf("\n"); 
    }
    printf("\n");
}

void row_avg(double array[COLS], int r)
{
    int x;
    double row_tot = 0;
    
    for (x = 0; x < COLS; x++)
       row_tot += array[x];
    printf("The average value of row %d = %.1f\n", r, (row_tot / COLS));
}

void all_avg(double array[][COLS], int r)
{
    int y;
    int x;
    double total = 0;

    for (y = 0; y < r; y++) {
        for (x = 0; x < COLS; x++)
           total += array[y][x];
    }
    
    printf("The average value of all elements of 'array' = %.1f\n", (total / (COLS * r)));
}    

void largest(double array[][COLS], int r)
{
    int y;
    int x;
    double largest;

    largest = array[0][0];
    for (y = 0; y < r; y++) {
        for (x = 0; x < COLS; x++)
           if (array[y][x] > largest)
               largest = array[y][x];
    }
    
    printf("The largest value in 'array' = %.1f\n", largest);
}    
