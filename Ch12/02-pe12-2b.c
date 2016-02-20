// 02-pe12-2b.c
// compile with 02-pe12-2a.c

#include <stdio.h>
#include "02-pe12-2a.h"

int main(void)
{
    int mode;

    puts("\n");

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);

    while (mode >=0) {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }

    printf("Done.\n");

    puts("\n");

    return 0;
}
