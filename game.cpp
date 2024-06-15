#include <bits/stdc++.h> 

#include "game.h"

#include "spring.h"
#include "winter.h"
#include "drummer.h"
#include "scarecrow.h"
#include "heroine.h"

#include "yellowCard.h"

#include "userinterface.h"

Game::Game(){
    //Inputs from the user.
    short numberOfPlayers = UserInterface::receiveNumberOfPlayers();
    setPlayerList(UserInterface::receivePlayerList(numberOfPlayers));
    //Making cards manually using dynamic allocation.
    Card* pointerToCard;
    for(int i = 0; i < 16; i++){
        pointerToCard = new Scarecrow;
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 6; i++){
        pointerToCard = new Drummer;
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 3; i++){
        pointerToCard = new Spring;
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 3; i++){
        pointerToCard = new Winter;
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 3; i++){
        pointerToCard = new Heroine;
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 10; i++){
        pointerToCard = new YellowCard(1);
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 8; i++){
        pointerToCard = new YellowCard(2);
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 8; i++){
        pointerToCard = new YellowCard(3);
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 8; i++){
        pointerToCard = new YellowCard(4);
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 8; i++){
        pointerToCard = new YellowCard(5);
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 8; i++){
        pointerToCard = new YellowCard(6);
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 8; i++){
        pointerToCard = new YellowCard(10);
        deckOfCards.push_back(pointerToCard);
    }
}

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

std::string Game::getSeason()const{
    return season->getTypeName();
}

Player* Game::playerInTurn()const{
    return playedPurpleCards.back().second;
}

void Game::distributeCards(){
    std::shuffle(deckOfCards.begin(), deckOfCards.end(), std::default_random_engine(0));
    std::vector <Card*> handtoBeGiven;
    for(int i = 0; i < playerList.size(); i++){
        handtoBeGiven.clear();
        for(int j = 0; j < 10 + playerList[i].numberOfTakenCities(); j++){
            handtoBeGiven.push_back(deckOfCards.back());
            deckOfCards.pop_back();
        }
        playerList[i].setCardsInHand(handtoBeGiven);
    }
}

void Game::addToPlayedPurpleCards(Card* cardToBeAdded, Player* currentPlayer){
    if(cardToBeAdded != NULL){
        std::pair <Card*, Player*> toBeAdded{cardToBeAdded, currentPlayer};
        playedPurpleCards.push_back(toBeAdded);
    }
}

void Game::war(int index){
    std::vector <bool> passed(playerList.size(), false);
    std::string playerInput;
    for(int i = index; !endOfWar(passed); i++){
        if(!passed[i]){
            UserInterface::bringThePlayer(playerList[i].getName());
            while(true){
                UserInterface::displayPlayersAndTheirPlayed(playerList, playedPurpleCards);
                UserInterface::displayPlayersCities(playerList);
                playerInput = UserInterface::play(playerList[i]);
                if(playerInput != "help" && playerInput != "empty"){
                    if(playerInput != "pass" && playerList[i].cardExistance(playerInput)){
                        addToPlayedPurpleCards(playerList[i].playACard(playerInput), &playerList[i]); 
                        break;
                    }
                    else if(playerInput == "pass"){
                        passed[i] = true;
                        break;
                    }
                    else{
                        /*cardNonExistenceError()*/
                    }
                }
            }
        }
    }
}

bool Game::endOfWar(std::vector <bool> passed){
    std::vector <int> indexOfNonPassers;
    for(int i = 0; i < passed.size(); i++){
        if(!passed[i]){
            indexOfNonPassers.push_back(i);
        }
    }
    if(indexOfNonPassers.size() == 0){
        return true;
    }
    for(int i = 0; i < indexOfNonPassers.size(); i++){
        if(!playerList[indexOfNonPassers[i]].emptyHand()){
            return false;
        }
    }
    return true;
}

int main(){
    Game theGame;
    return 0;
}