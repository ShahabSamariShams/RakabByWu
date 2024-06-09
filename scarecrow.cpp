#include "scarecrow.h"

Scarecrow::Scarecrow(){
    setPriority(0);
    setPower(0);
}

void Scarecrow::ability(Game& currentGame){
    Player* tempPlayerAddress = currentGame.playerInTurn();
    /*
    We need user interface function to return a pointer to the card we
    are going to remove. So this part is going to remain empty like 
    this for some time till we complete the user interface class.
    */
}

std::string Scarecrow::getTypeName()const{
    return "scarecrow";
}