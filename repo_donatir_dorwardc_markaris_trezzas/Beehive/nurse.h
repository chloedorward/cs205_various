#ifndef NURSE_H
#define NURSE_H
#include "bee.h"

class Nurse: public Bee
{
public:
    Nurse();
    ~Nurse();
    virtual bool CheckDeath();
   void careForBrood();
};

#endif // NURSE_H
