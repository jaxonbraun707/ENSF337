/* read_int.c
 * ENSF 337 Lab 4 Exercise  E
 * Completed by: Jaxon Braun
 * Submission Date: October 20, 2021
 */

#include "read_input.h"

#include <math.h>

int read_real(char* digits, int n, double * num){
    
    if(get_string(digits, n)== EOF)
        return EOF;

    if(is_valid_double(digits)){
        if(digits[0] == '-')
            *num = -convert_to_double(digits + 1);
        else if(digits[0] == '+') 
            *num = convert_to_double(digits + 1);
        else
            *num = convert_to_double(digits);
        return 1;
    }
    return 0;
}

int is_valid_double(const char* digits){
    int valid = 1;
    int i;

    if(digits[0] == '+' || digits[0] == '-')
        i = 1;
    else
        i = 0;

    if (digits[i] == '\0')
        valid = 0;
    else
        while (valid && (digits[i] != '\0')) {
            if (digits[i] < '.' || digits[i] > '9' || digits[i] == '/')
                valid = 0;
            i++;
        }
    return valid;
}

double convert_to_double(const char *digits){
    double sum = 0;
    int i = 0;
    double decimal_point = 0;
    while(digits[i] != '\0') {
        if (digits[i] != '.' && decimal_point == 0){
            sum = (10 * sum) + (digits[i] - '0');
            i++;
        }
        else if (digits[i] == '.'){
            decimal_point = 1;
            i++;
        }
        else{
            double divisor = 1;
            for (int j = 0; j < decimal_point; j++){
                divisor *= 10.0;
            }
            sum = sum + ((digits[i] - '0') / divisor);
            decimal_point++;
            i++;
        }
    }
    return sum;
}