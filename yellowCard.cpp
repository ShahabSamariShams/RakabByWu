#include "yellowCard.h"

YellowCard::YellowCard(unsigned short inputPower = 1){
    setType(soldier);
    setPower(inputPower);
}

void YellowCard::ability(Game& currentGame){}

std::string YellowCard::getTypeName()const{
    return "soldier";
}