#include "turncoat.h"

Turncoat::Turncoat(){
    setPriority(0);
    setPower(0);
    setType(turncoat);
}

void Turncoat::ability(Game& currentGame){
    currentGame.turncoatPlayed();
}

std::string Turncoat::getTypeName()const{
    return "turncoat";
}