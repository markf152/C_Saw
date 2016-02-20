/* 14-dig_pic_clean.c -- reads a text file consisting of 20 rows of 30    */
/* integers, each separated by a space.                                   */
/* The program outputs a crude picture representation, assigning 'darker' */
/* characters to each larger number.                                      */
/* The program also 'de-glitches' the picture, replacing any value that   */
/* differs by more than 1 from each of its neighbors with the average of  */
/* neighboring values.                                                    */
/* 0 -                                                                    */ 
/* 1 -    .....     .....                                                 */
/* 2 -    :::::     :::::                                                 */
/* 3 -    -----     ;;;;;                                                 */
/* 4 -    =====     ooooo                                                 */
/* 5 -    +++++     aaaaa                                                 */
/* 6 -    *****     OOOOO                                                 */
/* 7 -    #####     GGGGG                                                 */
/* 8 -    %%%%%     @@@@@                                                 */
/* 9 -    @@@@@     BBBBB                                                 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
    FILE * picfile;
    FILE * picoutfile;
    char picchar[20][31];
    int picnum[20][30];
    char greylvl_a[10] = {' ','.', ':', ';', 'o', 'a', 'O', 'G', '@', 'B'};
    char greylvl_b[10] = {' ','.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int i;
    int j;
    int x;
    int y;
    int neighbor_total;
    int neighbor_count;
    int deglitch;
    char ch;

    puts("\n");

    if (argc < 3) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((picfile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
          argv[1]);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++) {
            ch = getc(picfile);
            picnum[i][j] = ch - '0';   // -'0' converts char to int
            ch = getc(picfile);
        }
    }

//    printf("%d\n",(int)(8/3));
//    printf("%d",(int)((float)8/(float)3 + 0.5));

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++) 
            printf("%d", picnum[i][j]);
        printf("\n");
    }

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++) {
            neighbor_total = 0;
            neighbor_count = 0;
            deglitch = 0;
            for (y = i - 1; y <= i +1; y++) {
                if ((y < 0) || (y > 19))
                    continue;
                for (x = j - 1; x <= j + 1; x++) {
                    if ((x < 0) || (x > 29) || ((y == i) && (x == j)))
                        continue;
                    if (abs(picnum[y][x] - picnum[i][j]) > 1)
                        deglitch++;
                    neighbor_total += picnum[y][x];
                    neighbor_count++;
                }
            }
            if (deglitch == neighbor_count)
                picnum[i][j] = (int)((float)neighbor_total / (float)neighbor_count + 0.5);
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
          argv[1]);
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


