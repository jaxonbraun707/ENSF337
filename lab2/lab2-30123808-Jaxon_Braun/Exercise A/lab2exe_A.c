/*
 *  File Name: lab2exe_A.c
 *  Created by Mahmood Moussavi, Sept 2017 for ENCM 339
 *  Assignment: Lab 2 Exercise A
 *  Completed by: Jaxon Braun
 *  Submission Date: September 28, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity);
    return 0;
}
void create_table(double v){
    printf("Angle(deg)\t time(s)\t distance(m) \n");        
    for (double deg; deg <= 90; deg += 5){                  
        double a = degree_to_radian(deg);               
        double t = Projectile_travel_time(a, v);      
        double d = Projectile_travel_distance(a, v);  
        printf("%f\t %f\t %f\t \n", deg, t, d);         
    }
    return ;
}
double Projectile_travel_time(double a, double v){          
    double t = (2 * v * sin(a)) / G;
    return t;
}
double Projectile_travel_distance(double a, double v){
    double d = (pow(v, 2) / G) * sin(2*a);
    return d;
}
double degree_to_radian(double d){
    double a = d * (PI / 180);
    return a;
}
