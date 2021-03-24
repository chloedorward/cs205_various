#include "swarm.h"

/**
 * @brief Swarm::Swarm
 * Empty constructor for new Swarm
 */
Swarm::Swarm()
{

}

/**
 * @brief Swarm::Swarm
 * Constructor for inputs for HiveID, Day, Month, Year, Hours, Minutes, Seconds
 *
 * @param _HiveID specific hive
 * @param _day day of the week
 * @param _month month of the year
 * @param _year year
 * @param _hours hour of the day
 * @param _minutes minute of the hour
 * @param _seconds seconds of the minute
 */
Swarm::Swarm(std::string _HiveID, int _day, int _month, int _year, int _hours, int _minutes, int _seconds)
{
    HiveID = _HiveID;
    hdate.set_day(_day);
    hdate.set_month(_month);
    hdate.set_year(_year);
    htime.set_hours(_hours);
    htime.set_minutes(_minutes);
    htime.set_millis(_seconds * 1000);
}

/**
 * @brief Swarm::~Swarm
 * Destructor for Swarm
 */
Swarm::~Swarm()
{

}

/**
 * @brief Swarm::showAlertWindow
 * Displays alert window with set values
 *
 * @param UDPMessage
 * Retrieves data using the UDP Message
 */
void Swarm::showAlertWindow(std::string UDPMessage)
{
    importInformationFromUDPMessage(UDPMessage);
    swarm.setHiveID(HiveID);
    swarm.setTime(htime);
    swarm.setDate(hdate);
    swarm.exec();

}

/**
 * @brief Swarm::importInformationFromUDPMessage
 * Imports data from UDP Message
 *
 * @param UDP Message
 */
void Swarm::importInformationFromUDPMessage(std::string UDP)
{
    UDPMessageData message(UDP);
    HiveID = message.get_hiveID();
    hboards = message.get_boards();
    hdate = message.get_date();
    htime = message.get_time();
}

