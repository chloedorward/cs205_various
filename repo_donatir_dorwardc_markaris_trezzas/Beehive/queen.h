#ifndef QUEEN_H
#define QUEEN_H
#include <stdio.h>
#include <stdlib.h>     /*rand */
#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <random>
#include <algorithm>
using namespace std;

class Queen
{
public:
    Queen();
    ~Queen();
    void BirthEggs(int season,double pollenGen,double pollenUsed);
    double fertilizeEggs(int y);
    void setAge(int x);
    void setFed(bool x);
    bool getFed();
    int getAge();
    void setRatio(double x);
    void setSeason(int x);
    double getRatio();
    int getSeason();
    void setEgg(int x);
    int getEgg();
    double lookup(int season);
private:
    std::default_random_engine generator;

    int Age;
    int eggsMadeToday;
    bool isFed;
    int season;
    double ratioFert;
};

#endif // QUEEN_H
