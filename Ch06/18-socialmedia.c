/* 18-socialmedia.c -- calculates the number of persons in a social media group  */
/* based on a set rate of people joining and leaving the group.  It displays the */
/* weekly total until the group size reaches Dunbar's numer (150).               */

#include <stdio.h>

#define INITFRIENDS 5
#define DUNBAR 150

int main(void)
{
    int group = INITFRIENDS;
    int week = 1;

    printf("\n\n");  /* Blank lines for readability */

    while (group <= DUNBAR) {
        group = 2 * (group - week);
        printf("Week %d: - %d friends in the group\n", week, group);
        ++week;
    } 

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
    
