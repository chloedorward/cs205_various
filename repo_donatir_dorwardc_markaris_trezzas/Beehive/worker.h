#ifndef WORKER_H
#define WORKER_H
#include "bee.h"

class Worker: public Bee
{
public:
    Worker();
    ~Worker();
    virtual bool CheckDeath();
    bool getGuardDuty();
    void setGuardDuty(bool x);
    bool getGuardFar();
    void setGuardFar(bool x);
    int getGuardTime();
    void setGuardTime(bool x);
    int getGuardLength();
    void setGuardLength(bool x);

private:
    bool guardDuty;// should it guard
    int timeToGuard;// when to guard
    int LengthOfGuard;// how long to guard
    bool howFarToGuard;// which gate to guard


};

#endif // WORKER_H
