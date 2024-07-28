#include "pegasus.h"

Pegasus::Pegasus(){
    setPriority(0);
    setPower(0);
    setType(pegasus);
}

void Pegasus::ability(Game& currentGame){
    currentGame.pegasusPlayed();
}

std::string Pegasus::getTypeName()const{
    return "pegasus";
}