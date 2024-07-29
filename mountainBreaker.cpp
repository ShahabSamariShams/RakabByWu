#include "mountainBreaker.h"

MountainBreaker::MountainBreaker(){
    setPower(0);
    setPriority(0);
    setType(mountainBreaker);
}

void MountainBreaker::ability(Game& currentGame){
    currentGame.playerInTurn()->aCityWon(currentGame.currentWarPlace(), 3);
}

std::string MountainBreaker::getTypeName()const{
    return "mountain breaker";
}