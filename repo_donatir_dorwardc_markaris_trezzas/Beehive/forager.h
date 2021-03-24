#ifndef FORAGER_H
#define FORAGER_H
#include "bee.h"
#include <string>
using namespace std;
class Forager: public Bee
{
public:
    Forager();
    ~Forager();

   virtual bool CheckDeath();
    bool getinit();
    void setInit(bool b);
    bool getFor();
    void setFor(bool b);
    bool getNest();
    void setNest(bool b);
    bool getSearch();
    void setSearch(bool b);
    bool getEx();
    void setEX(bool b);
    bool getTarget();
    void setTarget(bool b);
    bool getFull();
    void setFull(bool b);
    bool getDance();
    void setDance(bool b);
    bool getDanceB();
    void setDanceB(bool b);
    bool getEat();
    void setEat(bool b);
    bool getFoundFood();
    void setFoundFood(bool b);
    bool getTired();
    void setTired(bool b);
    int getSleep();
    void setTime(int b);
    int getTime();
    void setSleep(int b);

    bool getEnter();
    void setEnter(bool b);
    bool getExit();
    string getState();
    string checkExits();
    void setExit(bool b);

    //these are for keeping track of the current state of the forager

private:
    bool hasTarget = false;
    bool isTired = false;
    bool foundFood = false;
    bool isFull = true;
    bool dance = false;
    bool beginDance = false;//state
    bool restOrEat= false;//state
    int timekeeper = 0;
    int sleep = 0;
    bool enterState = false;//state
    bool exitState = true;// state

    bool forageStep = false;//state
    bool initState = false;//state
    bool returnToNest = false;//state
    bool explore = false;//state
    bool searchForThing = false;//state

};

#endif // FORAGER_H
