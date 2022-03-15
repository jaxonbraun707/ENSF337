//  ENSF 337- Fall 2020 lab 7, Exercise C
//  lab7Clock.h
//  By: Jaxon Braun

#ifndef lab7Clock_h
#define lab7Clock_h

class Clock {
public:
    
    Clock(): hour(0), minute(0), second(0) {} 

    Clock(int second_in);               

    Clock(int hour, int minute, int second);

    int get_hour() const;

    int get_minute() const;

    int get_second() const;

    void set_hour(int hour);

    void set_minute(int minute);

    void set_second(int second);

    void increment();

    void decrement();

    void add_seconds(int seconds);


private:

    int hour;
    int minute;
    int second;

    int hms_to_sec(Clock& n);

    Clock sec_to_hms(int n);

};



#endif /* lab7Clock.h */