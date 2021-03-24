#ifndef BEEHIVE_H
#define BEEHIVE_H
#include <stdio.h>
#include <stdlib.h>     /*rand */
#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include "queen.h"
#include "nurse.h"
#include "worker.h"
#include "juvinile.h"
#include "forager.h"
#include "drone.h"
#include "brood.h"
#include "bee.h"

#include <queue>
#include <iostream>
#include <fstream>

#include "board.h"
#include <list>
#include <vector>
using namespace std;
class Beehive
{
public:
    Beehive(string ID,int forageNum, int NumOfBoard,int droneNum, double grow);
    ~Beehive();
    void beeSimpleGrowth(double x);
    void randomSwarm();
    bool checkBoards();
    bool dance(Forager *f);
    bool foundFood(Forager *f);
    bool hasTarget(Forager *f);
    bool isTired(Forager *f);
    double getFood();
    double getPollen();
    int getCurrentTime();
    int getNumOfYears();
    int growthfunction(double x);
    int getSeason();
    string boardString();
    string parseTime(int t);
    vector<Bee> getBees();
    vector<Board> getBoards();
    vector<Brood*> getbroods();
    vector<Drone> getDrones();
    vector<Forager> getForagers();
    vector<Juvinile*> getJuviniles();
    vector<Nurse*> getNurses();
    vector<Worker> getWorkers();
    void DefenceHooHaa();
    void OneDayTimeStep();
    void OneHourTimeStep();
    void OneMillisecondTimeStep();
    void OneMinuteTimeStep();
    void OneMonthTimeStep();
    void OneSecondTimeStep();
    void OneWeekTimeStep();
    void OneYearTimeStep();
    void SwarmTech(Bee *b);
    void TheSwarmBaby();
    void attackTech(Bee *b);
    void beginDance(Forager *f);
    void birthBees();
    void calculatePollenGen();
    void calculatePollenUSed();
    void checkbees();
    void enterState(Forager *f);
    void enterStates(Forager *f);
    void evolveBees();
    void exitState(Forager *f);
    void exitStates(Forager* f);
    void explore(Forager *f);
    void feedBees();
    void fertilizeEggs();
    void foodCalculation();
    void forageStep(Forager *f);
    void forageTech(Forager *f);
    void killBees();
    void nurseBees();
    void restOrEat(Forager *f);
    void returnToNest(Forager *f);
    void run();
    void searchForThing(Forager *f);
    void setCurrentTime(int x);
    void setFood(double x);
    void setNumOfBoards(int x);
    void setPollen(double x);
    void setSeason(int x);
    void setStartingValues();// need the starting values
    void setWeather(double s);
    void setYearsToRun(int x);
    void setup();
    void testFunction();
    void udpSetup();
    void updateBoards();
    void updateDatabase();
    void updateQueue();
    void workerTech(Worker w);


private:

    Queen q;
    int droneNum;
    double growthP;
    int forNum;
    int randNumGen;
    bool Attack = true;
    bool domilli = true;
    bool swarm = true;
    double foodAmount= 10000;
    double pollenAmmount = 10000;
    double pollenGen = 100;
    double pollenUsed = 20;
    double temperature = 70;
    int AttackTime = 43200;// rob at noon
    int BeeCounter=0;
int BeeCounter2=0;
    int TOD;
    int boardcycle = 0;
    int changenow;
    int currentTime = 0;
    int exitCounter=0;
     int exitCounter2=0;
    int milliCounter=0;
    int numOfBoards = 10;
    int season = 1;
    int swarmTime = 64800;// swarm at 6:00pm--
    int tempGateThingy =0;
    int tempThingCounter=0;
    int timeOfDay;
    int timeSinceMessage=0;
    int atkC = 0;
    int SWRMC = 0;
    int atkC2 = 0;
    int SWRMC2 = 0;
    std::queue<Bee> myqueue;
    string hiveID = "testID";
    int numofyears = 1;
    vector<Bee> beeVect;
    vector<Board> boardVect;
    vector<Brood*> broodVect;
    vector<Drone> droneVect;
    vector<Forager> forageVect;
    vector<Juvinile*> juviVect;
    vector<Nurse*> nurseVect;
    vector<Worker> workerVect;
    ofstream myfile;



};

#endif // BEEHIVE_H
