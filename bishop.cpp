#include "bishop.h"

Bishop::Bishop(){
    setPriority(1);
    setPower(0);
    setType(bishop);
}

void Bishop::ability(Game& currentGame){
    int highestPower = currentGame.highestYellowCardPlayed();
    std::vector <Player> tempPlayerList = currentGame.getPlayerList();
    std::vector <Card*> highestYellowCards;
    std::vector <Card*> tempYellowArmy;

    for(int i = 0; i < tempPlayerList.size(); i++){
        tempYellowArmy = tempPlayerList[i].getYellowArmy();
        for(int i = 0; i < tempYellowArmy.size(); i++){
            if(tempYellowArmy[i]->getPower() == highestPower){
                highestYellowCards.push_back(tempYellowArmy[i]);
                tempYellowArmy.erase(tempYellowArmy.begin() + i);
            }
        }
        tempPlayerList[i].setYellowArmy(tempYellowArmy);
    }

    currentGame.burnCards(highestYellowCards);
}

std::string Bishop::getTypeName()const{
    return "bishop";
}