#include <iostream>
#include "HDate.h"
#include "HTime.h"
#include "HBoard.h"
#include "RealTimeSimulator.h"
#include "UDPMessageData.h"
#include "DataAnalyzer.h"
#include <vector>

using namespace std;

int main()
{
    RealTimeSimulator rts("example.txt");
    rts.run(10);
}
