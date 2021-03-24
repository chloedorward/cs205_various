#ifndef JUVINILE_H
#define JUVINILE_H
#include "bee.h"

class Juvinile: public Bee
{
public:
    Juvinile();
    ~Juvinile();
    virtual bool CheckDeath();
};

#endif // JUVINILE_H
