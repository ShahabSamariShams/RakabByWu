#include "drummer.h"

Drummer::Drummer(){
    setPriority(3);
    setPower(0);
}

void Drummer::ability(Game& currentGame){
    
}

std::string Drummer::getTypeName()const{
    return "drummer";
}