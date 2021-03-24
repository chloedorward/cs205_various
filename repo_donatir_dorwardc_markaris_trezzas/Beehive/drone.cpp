#include "drone.h"

Drone::Drone()
{

}
Drone::~Drone(){

}
bool Drone::CheckDeath(){}

bool Drone::getI(){
    return onTheInside;
}
void Drone::setI(bool b){
    onTheInside = b;
}
