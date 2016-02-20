// 03-pe12-2b.c
// compile with 03-pe12-2a.c

#include <stdio.h>
#include "03-pe12-2a.h"

void set_mode(int * modeChoice);
void get_info(int mode, float * distance, float * fuelConsumed);
void show_info(int mode, float fuelConsumed, float distance);

int main(void)
{
    int mode;
    float distance;
    float fuelConsumed;

    puts("\n");

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);

    while (mode >=0) {
        set_mode(&mode);
        get_info(mode, &distance, &fuelConsumed);
        show_info(mode, distance, fuelConsumed);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }

    printf("Done.\n");

    puts("\n");

    return 0;
}
