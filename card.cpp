#include "card.h"

Card::Card(){}

void Card::setType(CardType inputType){
    type = inputType;
}

std::string Card::getTypeName()const{
    return "";
}

CardType Card::getType()const{
    return type;
}

void Card::setPower(unsigned short inputPower){
    if(inputPower <= 0){
        inputPower = 1;
    }
    power = inputPower;
}

unsigned short Card::getPower()const{
    return power;
}

void Card::ability(/*Game*/){
    return;
}