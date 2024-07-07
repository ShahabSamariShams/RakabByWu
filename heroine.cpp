#include "heroine.h"

Heroine::Heroine(){
    setPriority(5);
    setPower(10);
    setType(heroine);
}

void Heroine::ability(Game& currentGame){
    currentGame.playerInTurn()->addToArmyPower(getPower());
}

std::string Heroine::getTypeName()const{
    return "heroine";
}