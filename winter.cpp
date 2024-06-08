#include "winter.h"

Winter::Winter(){
    setPriority(2);
    setPower(0);
}

void Winter::ability(Game& currentGame){
    std::vector <Player> tempPlayerList = currentGame.getPlayerList();;
    for(int i = 0; i < tempPlayerList.size(); i++){
        tempPlayerList[i].setArmyPower(tempPlayerList[i].yellowArmySize());
    }
    currentGame.setPlayerList(tempPlayerList);
}