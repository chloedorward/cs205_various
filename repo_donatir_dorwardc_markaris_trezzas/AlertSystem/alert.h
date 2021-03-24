#ifndef ALERT_H
#define ALERT_H

#include <string>
#include <QDialog>
#include <vector>
#include "../UDPHandler/UDPMessageData.h"
#include "../UDPHandler/UDPHandler.h"
#include "../UDPHandler/HBoard.h"
#include "../UDPHandler/HDate.h"
#include "../UDPHandler/HTime.h"
#include "../AlertUI/robalertui.h"
#include "../UDPHandler/DataAnalyzer.h"
#include "swarm.h"
#include "rob.h"

class Alert
{
    std::vector<std::string> UDPMessages;
    std::string currentUDPMessage;
    std::vector<std::vector<HBoard>> boards;

    std::vector<HBoard> hboards;
    int numBeesIn;
    int numBeesOut;
    int time;

    int numMessages;


public:
    Alert();
    ~Alert();
    void addUDPMessage(std::string UDP);
    void detectSwarm();
    void detectRob();

    DataAnalyzer * da;

};

#endif // ALERT_H
