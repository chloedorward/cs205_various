#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

class HBoard
{
private:
    std::vector<bool> sensors;
public:
    HBoard();
    HBoard(std::vector<bool> s);
    void set_sensors(std::vector<bool> s);
    std::vector<bool> get_sensors();
};

#endif // BOARD_H
