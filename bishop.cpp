#include "bishop.h"

Bishop::Bishop(){
    setPriority(0);
    setPower(0);
    setType(bishop);
}

void Bishop::ability(Game& currentGame){
    currentGame.setIndexOfPeaceMarkOwner(currentGame.playerInTurnIndex(currentGame.playerInTurn()->getName()));

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

    currentGame.setPlayerList(tempPlayerList);

    currentGame.burnCards(highestYellowCards);
}

std::string Bishop::getTypeName()const{
    return "bishop";
}