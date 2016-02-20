// 08-airline.c -- Seating reservation program for Colossus Airlines 
//
// prog exercise . . . loc 18159
// menu techniques . . .loc 9251
// Colossus has 1 plane with 12 seats
//
// Program uses an array of 12 structures:
//  - seat ID number
//  - marker - seat assigned or not
//  - last name of seat holder
//  - first name of seat holder
// 
// Program has the following menu:
// To choose a function, enter its letter label:
// a) Show number of empty seats
// b) Show list of empty seats
// c) Show alphabetical list of seats [by last name of passenger?]
// d) Assign a customer to a seat assignment
// e) Delete a seat assignment
// f) Quit

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  // need for access() function to check existance of file

#define MAXNAMELEN 40
#define NUMSEATS 12
#define QUIT 'f'    // current 'quit'choice is 'f', but that could change

struct seat {
    int seatID;                // 1 through NUMSEATS (0 is not used)
    int seatAssigned;          // 0 = not assigned; non-zero = assigned
    char paxLname[MAXNAMELEN];
    char paxFname[MAXNAMELEN];
};

char * s_gets(char * st, int n);
void displaymenu(void);
void getfile(FILE ** flt);
void loadFlightData(FILE ** flt, struct seat * plane, int seats);
void createEmptySeat(FILE ** flt, struct seat emptySeat, int seatNum);
char getMenuChoice(void);
void showNrEmptySeats(const struct seat *);
void listEmptySeats(const struct seat * flt);
void showAlphaListPax(const struct seat *);
void assignPaxSeat(struct seat *);
void deleteSeatAssign(struct seat *);
void endProgram();       // 'f' == QUIT


int main (void)
{
    struct seat plane1[NUMSEATS];
    FILE * flight;
    int seatSize = sizeof(struct seat);
    int menuChoice;

    puts("\n");

//    printf("flight = %p\n", flight);
//    puts("getfile()");
    getfile(&flight);
//    puts("ok getfile, back in main()");
//    printf("flight = %p\n", flight);
    loadFlightData(&flight, plane1, NUMSEATS);
//    printf("plane = %p    %p\n", plane, &plane);
    showNrEmptySeats(plane1);
 
/*    while ( ( menuChoice = getMenuChoice()) != QUIT) {
        switch (menuChoice) {
            case 'a' : showNrEmptySeats(plane);
                      menuChoice = 'f';
                      break;
            case 'b' : listEmptySeats(plane);
                       break;
            case 'c' : showAlphaListPax(plane);
                       break;
            case 'd' : assignPaxSeat(plane);
                       break;
            case 'e' : deleteSeatAssign(plane);
                       break;
            case 'f' : endProgram();       // 'f' == QUIT
                       break;
            default  : fputs("Program Error. Terminating.\n", stderr);
                       exit(1);
        }
    } */

    fclose(flight);

    puts("\n");
}

void getfile(FILE ** flt)
{
    int i;
    struct seat emptySeat = {0, 0, ".", "."};

    if ((*flt = fopen("flight.dat", "r+b")) == NULL) {
        puts("File can't be opened for update, will check existence and try to create\n");
        if (access("flight.dat", F_OK) == -1) {
            puts("File fails 'access()' existence check, attempting to create. \n");
            if ((*flt = fopen("flight.dat", "w+b")) == NULL) {
                fputs("Can't open or create 'flight.dat' file. Program ending.\n", 
                      stderr);
                exit(1);
            }
            else {
                puts("File created\n");
//                printf("flt = %p\n", *flt);
                for (i = 0; i < NUMSEATS; i++) {  // create each empty seat
                    createEmptySeat(flt, emptySeat, i);
//                    printf("flt = %p\n", *flt);
//                    printf("Created seat %d\n", i);
                }
            }
        }
        else {
            fputs("File exists, but can't be opened for update. Program ending.\n",
                   stderr);
            exit(1);
        }
    }
    puts("Flight file is opened for update.\n");
//    printf("flt = %p\n", *flt);
//    puts("ok rewind . . .");
}

void loadFlightData(FILE ** flt, struct seat * plane, int seats)
{
    int i;
    int x;   // temp for testing
    int seatSize = sizeof(struct seat);
//    printf("plane = %p\n", plane);

    rewind(*flt);
//    printf("flt = %p\n", *flt);

    for (i = 0; i < seats; i++) {
//        printf("i = %2d  ", i);
//        x = fread(plane++, seatSize, 1, *flt);
//        printf("x = %2d\n", x);
        if (fread(plane++, seatSize, 1, *flt) != 1) {
            puts("Error . . . couldn't read in all seats for flight.");
            puts("Contact tech support.  Program ending.");
            puts("Function = loadFlightData");
            exit(1);            
        }


/* This entire section for testing . . . 
        plane--;
        printf("file location: %ld\n", ftell(*flt));
        printf("seatID: %d\n", plane->seatID);
        printf("seatAssigned: %d\n", plane->seatAssigned);
        printf("paxLname: %s\n", plane->paxLname);
        printf("paxFname: %s\n", plane->paxFname);
        plane++;
*/

    }
//    puts("read in all seats");
}

void createEmptySeat(FILE ** flt, struct seat emptySeat, int seatNum)
{
    int seatSize = sizeof(struct seat);
    int x;   // temp for testing
    
    fseek(*flt, (seatNum * seatSize), SEEK_SET);
//    printf("createEmptySeat . . . flt = %p\n", *flt);
    emptySeat.seatID = seatNum;

    x = fwrite(&emptySeat, seatSize, 1, *flt);
//    printf("file pointer at: %ld\n", ftell(*flt));
//    printf("fwrite check x = %d\n", x);

/* This entire section for testing . . .
    rewind(*flt);
    fseek(*flt, (seatNum * seatSize), SEEK_SET);
    x = fread(&emptySeat, seatSize, 1, *flt);
    printf("fread check x = %d\n", x);
    printf("seatID: %d\n", emptySeat.seatID);
    printf("seatAssigned: %d\n", emptySeat.seatAssigned);
    printf("paxLname: %s\n", emptySeat.paxLname);
    printf("paxFname: %s\n", emptySeat.paxFname);
*/

}

void displaymenu(void)
{
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
}

char getMenuChoice(void)
{
    return 'a';
}

void showNrEmptySeats(const struct seat * plane)
{
    int i;
    int filled = 0;

    for (i = 0; i < NUMSEATS; i++) {
//        printf("plane[%d].seatID = %d\n", i, plane->seatID);
//        printf("plane[%d].seatAssigned = %d\n", i, plane->seatAssigned);
        if (plane++->seatAssigned)
            filled++;
    }
    printf("%d seats are currently filled.\n\n", filled);
}

void listEmptySeats(const struct seat * flt)
{

}

void showAlphaListPax(const struct seat * flt)
{

}

void assignPaxSeat(struct seat * flt)
{

}

void deleteSeatAssign(struct seat * flt)
{

}

void endProgram()       // 'f' == QUIT
{

}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
