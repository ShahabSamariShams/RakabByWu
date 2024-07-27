#include "winter.h"

Winter::Winter(){
    setPriority(2);
    setPower(0);
    setType(winter);
}

void Winter::ability(Game& currentGame){
    std::vector <Player> tempPlayerList = currentGame.getPlayerList();
    std::vector <Card*> tempYellowArmy;
    for(int i = 0; i < tempPlayerList.size(); i++){
        tempYellowArmy = tempPlayerList[i].getYellowArmy();
        int powerSum = 0;
        for(int i = 0; i < tempYellowArmy.size(); i++){
            powerSum += tempYellowArmy[i]->getPower() / 2;
        }
        tempPlayerList[i].setArmyPower(powerSum);
    }
    currentGame.setPlayerList(tempPlayerList);
}

std::string Winter::getTypeName()const{
    return "winter";
}