#include "card.h"

Card::Card(){}

void Card::setType(CardType inputType){
    type = inputType;
}

void Card::setPower(float inputPower){
    if(inputPower < 0){
        inputPower = 0;
    }
    power = inputPower;
}

CardType Card::getType()const{
    return type;
}

float Card::getPower()const{
    return power;
}