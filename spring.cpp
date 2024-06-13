#include "spring.h"

Spring::Spring(){
    setPriority(4);
    setPower(0);
}

void Spring::ability(Game& currentGame){
    int highestCard = currentGame.highestYellowCardPlayed();
    std::vector <Player> tempPlayerList = currentGame.getPlayerList();
    std::vector <Card*> tempYellowArmy;
    int playerTempHighest;
    for(int i = 0; i < tempPlayerList.size(); i++){
        playerTempHighest = tempPlayerList[i].highestYellowCard();
        if(highestCard == playerTempHighest){
            tempYellowArmy = tempPlayerList[i].getYellowArmy();
            int counter = 0;
            for(int i = 0; i < tempYellowArmy.size(); i++){
                if(tempYellowArmy[i]->getPower() == highestCard){
                    counter++;
                }
            }
            tempPlayerList[i].addToArmyPower(counter * 3);
        }
    }
    currentGame.setPlayerList(tempPlayerList);
}

std::string Spring::getTypeName()const{
    return "spring";
}