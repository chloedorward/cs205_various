#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <vector>

class HTime
{
private:
    int hours;
    int minutes;
    int millis;
public:
    HTime(int h = 0, int m = 0, int ms = 0);
    int get_hours();
    int get_minutes();
    int get_millis();
    void set_hours(int h);
    void set_minutes(int m);
    void set_millis(int ms);
    long compare_to(HTime t);
    long inMillis();
    std::string format();
};

#endif // TIME_H
