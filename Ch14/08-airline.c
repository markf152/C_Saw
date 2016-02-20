// 08-airline.c -- Seating reservation program for Colossus Airlines 
//
// prog exercise . . . loc 18159
// menu techniques . . .loc 9154
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
// e) Confirm a customer's seat assigment
// f) Delete a seat assignment
// g) Quit

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  // need for access() function to check existance of file

#define MAX_NAME_LEN 40
#define MAX_CITY_NAME_LEN 40
#define NUMSEATS 12
#define QUIT 'g'    // current 'quit'choice is 'g', but that could change

struct flightInfo {
    int flightNum;
    int numSeats;
    char fromCity[MAX_CITY_NAME_LEN];
    char toCity[MAX_CITY_NAME_LEN];
};

struct seat {
    int seatID;                // 1 through NUMSEATS (0 is not used)
    int seatAssigned;          // 0 = not assigned; non-zero = assigned
    int seatConfirmed;
    char paxLname[MAX_NAME_LEN];
    char paxFname[MAX_NAME_LEN];
};

//Utility Functions . . .
char * s_gets(char * st, int n);
int getfile(char * fileName, FILE ** filePtr);
void createEmptySeats(FILE ** flt, int numSeats);
void endProgram();       // 'q' == QUIT

//Menu Functions . . .
char mainMenu(void);
char pickFLightMenu(void);
char flightMenu(void);

//Show, Add, Delete Flights . . .
int getExistingFlights(FILE ** flightListFile, 
                         struct flightInfo * flightList);

//Functions for individual flight work . . .
void loadFlightData(FILE ** flt, struct seat * plane, int seats);
void showNrEmptySeats(const struct seat *);
void listEmptySeats(const struct seat * flt);
void showAlphaListPax(const struct seat *, int seats);
void assignPaxSeat(struct seat *);
void deleteSeatAssign(struct seat *);


int main (void)
{
    struct flightInfo flight;
    struct seat plane1[NUMSEATS];
    FILE * flightFile;
    int seatSize = sizeof(struct seat);
    int menuChoice;

    puts("\n");

//    printf("flight = %p\n", flight);
//    puts("getfile()");

    // getfile() returns 1 (non-zero) if new file created - requires empty seats
    // to be created and filled
    if (getfile("flight.dat", &flightFile))
        createEmptySeats(&flightFile, NUMSEATS);

//    puts("ok getfile, back in main()");
//    printf("flight = %p\n", flight);

// GET FLIGHT FROM USER - pickFlight

// LOAD FLIGHT SPECIFIED BY USER

// FLIGHT MENU - flightMenu

// EXECUTE FUNCTION

// EXECUTE NEXT FUNCTION OR RETURN TO PICK ANOTHER FLIGHT (OR QUIT)

 

    loadFlightData(&flightFile, plane1, NUMSEATS);
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
            case 'q' : endProgram();       // 'f' == QUIT
                       break;
            default  : fputs("Program Error. Terminating.\n", stderr);
                       exit(1);
        }
    } */

    fclose(flightFile);

    puts("\n");
}

//****************************************************************************
int getfile(char * fileName, FILE ** filePtr)
{
    int i;

    if ((*filePtr = fopen(fileName, "r+b")) == NULL) {
        puts("File can't be opened for update, will check existence and try to create\n");
        if (access(fileName, F_OK) == -1) {
            puts("File fails 'access()' existence check, attempting to create. \n");
            if ((*filePtr = fopen(fileName, "w+b")) == NULL) {
                fprintf(stderr, "Can't open or create '%s' file. Program ending.\n", 
                      fileName);
                exit(EXIT_FAILURE);
            }
            else {
                puts("File created\n");
                return 1;  // 1 = new file created and opened
            }
        }
        else {
            fputs("File exists, but can't be opened for update. Program ending.\n",
                   stderr);
            exit(EXIT_FAILURE);
        }
    }
    else
        puts("Flight file is opened for update.\n");
        return 0;  // 0 = file exists and was opened successfully

//    printf("flt = %p\n", *flt);
//    puts("ok rewind . . .");
}


//****************************************************************************
void createEmptySeats(FILE ** flt, int numSeats)
{
    int seatSize = sizeof(struct seat);
    struct seat emptySeat = {0, 0, 0, ".", "."};
    int i;  // loop variable
    
    rewind(*flt);

    for (i = 0; i < numSeats; i++) {  // create each empty seat
        emptySeat.seatID = i;

        if (i % 2)                      // temp for testing
            emptySeat.seatAssigned = 1; // temp for testing
        else                            // temp for testing
            emptySeat.seatAssigned = 0; // temp for testing

        fwrite(&emptySeat, seatSize, 1, *flt);
    }
}


//****************************************************************************
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


//****************************************************************************
char mainMenu(void)
{
    puts("Select a function (enter its letter)...");
    puts("a) Pick a flight");
    puts("b) Create a flight");
    puts("c) Delete a flight");
    puts("q) Quit");
}


//****************************************************************************
char pickFlightMenu(void)
{
    FILE * flightListFile;
    struct flightInfo * flightListing;
    int numFlights = 0;  // stores number of flights read in from file
    int i = 0; // index variable for loops 
    char menuLtr =  'a';

    puts("Select a flight (enter its letter)...");

    getfile("flightList.dat", &flightListFile);
    numFlights = getExistingFlights(&flightListFile, flightListing);
    puts("   Flight Nr    From                      To");
    puts("--------------------------------------------------------------");
    for (i = 0; i < numFlights; i++) {
        printf("%c) %d           %s                        %s",
             (menuLtr + i),
             flightListing[i].flightNum, 
             flightListing[i].fromCity, 
             flightListing[i].toCity);
    } 
    
}


//****************************************************************************
char flightMenu(void)
{
    puts("Choose a function (enter its letter)...");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Confirm a customer's seat assignment");
    puts("f) Delete a seat assignment");
    puts("q) Quit");
}


//****************************************************************************
int getExistingFlights(FILE ** flightListFile, 
                         struct flightInfo * flightList)
// returns number of existing flights (i)
{
    int i = 0; // increments to count number of flights listed in 
               // file pointed to by flightList

    rewind(*flightListFile);
    while (fread(&flightList[i], (sizeof(struct flightInfo)), 
           1, *flightListFile) == 1) {
        i++;
    }
    

    return i;
}


//****************************************************************************
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


//****************************************************************************
void listEmptySeats(const struct seat * plane)
{
    int i;
    int filled = 0;

    printf("The following seats are empty:\n");

    for (i = 0; i < NUMSEATS; i++) 
        if (plane++->seatAssigned) 
            printf("%d, ", plane->seatID);
    
    printf("\n\n");
}


//****************************************************************************
void showAlphaListPax(const struct seat * plane, int numSeats)
{
    int i;
    int j;
    int temp; // temp storage during sort
    int *  sortedSeats;
    sortedSeats = (int *)malloc(numSeats * sizeof(int)); 
    
    for (i = 0; i < numSeats; i++) 
        sortedSeats[i] = i;

    for (i = 1; i < numSeats; i++) {
        for (j = i; j > 0; j--)
            if (strcmp(plane[j].paxLname, plane[j-1].paxLname) > 0) {
                temp = sortedSeats[j-1];
                sortedSeats[j-1] = sortedSeats[j];
                sortedSeats[j] = temp;
            }
    }
}


//****************************************************************************
void assignPaxSeat(struct seat * flt)
{

}


//****************************************************************************
void deleteSeatAssign(struct seat * flt)
{

}


//****************************************************************************
void endProgram()       // 'f' == QUIT
{

}


//****************************************************************************
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
