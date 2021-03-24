#ifndef DRONE_H
#define DRONE_H
#include "bee.h"

class Drone: public Bee
{
public:
    Drone();
    virtual ~Drone();
    virtual bool CheckDeath();
    bool getI();
    void setI(bool b);
private:
    bool onTheInside= true;
};

#endif // DRONE_H
