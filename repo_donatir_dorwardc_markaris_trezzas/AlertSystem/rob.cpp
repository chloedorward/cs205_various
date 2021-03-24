#include "rob.h"

/**
 * @brief Rob::Rob
 * Empty constructor for new Rob
 */
Rob::Rob()
{

}

/**
 * @brief Rob::Rob
 * Constructor for inputs for HiveID, Day, Month, Year, Hours, Minutes, Seconds
 *
 * @param _HiveID specific hive
 * @param _day day fo the week
 * @param _month month of the year
 * @param _year year
 * @param _hours hour of the day
 * @param _minutes minute of the hour
 * @param _seconds second of the minute
 */
Rob::Rob(std::string _HiveID, int _day, int _month, int _year, int _hours, int _minutes, int _seconds)
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
 * @brief Rob::~Rob
 * Destructor for Rob
 */
Rob::~Rob()
{

}

/**
 * @brief Rob::showAlertWindow
 * Displays alert window with set values
 *
 * @param UDPMessage
 * Retrieves data using the UDP Message
 */
void Rob::showAlertWindow(std::string UDPMessage)
{
    importInformationFromUDPMessage(UDPMessage);
    rob.setHiveID(HiveID);
    rob.setTime(htime);
    rob.setDate(hdate);
    rob.exec();
}

/**
 * @brief Rob::importInformationFromUDPMessage
 * Imports data from UDP Message
 *
 * @param UDP Message
 */
void Rob::importInformationFromUDPMessage(std::string UDP)
{
    UDPMessageData message(UDP);
    HiveID = message.get_hiveID();
    hboards = message.get_boards();
    hdate = message.get_date();
    htime = message.get_time();
}
