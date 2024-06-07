#include "game.h"

int Game::highestYellowCardPlayed(){
    int highestPower = playerList[0].highestYellowCard();
    int currentPlayerHighest;
    for(auto i: playerList){
        currentPlayerHighest = i.highestYellowCard();
        if(highestPower < currentPlayerHighest){
            highestPower = currentPlayerHighest;
        }
    }
    return highestPower;
}

std::vector <Player> Game::getPlayerList()const{
    return playerList;
}

void Game::setPlayerList(std::vector <Player> inputList){
    playerList = inputList;
}