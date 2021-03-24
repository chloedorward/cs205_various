#ifndef UDPHANDLER_H
#define UDPHANDLER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "HTime.h"
#include "HDate.h"
#include "HBoard.h"
#include "math.h"


class UDPHandler
{
private:
    std::string UDPMessage;
    std::vector<bool> sensors;
    std::string dateString;
    std::string timeString;
    std::string hiveID;
    std::string gateString;
public:
    UDPHandler();
    void read_UDP(std::string message);
    std::string get_hiveID();
    std::vector<HBoard> get_boards();
    std::string encode_boards(std::vector<std::vector<bool>> gs);
    HDate get_date();
    HTime get_time();
    std::string get_message();
    std::string create_message(std::string hID, HDate d, HTime t,  std::vector<std::vector<bool>> gs);
    void set_message();
    void to_string();
    std::vector<bool> decode_gates(std::string s);
    std::string encode_gates(std::vector<bool> g);
};

#endif // UDPHANDLER_H
