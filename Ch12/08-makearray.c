/* 08-makearray.c -- user inputs the number of elements of a one-dimensional array */
/* along with an initialization value that will be applied to each element */
/* The program uses malloc() to create the array */

#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main (void)
{
    int *pa;
    int size;
    int value;

    puts("\n");
    
    printf("Enter the number of elements: ");

    while (scanf("%d", &size) == 1  && size > 0) {
        printf("Enther the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa) {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (< 1 to quit): ");
    }
    printf("Done.\n");

    puts("\n");
    
    return 0;
}

int * make_array(int elem, int val)
{
    int * arr_ptr;
    int i;
    
    arr_ptr = (int *) malloc(elem * sizeof(int));
    for (i = 0; i < elem; i++)
        arr_ptr[i] = val;

    return (arr_ptr);
}

void show_array(const int ar[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%4d", ar[i]);

        if (((i + 1) % 8) == 0 || i == (n-1))
            printf("\n");
    }
}


