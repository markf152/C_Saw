// 06-baseball.c -- reads baseball stats on players in from a text file
// popultes a structure array with an entry for each player and then
// calculates and stores in the structure each player's batting average


// programming exercise text location 18136

// 5 Bob Smith 5 2 1 1
//     at bats |
//          hits |
//           walks |
//               RBI |



#include<stdio.h>
#include<stdlib.h>

#define TEAMSIZE 19

struct playerRec {
    int num;
    char f_name[30];
    char l_name[30];
    int atBat;
    int hits;
    int walks;
    int rbi;
    float batavg;
};


int main(void)
{

    struct playerRec team[19] = {
        {0, "Michael", "Jones"},
        {1, "Steven", "Smith"},
        {2, "Theodore", "Wiliams"},
        {3, "James", "Franklin"},
        {4, "Wilson", "Michaels"},
        {5, "Albert", "Yankovick"},
        {6, "Cedric", "Lee"},
        {7, "John", "Ames"},
        {8, "Izake", "Ozuno"},
        {9, "Dennis", "Hazelwood"},
        {10, "Ezra", "Jackson"},
        {11, "Jacob", "Paulson"},
        {12, "Andrew", "Sherman"},
        {13, "Amos", "Patton"},
        {14, "Orson", "Bradley"},
        {15, "Harold", "Green"},
        {16, "Benjamin", "Brown"},
        {17, "Gerald", "Black"},
        {18, "Melvin", "White"}
    };

    struct playerRec tempRec;
    struct playerRec teamTotals;

    int num;
    char fname[30];
    char lname[30];
    int atBat;
    int hits;
    int walks;
    int rbi;
    float batavg;

    FILE * fp;
  
    int i;
    int records = 0;
    
    puts("\n");

    for (i = 0; i < TEAMSIZE; i++) {
        team[i].num = i;
        team[i].atBat = 0;
        team[i].hits = 0;
        team[i].walks = 0;
        team[i].rbi = 0;
        team[i].batavg = 0;
    }
        teamTotals.atBat = 0;
        teamTotals.hits = 0;
        teamTotals.walks = 0;
        teamTotals.rbi = 0;

    if ((fp = fopen("06-baseball_testdata.txt", "r")) == NULL) {
        printf("Unable to open file 'baseball_testdata.txt; terminating");
        exit(EXIT_FAILURE);
    }

// 5 Bob Smith 5 2 1 1

    while ((fscanf(fp, "%d %s %s %d %d %d %d", &num, fname, lname, &atBat, &hits, 
                  &walks, &rbi) == 7) && (num >= 0) && (num < 20)) {

        team[num].atBat += atBat;
        teamTotals.atBat += atBat;

        team[num].hits += hits;
        teamTotals.hits += hits;

        team[num].walks += walks;
        teamTotals.walks += walks;

        team[num].rbi += rbi;
        teamTotals.rbi += rbi;
   
        records++;

//        printf("%d, ", i++);
    }


    printf("%d records processed\n\n", records);

    for (i = 0; i < TEAMSIZE; i++) {
        if (team[i].atBat)
            team[i].batavg = (float)team[i].hits / (float)team[i].atBat;
        else
            team[i].batavg = 0.0;

        printf("Stats for Nr %d, %s %s . . . \n",
                i, team[i].f_name, team[i].l_name);
        printf("At-Bats: %d\n", team[i].atBat);
        printf("Hits: %d\n", team[i].hits);
        printf("Walks: %d\n", team[i].walks);
        printf("RBI: %d\n", team[i].rbi);
        printf("Batting Average: %0.3f\n\n", team[i].batavg);
    }
    
    teamTotals.batavg = (float)teamTotals.hits / (float)teamTotals.atBat;
    printf("Team Totals . . . \n");
    printf("At-Bats: %d\n", teamTotals.atBat);
    printf("Hits: %d\n", teamTotals.hits);
    printf("Walks: %d\n", teamTotals.walks);
    printf("RBI: %d\n", teamTotals.rbi);
    printf("Batting Average: %0.3f\n", teamTotals.batavg);

    fclose(fp);

    puts("\n");

    return 0;
}


