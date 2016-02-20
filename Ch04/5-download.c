/* 5-download.c -- given speed of download in Mbs and size of download in MB */
/*                  program calculates and displays download time along with */
/*                  the user-supplied Mbs and MB, all to 2 decimal places    */

#include <stdio.h>

int main(void)
{
    float downloadspd = 0.0;   /* Mbs */ 
    float downloadsize = 0.0;  /* MB */
    float downloadtime = 0.0;  /* seconds */

    printf("\n\n");  /* Blank lines for readability */
    
    printf("Please enter the download speed (Mbs): ");
    scanf("%f", &downloadspd);
    printf("\n");
    printf("Please enter the size of the file (MB): ");
    scanf("%f", &downloadsize);
    printf("\n");

    downloadtime = (downloadsize * 8) / downloadspd;

    printf("At %.2f megabits per second (Mbs), a file of %.2f megabytes (MB) ", downloadspd, downloadsize);
    printf("downloads in %.2f seconds.\n", downloadtime); 

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

