#include "card.h"

Card::Card(){}

void Card::setType(CardType inputType){
    type = inputType;
}

void Card::setPower(unsigned short inputPower){
    if(inputPower < 0){
        inputPower = 0;
    }
    power = inputPower;
}

CardType Card::getType()const{
    return type;
}

unsigned short Card::getPower()const{
    return power;
}