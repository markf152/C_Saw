/* running.c -- A useful(?) program for runners */

#include <stdio.h>

const int S_PER_M = 60;    /* Seconds in a minute */
const int S_PER_H = 3600;  /* Seconds in an hour */
const double M_PER_K = 0.62137;  /* Miles in a kilometer */

int main(void)
{
    double distk;  /* Distance run in km */
    double distm;  /* Distance run in statute miles*/
    double rate;   /* Average speed in mph */
    int min;       /* minutes of running time */
    int sec;       /* seconds of running time */
    int time;      /* running time in seconds only */
    double mtime;  /* time in seconds for one mile */
    int mmin;      /* minutes portion of one mile time */
    int msec;      /* seconds portion of one mile time */

    printf("\n\n");  /* Blank lines for readability */

    printf("This program converts your time for a metric race\n");
    printf("to a time for running a mile nd to your average\n");
    printf("speed in miles per hour.\n\n");
    printf("Please enter, in kilometers, the distance run: "); 
    scanf("%lf", &distk);  /* %lf for type double */
    printf("Next enter the time in minutes and seconds.\n");
    printf("Begin by entering the minutes: ");
    scanf("%d", &min);
    printf("Now enter the seconds: ");
    scanf("%d", &sec);
    
/* Converts time to pure seconds */
    time = S_PER_M * min + sec;
/* Converts kilometeres to miles */
    distm = M_PER_K * distk;
/* Miles per sec x sec per hour = mph */
    rate = distm / time * S_PER_H;
/* Time / distance = time per mile */
    mtime = (double) time / distm;
    mmin = (int) mtime / S_PER_M;  /* Find whole minutes */
    msec = (int) mtime % S_PER_M;  /* Find remaining seconds */
    printf("You ran %1.2f km (%1.2f miles) in %d min, %d sec.\n",
           distk, distm, min, sec);
    printf("That pace corresponds to running a mile in %d min, %d sec.\n", 
           mmin, msec);
    printf("Your average speed was %1.2f mph.\n", rate);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

