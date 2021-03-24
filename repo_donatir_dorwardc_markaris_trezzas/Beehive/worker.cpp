#include "worker.h"

Worker::Worker()
{

}
Worker::~Worker()
{

}
bool Worker::CheckDeath(){}
bool Worker::getGuardDuty(){
    return guardDuty;
}
void Worker::setGuardDuty(bool x){
    guardDuty=x;
}
bool Worker::getGuardFar(){
    return howFarToGuard;
}
void Worker::setGuardFar(bool x){
    howFarToGuard=x;
}
int Worker::getGuardTime(){
    return timeToGuard;
}
void Worker::setGuardTime(bool x){
    timeToGuard =x;
}
int Worker::getGuardLength(){
    return LengthOfGuard;
}
void Worker::setGuardLength(bool x){
    LengthOfGuard =x;
}
