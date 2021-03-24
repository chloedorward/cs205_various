#ifndef BOARD_H
#define BOARD_H

#include "bee.h"
#include <vector>
#include "forager.h"
#include <random>

using namespace std;
class Board
{
public:
    Board();

    void updateline(int x);
    void addToLine(Bee *b);
    void addToEnterLine(Bee *b);
    int calculateBool();
    int toTwoInt(int x);
    void testFunct();
    void Traverse();
    void Inverse();
    void Iterate();
    void swapping();
    void checkSwap();
    bool checkFinT();
    bool checkFinI();

    void InverseIterate();
    void reset();
    int checkBoards();
private:
    vector<Bee*> line;
    vector<Bee*> Enterline;
    int condition = 0;
    bool enterNew = true;
    bool changedstates[8];
    Bee* inner[4];
    Bee* middle[4];
    Bee* outer[4];
    int gateCycle =0;
    int timeSinceUpdate = 0;
    int cycle =0;
    bool FrontBack = false;

};

#endif // BOARD_H
