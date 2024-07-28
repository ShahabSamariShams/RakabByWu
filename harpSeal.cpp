#include "harpSeal.h"

HarpSeal::HarpSeal(){
    setPower(0);
    setPriority(0);
    setType(harpseal);
}

void HarpSeal::ability(Game& currentGame){
    currentGame.resetingArmies(currentGame.getPlayedPurpleCards());
}

std::string HarpSeal::getTypeName()const{
    return "harpseal";
}