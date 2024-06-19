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

void Card::setPriority(short inputPriority){
    priority = inputPriority;
}

CardType Card::getType()const{
    return type;
}

unsigned short Card::getPower()const{
    return power;
}


short Card::getPriority()const{
    return priority;
}