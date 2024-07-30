#include "hercules.h"

Hercules::Hercules(){
    setPriority(0);
    setPower(0);
    setType(hercules);
}

void Hercules::ability(Game& currentGame){
    if(currentGame.currentWarPlace().haveCastle())
        currentGame.playerInTurn()->aCityWon(currentGame.currentWarPlaceName(), 4);
}

std::string Hercules::getTypeName()const{
    return "hercules";
}