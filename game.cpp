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

int main(){
    Game theGame;
    return 0;
}