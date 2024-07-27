#include "drummer.h"

Drummer::Drummer(){
    setPriority(3);
    setPower(0);
    setType(drummer);
}

void Drummer::ability(Game& currentGame){
    currentGame.playerInTurn()->setArmyPower(currentGame.playerInTurn()->getArmyPower() * 1.5);
}

std::string Drummer::getTypeName()const{
    return "drummer";
}