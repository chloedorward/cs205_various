#ifndef BEE_H
#define BEE_H
#include <stdio.h>
#include <stdlib.h>     /*rand */
#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>

class Bee
{
public:
     Bee();
    virtual ~Bee();
     Bee(int age);
    virtual bool CheckDeath();
     void setAge(int x);
     void setFed(bool x);
     bool getFed();
     int getAge();
     bool getEN1();
     void setEN1(bool b);
     bool getEX2();
     void setEX2(bool b);
     bool getEN2();
     void setEN2(bool b);
     bool getEx1();
     void setEX1(bool b);

private:
    int Age = 0;
    bool IsFed = true;
    bool hasEnteredGate1 = false;
    bool hasEnteredGate2 = false;
    bool HasExitedGate1 = false;
    bool HasExitedGate2 = false;

};

#endif // BEE_H
