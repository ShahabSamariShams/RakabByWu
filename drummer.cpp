#include "drummer.h"

Drummer::Drummer(){
    setPriority(3);
    setPower(0);
}

void Drummer::ability(Game& currentGame){
    Player* tempPlayerAddress = currentGame.playerInTurn();
    if(currentGame.getSeason() == "winter"){
        if(tempPlayerAddress->getArmyPower() != tempPlayerAddress->yellowArmySize() * 2){
            tempPlayerAddress->setArmyPower(tempPlayerAddress->getArmyPower() * 2);
        }
    }
    else{
        if(tempPlayerAddress->getArmyPower() != tempPlayerAddress->getRawYellowPower() * 2){
            tempPlayerAddress->setArmyPower(tempPlayerAddress->getArmyPower() * 2);
        }
    }
}

std::string Drummer::getTypeName()const{
    return "drummer";
}