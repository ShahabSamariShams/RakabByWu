#include "bishop.h"

Bishop::Bishop(){
    setPriority(1);
    setPower(0);
    setType(bishop);
}

void Bishop::ability(Game& currentGame){
    currentGame.setIndexOfPeaceMarkOwner(currentGame.playerInTurnIndex(currentGame.playerInTurn()->getName()));

    int highestPower = currentGame.highestYellowCardPlayed();
    std::vector <Player> tempPlayerList = currentGame.getPlayerList();
    std::vector <Card*> highestYellowCards;
    std::vector <Card*> tempYellowArmy;
    int counterOfCard = 0;

    for(int i = 0; i < tempPlayerList.size(); i++){
        tempYellowArmy = tempPlayerList[i].getYellowArmy();
        counterOfCard = 0;
        for(int i = 0; i < tempYellowArmy.size(); i++){
            if(tempYellowArmy[i]->getPower() == highestPower){
                highestYellowCards.push_back(tempYellowArmy[i]);
                tempYellowArmy.erase(tempYellowArmy.begin() + i);
                counterOfCard++;
            }
        }
        tempPlayerList[i].setYellowArmy(tempYellowArmy);
        tempPlayerList[i].setArmyPower(tempPlayerList[i].getArmyPower() - counterOfCard * highestPower);
    }

    currentGame.setPlayerList(tempPlayerList);

    currentGame.burnCards(highestYellowCards);
}

std::string Bishop::getTypeName()const{
    return "bishop";
}