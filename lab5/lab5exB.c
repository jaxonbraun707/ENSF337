//  ENSF 337 - lab 5 -exercise B
//  lab5exB.c

#include <stdio.h>
#include "lab5exB.h"

const Date cd = {1, 1, 1970};

int main() {
    Timestamp *tsp;
    Time t = {0, 0, 24};
    Timestamp ts = {cd, &t};
    tsp = & ts;
    change_date_time(&tsp->date, &t);

    printf("Date: %d %d %d\n", ts.date.day, ts.date.month, ts.date.year);
    printf("Time: %d %d %d\n", ts.time->hour, ts.time->minute, ts.time->second);
    printf("t: %d %d %d\n", t.hour, t.minute, t.second);
    printf("Program Terminted.\n");
    return 0;
}

void change_date_time(Date *arg1, Time *arg2){
    
    arg1 -> day = 29;
    arg1 -> month = 10;
    arg1 -> year = 2016;
    (*arg2).second = 5;
    (*arg2).minute = 59;
    (*arg2).hour = 23;
    
    // Point one
}
