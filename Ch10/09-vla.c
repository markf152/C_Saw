/* 09-vla.c -- use VLA-based functions to copy and display an array */

/* initialize 3x5 array of double; use VLA-based function to copy it to a second */
/* 2D array; use a VLA-based function to display the contents of the two */
/* arrays; functions should be capable in general of processing */
/* arbitrary NxM arrays */

#include <stdio.h>

int main(void)
{

    void copy_vla(int r, int c, double sourc[][c], double targ[][c]);
    void display_vla(int r, int c, double array[][c]);

    double array1[3][5] = { {1.1, 1.2, 1.3, 1.4, 1.5},
                            {2.1, 2.2, 2.3, 2.4, 2.5},
                            {3.1, 3.2, 3.3, 3.4, 3.5}
    };

    double array2[3][5];

    printf("\n\n");

    printf("Array1 before the copy . . .\n");
    display_vla(3,5,array1);

    printf("Array2 before the copy . . .\n");
    display_vla(3,5,array2);

    printf("Copying Array1 --> Array2 . . .\n\n");

    copy_vla(3,5,array1,array2);

    printf("Array2 after the copy . . .\n");
    display_vla(3,5,array2);

    printf("\n\n");

    return 0;
}

void copy_vla(int r, int c, double sourc[][c], double targ[][c])
{
    int x;
    int y;

    for (x = 0; x < r; x++)
        for (y =0; y < c; y++)
            targ[x][y] = sourc[x][y];

}

void display_vla(int r, int c, double array[][c]) 
{
    int x;
    int y;

    for (x = 0; x < r; x++) {
        for (y = 0; y < c; y++)
            printf("[%d][%d]: %.1f  ", x, y, array[x][y]);
        printf("\n");
    }
    printf("\n");
}

