#include "mark.h"

Mark::Mark(){
    setMarkOn(NULL);
}

City* Mark::whereIsIt()const{
    return cityAddress;
}

void Mark::setMarkOn(City* destinedCity){
    cityAddress = destinedCity;
}

void Mark::setColor(Color inputColor){
    color = inputColor;
}