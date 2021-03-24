#include <iostream>
#include "beehive.h"
using namespace std;

int main()
{
      cout<<"beginning of main."<<endl;

      Beehive b("testID",100/* num of bees*/,10/* num of boards*/,1000/*swarm/attack number*/,.05/*growth function*/);

      b.run();
}
