#ifndef BROOD_H
#define BROOD_H
#include "bee.h"

class Brood : public Bee
{
public:
    Brood();
    ~Brood();
    virtual bool CheckDeath();
    void setFert(bool x);
    void setcare(bool x);
    bool getFert();
    bool getcare();
private:
   bool Fertilized;//true is yes false is no
   bool isCaredFor;


};

#endif // BROOD_H
