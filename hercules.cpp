#include "hercules.h"

Hercules::Hercules(){
    setPriority(0);
    setPower(0);
    setType(hercules);
}

void Hercules::ability(Game& currentGame){
    currentGame.playerInTurn()->aCityWon(currentGame.currentWarPlace(), 4);
}

std::string Hercules::getTypeName()const{
    return "hercules";
}