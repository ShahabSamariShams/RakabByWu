#include "card.h"

Card::Card(){}

void Card::setType(CardType inputType){
    type = inputType;
}

std::string Card::getTypeName()const{
    switch(type){
        case soldier:
            return "soldier";
            break;
        case scarecrow:
            return "scarecrow";
            break;
        case turncoat:
            return "turncoat";
            break;
        case bishop:
            return "bishop";
            break;
        case winter:
            return "winter";
            break;
        case drummer:
            return "drummer";
            break;
        case spring:
            return "spring";
            break;
        case spy:
            return "spy";
            break;
        case heroine:
            return "heroine";
            break;
    }
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