#include "brood.h"

Brood::Brood()
{

}
Brood::~Brood()
{

}
bool Brood::CheckDeath(){

}
void Brood::setFert(bool x){
    Fertilized=x;
}
void Brood::setcare(bool x){
    isCaredFor =x;
}
bool Brood::getFert(){
    return Fertilized;
}
bool Brood::getcare(){
    return isCaredFor;
}
