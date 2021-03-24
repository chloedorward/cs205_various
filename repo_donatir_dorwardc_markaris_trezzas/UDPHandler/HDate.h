#ifndef HDate_H
#define HDate_H

#include <iostream>
#include <vector>

class HDate
{
private:
    std::vector<std::string> months = {"January", "February", "March", "April",
                                       "May", "June", "July", "August",
                                       "September", "October", "November", "December"};
    int day;
    int month;
    int year;
public:
    HDate(int d = 0, int m = 0, int y = 0);
    int get_day();
    int get_month();
    int get_year();
    void set_day(int d);
    void set_month(int m);
    void set_year(int y);
    std::string format();
};

#endif // HDate_H
