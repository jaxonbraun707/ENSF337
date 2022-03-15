/*
    File Name: lab1_exe_D.c
    Assignment: Lab 1 Exercise D
    Lab Section: B01
    Completed By: Jaxon Braun
    Submission Date: Sept 20, 2021
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float angle;
    printf("Please enter a value for an angle in radians: \n");
    scanf("%f", &angle);

    // using the built in math.h function to calculate sin(x) where x = angle
    float result_sin_function = sin(angle);
    printf("Using the built-in function, sin(%f) = %f \n", angle, result_sin_function);

    // using the taylor series approximation to calcualte sin(x) where x = angle
    float three_fact = 3 * 2 * 1, five_fact = 5 * 4 * 3 * 2 * 1, seven_fact = 7 * 6 * 5 * 4 * 3 * 2 * 1;
    float result_taylor_approx = angle - (pow(angle, 3) / three_fact) + (pow(angle, 5) / five_fact) -(pow(angle, 7) / seven_fact);
    printf("Using the taylor series approximation, sin(%f) = %f \n", angle, result_taylor_approx);

    return 0;
}

