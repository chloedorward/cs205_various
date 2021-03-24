#include "UDPMessageData.h"

UDPMessageData::UDPMessageData(std::string m){
    message = m;
    UDPHandler handler;
    handler.read_UDP(m);
    boards = handler.get_boards();
    date = handler.get_date();
    time = handler.get_time();
    hiveID = handler.get_hiveID();
}

UDPMessageData::UDPMessageData(std::string hID, HDate d, HTime t, std::vector<HBoard> bs){
    hiveID = hID;
    date = d;
    time = t;
    UDPHandler handler;
    std::vector<std::vector<bool>> gates;
    for(int i = 0; i < bs.size(); i++){
        gates.push_back(bs[i].get_sensors());
    }
    message = handler.create_message(hID, d, t, gates);
}

UDPMessageData::UDPMessageData(std::string hID, HDate d, HTime t, std::vector<std::vector<bool>> gs){
    hiveID = hID;
    date = d;
    time = t;
    UDPHandler handler;
    message = handler.create_message(hID, d, t, gs);
}

std::vector<HBoard> UDPMessageData::get_boards(){
    return boards;
}

HDate UDPMessageData::get_date(){
    return date;
}

HTime UDPMessageData::get_time(){
    return time;
}

std::string UDPMessageData::get_hiveID(){
    return hiveID;
}

std::string  UDPMessageData::get_message(){
    return message;
}

void UDPMessageData::to_string(){
    std::cout << "Message: " << message << std::endl << std::endl <<
                 "Hive ID: " << hiveID << std::endl << std::endl <<
                 "Date: " << date.format() << std::endl <<
                 "    Day:   " << date.get_day() << std::endl <<
                 "    Month: " << date.get_month() << std::endl <<
                 "    Year:  " << date.get_year() << std::endl << std::endl <<
                 "Time: " << time.format() << std::endl <<
                 "    Hours:   " << time.get_hours() << std::endl <<
                 "    Minutes: " << time.get_minutes() << std::endl <<
                 "    Millis:  " << time.get_millis() << std::endl << std::endl <<
                 "Boards/Gates: " << std::endl;
    for(int i = 0; i < 10; /*number of boards*/ i++){
        std::cout << "    Board " << i + 1 << std::endl;
        for(int z = 0; z < boards[i].get_sensors().size(); z++){
            std::cout << "        Gate " << z + 1 << ": " << boards[i].get_sensors()[z] << std::endl;
        }
    }
}
