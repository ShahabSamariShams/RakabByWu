#include "jungleSpirit.h"

JungleSpirit::JungleSpirit(){
    setPriority(0);
    setPower(0);
    setType(jungleSpirit);
}

void JungleSpirit::ability(Game& currentGame){
    if(currentGame.currentWarPlace().haveJungle())
        currentGame.playerInTurn()->aCityWon(currentGame.currentWarPlaceName(), 2);
}

std::string JungleSpirit::getTypeName()const{
    return "jungle spirit";
}