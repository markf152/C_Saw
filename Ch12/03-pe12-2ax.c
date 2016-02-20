/* 03-pe12-2a.c -- computes miles per gallon (US) or */
/* liters per 100km (Europe) */
/* compile with 03-pe12-2b.c */

#include <stdio.h>
#include "03-pe12-2a.h"

static int mode;
static float distance;
static float fuelConsumed;

void set_mode(int * modeChoice)
{
    static int lastMode = 1;
    const char lastModeName[2][10] = {"metric", "US"};

    if (*modeChoice != 0 && *modeChoice != 1)
        printf("Invalid mode specified. Mode %d (%s) used.\n", 
                lastMode, lastModeName[lastMode]);
    else 
        lastMode = *modeChoice;
}

void get_info(int mode, float * distance, float * fuelConsumed)
{
    const char distUnits[2][15] = {"kilometers", "miles"};
    const char fuelUnits[2][10] = {"liters", "gallons"};

    printf("Enter distance traveled in %s: ", distUnits[mode]);
    scanf("%f", distance);
    
    printf("Enter fuels consumed in %s: ", fuelUnits[mode]);
    scanf("%f", fuelConsumed);
}

void show_info(int mode, float fuelConsumed, float distance)
{
    float fuelConsumption;
    const char consumptionPhrase[2][25] = {"liters per 100 km",
                                          "miles per gallon"};
    if (mode == 0)
        fuelConsumption = fuelConsumed / (distance / 100);
    else
        fuelConsumption = distance / fuelConsumed;

    printf("Fuel consumption is %.1f %s.\n\n",
            fuelConsumption, consumptionPhrase[mode]);
}

