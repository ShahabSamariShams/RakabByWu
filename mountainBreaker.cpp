#include "mountainBreaker.h"

MountainBreaker::MountainBreaker(){
    setPower(0);
    setPriority(0);
    setType(mountainBreaker);
}

void MountainBreaker::ability(Game& currentGame){
    if(currentGame.currentWarPlace().haveMountain())
        currentGame.playerInTurn()->aCityWon(currentGame.currentWarPlaceName(), 3);
}

std::string MountainBreaker::getTypeName()const{
    return "mountain breaker";
}