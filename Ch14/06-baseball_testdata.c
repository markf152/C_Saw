//06-baseball_testdata.c -- program creates a text file full of random
//data to test program 06-baseball.c

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define DEFAULT_NUM 100


int main(int argc, char * argv[])
{
    FILE * fp;      // file pointer
    char * chrptr;
    int playernum;
    int numatbat;
    int hits;
    int walks;
    int rbi;
    int num;
    int i;
    int j;

    char chbuf[10]; // TEST
    float value = 0.326;  // TEST
    char outstring[100];

    struct player {
        char fname[30];
        char lname[30];
    };

    struct player plist[19] = {
        {"Michael", "Jones"},
        {"Steven", "Smith"},
        {"Theodore", "Wiliams"},
        {"James", "Franklin"},
        {"Wilson", "Michaels"},
        {"Albert", "Yankovick"},
        {"Cedric", "Lee"},
        {"John", "Ames"},
        {"Izake", "Ozuno"},
        {"Dennis", "Hazelwood"},
        {"Ezra", "Jackson"},
        {"Jacob", "Paulson"},
        {"Andrew", "Sherman"},
        {"Amos", "Patton"},
        {"Orson", "Bradley"},
        {"Harold", "Green"},
        {"Benjamin", "Brown"},
        {"Gerald", "Black"},
        {"Melvin", "White"}
    };

    puts("\n");

    srand((unsigned int)time(0));
    if (argc == 2) {
        printf("%s\n", argv[1]);
        if (isdigit(argv[1][0])) {
            num = strtol(argv[1], &chrptr, 10);
            printf("isdigit\n");
        }
    }
    else {
        num = DEFAULT_NUM;
        printf("Used DEFAULT_NUM\n");
    }

// open file "w+" . . . truncates file to zero length if it exists
//                      or creates the file it if doesn't exist
// location 15557

// strcat() or strncat() which might be better

    if ((fp = fopen("06-baseball_testdata.txt", "w+")) == NULL) {
        printf("Unable to open file 'bballtestdata.txt; terminating");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < num; i++) {
        playernum = rand() % 19;
        if (playernum > 9)
            snprintf(chbuf, 3, "%d ", playernum);
        else
            snprintf(chbuf, 2, "%d ", playernum);
        strncpy(outstring, chbuf, 3);
        strncat(outstring, " ", 1);

        strncat(outstring, plist[playernum].fname, 30);
        strncat(outstring, " ", 1);
        strncat(outstring, plist[playernum].lname, 30);
        strncat(outstring, " ", 1);
    
        numatbat = rand() % 4 + 1;
        snprintf(chbuf, 2, "%d", numatbat);
        strncat(outstring, chbuf, 2);
        strncat(outstring, " ", 1);

        hits = rand() % numatbat;
        if (hits < 0)
            hits = 0;
        if (hits > numatbat)
            hits = numatbat;
        snprintf(chbuf, 2, "%d", hits);
        strncat(outstring, chbuf, 2);
        strncat(outstring, " ", 1);

        if (hits == numatbat)
            walks = 0;
        else
            walks = rand() % (numatbat - hits) + 1; 
        snprintf(chbuf, 2, "%d", walks);
        strncat(outstring, chbuf, 2);
        strncat(outstring, " ", 1);

        rbi = 0;
        for (j = 0; j < hits; j++) 
            rbi += rand() % 4 + 1;
        snprintf(chbuf, 2,"%d", rbi);
        strncat(outstring, chbuf, 2);
        strncat(outstring, " ", 1);

        strncat(outstring, "\n", 1);
       
        printf("%s", outstring);
        fprintf(fp, "%s", outstring);
//        printf("Loop %d\n", i);
    }
    
    fclose(fp);

    puts("\n");

    return 0;
}
