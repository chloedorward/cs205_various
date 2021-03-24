#ifndef UDPMESSAGEDATA_H
#define UDPMESSAGEDATA_H

#include <iostream>
#include <vector>
#include "UDPHandler.h"
#include "HBoard.h"
#include "HDate.h"
#include "HTime.h"

class UDPMessageData
{
private:
    std::vector<HBoard> boards;
    HDate date;
    HTime time;
    std::string hiveID;
    std::string message = "";
public:
    UDPMessageData(std::string m);
    UDPMessageData(std::string hID, HDate d, HTime t,  std::vector<HBoard> bs);
    UDPMessageData(std::string hID, HDate d, HTime t,  std::vector<std::vector<bool>> gs);
    std::vector<HBoard> get_boards();
    HDate get_date();
    HTime get_time();
    std::string get_hiveID();
    std::string get_message();
    void to_string();
};

#endif // UDPMESSAGEDATA_H
