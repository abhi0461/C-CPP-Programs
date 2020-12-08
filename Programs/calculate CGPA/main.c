/*
Assignment Problem 2
Write a program that will first ask the user the number of subjects (maximum value is 50) in a
semester. It will then take as input the number of credits (possible values are 1, 3 and 4) for
each subject and also the marks (integer between 0 and 100 both inclusive) for each subject
for a student. The program will compute the CGPA and will print as output a grade sheet for
the student. The following table will be used for calculating CGPA.

Marks (M) Equivalent Grade Points Grade
90<=M<=100 10.0 EX
80<=M<90 9.0 A
70<=M<80 8.0 B
60<=M<70 7.0 C
50<=M<60 6.0 D
40<=M<50 5.0 P
0<=M<40 0.0 F
The formula for calculating CGPA is Σ (Ci × Gi) / ΣCi, where Ci and Gi respectively represent
the number of credits and the equivalent grade points corresponding to the grade obtained in
the ith subject. While printing, CGPA is printed upto two decimal places.
You need to define and use four functions other than main for performing the following
tasks:
● Function 1: Read the number of subjects from the user, the marks for each subject and
credits for each subject. It does not do any other processing or printing. It also does
not call any other function. It can return appropriate value.
● Function 2: Accept a single value for marks as input and return the corresponding
grade using the table shown above (Note, you may have to return the grade EX as one
character like X but then show it correctly as EX during printing as mentioned below)
● Function 3: Accept a single value for marks as input and return the equivalent grade
point using the table shown above.
● Function 4: Print the grade sheet in the format shown below. It also computes the
CGPA. It calls other functions as appropriate. Only this function can have print
statements. It does not return anything.
The main function has the appropriate variable declarations. It can call the above functions as
appropriate and store the return values in appropriate variables. It does not do any calculation.
It does not do any printing. Global variables are not allowed.
*/

#include<stdio.h>

char ShowGrade(int marks)
{
    if(marks >= 0 && marks < 40)
    {
        return 'F';
    }
    else if(marks >= 40 && marks < 50)
    {
        return 'P';
    }
    else if(marks >= 50 && marks < 60)
    {
        return 'D';
    }
    else if(marks >= 60 && marks < 70)
    {
        return 'C';
    }
    else if(marks >= 70 && marks < 80)
    {
        return 'B';
    }
    else if(marks >= 80 && marks < 90)
    {
        return 'A';
    }
    else if(marks >= 90 && marks < 100)
    {
        return 'O';
    }
}

float ShowGradePoints(int marks)
{
    if(marks >= 0 && marks < 40)
    {
        return 0.0;
    }
    else if(marks >= 40 && marks < 50)
    {
        return 5.0;
    }
    else if(marks >= 50 && marks < 60)
    {
        return 6.0;
    }
    else if(marks >= 60 && marks < 70)
    {
        return 7.0;
    }
    else if(marks >= 70 && marks < 80)
    {
        return 8.0;
    }
    else if(marks >= 80 && marks < 90)
    {
        return 9.0;
    }
    else if(marks >= 90 && marks < 100)
    {
        return 10.0;
    }
}

void AcceptAll(int credit[], int mark[], int sub)
{
    printf("Enter the credits and marks obtained per subject :\n\n");
    for(int i = 0; i < sub; i++)
    {
        printf("Enter number of credits for subject %d : ",i+1);
        scanf("%d",&credit[i]);
        ifmarks:
        printf("Enter marks in subject %d : ",i+1);
        scanf("%d",&mark[i]);
        if (mark[i] > 100 || mark[i] < 0)
        {
            printf("Invalid Input\n");
            goto ifmarks;
        }    
    }
}

void ShowCGPA()
{
    int sub = 0;
    printf("Enter the number of subjects\n");
    scanf("%d",&sub);
    int credit[sub];
    int mark[sub];

    AcceptAll(credit, mark, sub);

    float num = 0.0;
    int total_credit = 0;
    float result = 0.0;
    printf("Result :\n\nSub.no.\tMarks\tCredits\t Grades\n");
    printf("-------------------------------\n");
    for (int i = 0; i < sub; i++)
    {
        printf(" %d\t%d\t %d\t %c\n",i+1,mark[i],credit[i],ShowGrade(mark[i]));
        
        num = num+(credit[i]*ShowGradePoints(mark[i]));
        total_credit = total_credit+credit[i];
    }
    result = num/total_credit;
    printf("\nCGPA : %0.2f\n",result);
}


int main()
{
    ShowCGPA();
    
    return 0;
}