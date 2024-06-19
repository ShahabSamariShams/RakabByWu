#include "userinterface.h"

#include "scarecrow.h"

Scarecrow::Scarecrow(){
    setPriority(0);
    setPower(0);
    setType(scarecrow);
}

void Scarecrow::ability(Game& currentGame){
    Player* tempPlayerAddress = currentGame.playerInTurn();
    std::vector <Card*> tempYellowArmy = tempPlayerAddress->getYellowArmy();
    if(tempYellowArmy.size() > 0){
        std::vector <Card*> tempHand = tempPlayerAddress->getCardsInHand();
        int resurrected = UserInterface::scarecrowEntry(tempYellowArmy);
        std::vector <Card*>::iterator pointer = tempYellowArmy.begin();
        for(int i = 0; i < tempYellowArmy.size(); i++, pointer++){
            if(tempYellowArmy[i]->getPower() == resurrected){
                tempHand.push_back(tempYellowArmy[i]);
                tempYellowArmy.erase(pointer);
                tempPlayerAddress->setCardsInHand(tempHand);
                tempPlayerAddress->setYellowArmy(tempYellowArmy);
                return;
            }
        }
    }
}

std::string Scarecrow::getTypeName()const{
    return "scarecrow";
}