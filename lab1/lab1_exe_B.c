/*
    File Name: lab1_exe_B.c
    Assignment: Lab 1 Exercise B
    Lab Section: B01
    Completed By: Jaxon Braun
    Submission Date: Sept 20, 2021
*/

#include <stdio.h>
int main()
{
    double num1 = -34.5;
    double num2 = 98.7;

    double sum;             // sum of num1 and num2
    double sumSquared;      // the square of num1 plus num2

    sum = num1 + num2;

    sumSquared = sum * sum;

    printf("The sum squared is %f \n", sumSquared);

    sumSquared *= 2;

    printf("The sum squared now is: %f \n", sumSquared);

    return 0;
}