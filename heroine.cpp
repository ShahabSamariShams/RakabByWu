#include "heroine.h"

Heroine::Heroine(){
    setPriority(5);
    setPower(10);
    setType(heroine);
}

void Heroine::ability(Game& currentGame){
    Player* tempPlayerAddress = currentGame.playerInTurn();
    tempPlayerAddress->addToArmyPower(getPower());
}

std::string Heroine::getTypeName()const{
    return "heroine";
}