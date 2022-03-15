//  ENSF 337- Fall 2020 lab 7, Exercise C
//  lab7Clock.cpp
//  By: Jaxon Braun

#include "lab7Clock.h"

Clock::Clock(int second_in){
    if (second_in < 0){
        hour = 0;
        minute = 0;
        second = 0;
    }
    else{
        Clock temp_Clock = sec_to_hms(second_in);
        hour = temp_Clock.hour;
        minute = temp_Clock.minute;
        second = temp_Clock.second;
    }
}

Clock::Clock(int hour_in, int minute_in, int second_in){
    if ( (hour_in < 0 || hour_in > 23) || (minute_in < 0 || minute_in > 59) || (second_in < 0 || second_in > 59)){
        hour = 0;
        minute = 0;
        second = 0;
    }
    else{
        hour = hour_in;
        minute = minute_in;
        second = second_in;
    }
}

int Clock::get_hour() const {
    return hour;
}

int Clock::get_minute() const {
    return minute;
}

int Clock::get_second() const {
    return second;
}

void Clock::set_hour(int hour_in){
    if (hour_in < 0 || hour_in > 23)
        return;
    hour = hour_in;
}

void Clock::set_minute(int minute_in){
    if (minute_in < 0 || minute_in > 59)
        return;
    minute = minute_in;
}

void Clock::set_second(int second_in){
    if (second_in < 0 || second_in > 59)
        return;
    second = second_in;
}

void Clock::increment(){
    Clock temp_Clock = Clock(hour, minute, second);
    int total_seconds = hms_to_sec(temp_Clock) + 1;
    temp_Clock = sec_to_hms(total_seconds);
    hour = temp_Clock.hour;
    minute = temp_Clock.minute;
    second = temp_Clock.second;
    return;
}

void Clock::decrement(){
    Clock temp_Clock = Clock(hour, minute, second);
    int total_seconds = hms_to_sec(temp_Clock) - 1;
    temp_Clock = sec_to_hms(total_seconds);
    hour = temp_Clock.hour;
    minute = temp_Clock.minute;
    second = temp_Clock.second;
    return;
}

void Clock::add_seconds(int seconds){
    if (seconds < 0)
        return;
    Clock temp_Clock = Clock(hour, minute, second);
    int total_seconds = hms_to_sec(temp_Clock) + seconds;
    temp_Clock = sec_to_hms(total_seconds);
    hour = temp_Clock.hour;
    minute = temp_Clock.minute;
    second = temp_Clock.second;
    return;

}

int Clock::hms_to_sec(Clock& n){
    int seconds = (n.hour * 3600) + (n.minute * 60) + n.second;
    return seconds;
}

Clock Clock::sec_to_hms(int n){
    int hour_in = n / 3600;
    int minute_in = (n % 3600) / 60;
    int second_in = n % 60;

    if (second_in < 0){
        minute_in -= 1;
        second_in += 60;
    }
    if (minute_in < 0){
        hour_in -= 1;
        minute_in += 60;
    }
    if (hour_in < 0)
        hour_in += 24;

    if (second_in > 59){
        minute_in += 1;
        second_in -= 60;
    }
    if (minute_in > 59){
        hour_in += 1;
        minute_in -= 60; 
    }
    if (hour_in > 23)
        hour_in -= 24;

    return Clock(hour_in, minute_in, second_in);
}