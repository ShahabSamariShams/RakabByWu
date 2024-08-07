#include "spy.h"

Spy::Spy(){
    setPriority(5);
    setPower(1);
    setType(spy);
}

void Spy::ability(Game& currentGame){
    currentGame.spyCountIncrementation(currentGame.playerInTurnIndex(currentGame.playerInTurn()->getName()));
    currentGame.playerInTurn()->addToArmyPower(getPower());
}

std::string Spy::getTypeName()const{
    return "spy";
}