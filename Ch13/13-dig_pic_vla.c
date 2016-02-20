/* 13-dig_pic_vla.c -- reads a text file consisting of 20 rows of 30 integers */
/* each separated by a space                                                  */
/* The program outputs a crude picture representation, assigning 'darker'     */
/* characters to each larger number                                           */
/* 0 -                                                                        */ 
/* 1 -    .....     .....                                                     */
/* 2 -    :::::     :::::                                                     */
/* 3 -    -----     ;;;;;                                                     */
/* 4 -    =====     ooooo                                                     */
/* 5 -    +++++     aaaaa                                                     */
/* 6 -    *****     OOOOO                                                     */
/* 7 -    #####     GGGGG                                                     */
/* 8 -    %%%%%     @@@@@                                                     */
/* 9 -    @@@@@     BBBBB                                                     */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
    FILE * picfile;
    FILE * picoutfile;
    char greylvl_a[10] = {' ','.', ':', ';', 'o', 'a', 'O', 'G', '@', 'B'};
    char greylvl_b[10] = {' ','.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int i;
    int j;
    char ch;
    char * endptr;
    int rows;
    int cols;

    puts("\n");

    if (argc < 5) {
        fprintf(stderr, "Usage: %s filename rows cols\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((picfile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
          argv[1]);
        exit(EXIT_FAILURE);
    }

    rows = (int)(strtol(argv[3], &endptr, 10)); 
    cols = (int)(strtol(argv[4], &endptr, 10));
    printf("rows = %d \n cols = %d\n\n", rows, cols);
    char picchar[rows][cols + 1];
    int picnum[rows][cols];

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++) {
            ch = getc(picfile);
            picnum[i][j] = ch - '0';   // -'0' converts char to int
            ch = getc(picfile);
        }
    }

    fclose(picfile);            

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++) 
            printf("%d", picnum[i][j]);
        printf("\n");
    }
    
    puts("\n");

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++) 
            picchar[i][j] =  greylvl_b[picnum[i][j]];
        picchar[i][30] = '\0';
    }

    if ((picoutfile = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
          argv[2]);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 20; i++) {
        puts(picchar[i]);
        fputs(picchar[i], picoutfile);
        fputc('\n', picoutfile);
    }
    
    fclose(picoutfile);

    puts("\n");

    return 0;

}


