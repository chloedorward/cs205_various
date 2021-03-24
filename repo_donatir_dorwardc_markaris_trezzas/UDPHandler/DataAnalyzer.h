#ifndef DATAANALYZER_H
#define DATAANALYZER_H

#include <iostream>
#include <vector>
#include <fstream>

#include "UDPMessageData.h"

class DataAnalyzer
{
private:
    int gateSize;
    std::vector<std::vector<int>> pathStatuses;
    std::vector<std::vector<HTime>> pathLastActivity;
    int numOfBoards;
    int numOfGates;
    int gateToPath(int n);
public:
    DataAnalyzer(std::string f);
    DataAnalyzer(UDPMessageData * m);
    void printData();
    std::vector<UDPMessageData*> messages;
    std::vector<int> analyze();
    std::vector<int> analyzeComprehensive();
    std::vector<int> updateState(UDPMessageData *m);
    void reset();
    void printState();
    void printMessage(UDPMessageData *m);
};

#endif // DATAANALYZER_H
