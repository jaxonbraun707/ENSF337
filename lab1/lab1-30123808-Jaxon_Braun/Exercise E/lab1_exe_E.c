/*
    File Name: lab1_exe_E.c
    Assignment: Lab 1 Exercise E
    Lab Section: B01
    Completed By: Jaxon Braun
    Submission Date: Sept 21, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c;
    
    //asking for the inputs of coefficients a b and c

    printf("This program calculates the solutions of a quadratic equation given the coefficients in the general quadratic equation ax^2 + bx + c. \n");
    printf("Please enter a value for coefficient a: \n");
    scanf("%f", &a);
    printf("Please enter a value for coefficient b: \n");
    scanf("%f", &b);
    printf("Please enter a value for coefficient c: \n");
    scanf("%f", &c);

    //computing the discriminant of the equation to determine if the equation will have complex solutions or not

    float discriminant = (pow(b, 2)) - (4 * a * c);

    //separating the quadratic into two ratios in order to simplify calculation. Using the absolute value of the discriminant for now, but will consider its true value later in order to determine if we need to represent complex solutions or not

    float ratio_1 = (b * -1) / (2 * a);
    float ratio_2 = (sqrt(abs(discriminant))) / (2 * a);
    
    //if the discriminant is 0 or greater, we calculate the solutions using the quadratic equation normally. If the discriminant is less than zero, we must represent the complex solutions, which we can do by simply adding an i to ratio_2 and not add together ratio_1 and ratio_2. We also need to print the results here, as the formatting is different depending on if we need complex solutions or not.

    if (discriminant >= 0){
        float x_1 = ratio_1 + ratio_2;
        float x_2 = ratio_1 - ratio_2;
        printf("The solutions to the quadratic are: \n x_1 = %f and x_2 = %f \n", x_1, x_2);
    }
    else {
        ratio_2 = abs(ratio_2);
        printf("The solutions to the quadratic are: \n x_1 = %f + %fi and x_2 = %f - %fi \n", ratio_1, ratio_2, ratio_1, ratio_2);
    }

    return 0;
}
        