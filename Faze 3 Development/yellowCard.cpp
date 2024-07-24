#include "yellowCard.h"

YellowCard::YellowCard(unsigned short inputPower = 1){
    setType(soldier);
    setPower(inputPower);
}

std::string YellowCard::getTypeName()const{
    return "soldier";
}