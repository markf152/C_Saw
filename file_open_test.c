
    FILE * flight;

    puts("\n");

    if ((flight = fopen("flight.dat", "r+b")) == NULL) {
        puts("File can't be opened for update, will check existence and try to create\n");
        if (access("flight.dat", F_OK) == -1) {
            puts("File fails 'access()' existence check, attempting to create. \n");
            if ((flight = fopen("flight.dat", "wb")) == NULL) {
                fputs("Can't open or create 'flight.dat' file. Program ending.\n", 
                      stderr);
                exit(1);
            }
            else puts("File created\n");
        }
        else fputs("File exists, but can't be opened for update. Program ending.\n",
                   stderr);
    }
    else puts("File exists and is opened for update\n");

    

    fclose(flight);
