// 05-grades.c -- uses an array of structures to hold grade information about a group of 
// students; uses grade information to calculate student and class averages


// text location 18112

#include<stdio.h>

#define CSIZE 4

struct name {
    char first[30];
    char last[30];
};

struct student {
    struct name studentname;
    float grade[3];
    float average;
};


void getgrades(struct student students[], int n);
void calcStudAvg(struct student students[], int n);
void printStudGradeInfo(struct student students[], int n);
void printClassAvg(struct student students[], int n);

int main(void)
{

    struct student students[CSIZE] = {
        { {"Michael", "Jones"} },
        { {"Nancy", "Smith"} },
        { {"Pedro", "Munoz"} },
        { {"Hans", "von Bulow"} }
    };

    getgrades(students, CSIZE);       
    calcStudAvg(students, CSIZE);
    printStudGradeInfo(students, CSIZE);
    printClassAvg(students, CSIZE);
}

// function - acquire scores
void getgrades(struct student students[], int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++)  {
        printf("For student %s %s . . . \n", 
                students[i].studentname.first, students[i].studentname.last);
        for (j = 0; j < 3; j++) {
            printf("Enter grade for class %d: ", j);
            scanf("%f", &students[i].grade[j]);
        }
        printf("\n");
    }
}

// function - calculate average score for each array member and store it
void calcStudAvg(struct student students[], int n)
{
    int i;
    int j;
    float gradesum;

    for (i = 0; i < n; i++) {
        gradesum = 0;
        for (j = 0; j < 3; j++) 
            gradesum += students[i].grade[j];
        students[i].average = (gradesum / 3);
    }
}

// function - print the information in each structure in the array
void printStudGradeInfo(struct student students[], int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++) {
        printf("Student %s %s . . .\n", 
                students[i].studentname.first, students[i].studentname.last);
        for (j = 0; j < 3; j++)
            printf("Class %d - Grade %.1f\n", j, students[i].grade[j]);
        printf("Student's average: %.1f\n", students[i].average);
        printf("\n");
    }
}


// function - print the class average for each of the numeric structure members
void printClassAvg(struct student students[], int n)
{
    int i;
    int j;
    float gradesum;

    for (j = 0; j < 3; j++) {
        gradesum = 0;
        for (i = 0; i < n; i++) 
            gradesum += students[i].grade[j];
        printf("Class %d average: %.1f\n", j, (gradesum / n));
    }
    printf("\n");
}

