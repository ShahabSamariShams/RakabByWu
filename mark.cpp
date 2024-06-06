#ifndef MARK_H
#define MARK_H
#include "mark.h"
#endif

Mark::Mark(){
    setMarkOn(NULL);
}

City Mark::whereIsIt()const{
    return *cityAddress;
}

void Mark::setMarkOn(City* destinedCity){
    cityAddress = destinedCity;
}

void Mark::setColor(Color inputColor){
    color = inputColor;
}