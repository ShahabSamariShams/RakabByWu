#include <bits/stdc++.h> 

#include "game.h"

#include "bishop.h"
#include "spring.h"
#include "winter.h"
#include "drummer.h"
#include "scarecrow.h"
#include "heroine.h"
#include "spy.h"

#include "purpleCard.h"
#include "yellowCard.h"

#include "userinterface.h"

//------------------------------------------------------------------

void merge(std::vector <std::pair <Card*, Player*>>& playedPurpleCards, int start, int end, int middle){
    int leftPointer = start, rightPointer = middle + 1;
    std::vector <std::pair <Card*, Player*>> tempSorted;
    while(leftPointer <= middle && rightPointer <= end){
        if(static_cast<PurpleCard*>(playedPurpleCards[leftPointer].first)->getPriority() < static_cast<PurpleCard*>(playedPurpleCards[rightPointer].first)->getPriority()){
            tempSorted.push_back(playedPurpleCards[leftPointer]);
            leftPointer++;
        }
        else{
            tempSorted.push_back(playedPurpleCards[rightPointer]);
            rightPointer++;
        }
    }

    while(leftPointer <= middle){
        tempSorted.push_back(playedPurpleCards[leftPointer]);
        leftPointer++;
    }
    while(rightPointer <= end){
        tempSorted.push_back(playedPurpleCards[rightPointer]);
        rightPointer++;
    }

    for(int i = start, j = 0; i <= end; i++, j++){
        playedPurpleCards[i] = tempSorted[j];
    }
}

void mergeSort(std::vector <std::pair <Card*, Player*>>& playedPurpleCards, int start, int end){
    if(start >= end){
        return;
    }
    int middle = (start + end) / 2;
    mergeSort(playedPurpleCards, start, middle);
    mergeSort(playedPurpleCards, middle + 1, end);
    merge(playedPurpleCards, start, end, middle);
}

//------------------------------------------------------------------

Game::Game(){
    //Inputs from the users.
    short numberOfPlayers = UserInterface::receiveNumberOfPlayers();
    setPlayerList(UserInterface::receivePlayerList(numberOfPlayers));

    //Marks
    blackMark.setMarkOn(NULL);
    peaceMark.setMarkOn(NULL);

    //Making cards manually using dynamic allocation.
    //Purple cards:
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
    for(int i = 0; i < 6; i++){
        pointerToCard = new Bishop;
        deckOfCards.push_back(pointerToCard);
    }
    for(int i = 0; i < 12; i++){
        pointerToCard = new Spy;
        deckOfCards.push_back(pointerToCard);
    }

    //Yellow cards:
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

    //Season:
    season = NULL;

    //Mid-game data:
    midGameData.resizeList(playerList.size());
}

//------------------------------------------------------------------

void Game::setSeason(Card* seasonToBeSetted){
    if(season != NULL)
        deckOfCards.push_back(season);
    season = seasonToBeSetted;
}

void Game::setPlayerList(std::vector <Player> inputList){
    playerList = inputList;
}

void Game::setIndexOfPeaceMarkOwner(int index){
    midGameData.indexOfPeaceMarkOwner = index;
}

//------------------------------------------------------------------

std::vector <Player> Game::getPlayerList()const{
    return playerList;
}

std::string Game::getSeason()const{
    if(season != NULL)
        return season->getTypeName();
    return "empty";
}

int Game::playerInTurnIndex(std::string playerName)const{
    for(int i = 0; i < playerList.size(); i++){
        if(playerList[i].getName() == playerName){
            return i;
        }
    }
}

//------------------------------------------------------------------

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

void Game::burnHandIfPossible(){
    for(int i = 0; i < playerList.size(); i++){
        if(!playerList[i].yellowCardInHand() && !playerList[i].emptyHand()){
            if(UserInterface::receicveAnswer(playerList[i].getName()) == "yes"){
                burnCards(playerList[i].burnCardsInHand());
            }
        }
    }
}

void Game::burnCards(std::vector <Card*> cardsToBurn){
    for(int i = 0; i < cardsToBurn.size(); i++){
        deckOfCards.push_back(cardsToBurn[i]);
    }
}

void Game::distributeCards(){
    std::shuffle(deckOfCards.begin(), deckOfCards.end(), std::default_random_engine(time(0)));
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

bool Game::timeToDistribute(){
    int indexOfTheSingleFullHand;
    int count = 0;
    for(int i = 0; i < playerList.size(); i++){
        if(!playerList[i].emptyHand()){
            count++;
            indexOfTheSingleFullHand = i;
            if(count >= 2){
                return false;
            }
        }
    }
    if(count == 1){
        burnCards(playerList[indexOfTheSingleFullHand].burnCardsInHand());
    }
    return true;
}

void Game::addToPlayedPurpleCards(Card* cardToBeAdded, Player* currentPlayer){
    if(cardToBeAdded != NULL){
        std::pair <Card*, Player*> toBeAdded{cardToBeAdded, currentPlayer};
        playedPurpleCards.push_back(toBeAdded);
    }
}

void Game::resetingArmies(std::vector <Card*> purpleCards){
    burnCards(purpleCards);
    for(int i = 0; i < playerList.size(); i++){
        burnCards(playerList[i].burnYellowArmy());
    }
    season = NULL;
}

std::vector <Card*> Game::calculateThePowers(){
    std::vector <Card*> toBeReturned;
    for(int i = 0; i < playerList.size(); i++){
        playerList[i].setArmyPower(playerList[i].getRawYellowPower());
    }
    while(playedPurpleCards.size() > 0){
        static_cast<PurpleCard*>(playedPurpleCards.back().first)->ability(*this);
        toBeReturned.push_back(playedPurpleCards.back().first);
        playedPurpleCards.pop_back();
    }
    return toBeReturned;
}

//------------------------------------------------------------------

void Game::setTheBlackMark(){
    std::string cityName = UserInterface::callTheBlackMarkOwner(playerList[midGameData.indexOfWarStarter], theMap);
    blackMark.setMarkOn(theMap.toBeFoughtFor(cityName));
}

void Game::spyCountIncrementation(int index){
    midGameData.spyCount[index]++;
}

void Game::setThePeaceMark(){
    if(midGameData.indexOfPeaceMarkOwner != -1){
        if(peaceMark.whereIsIt() != NULL){
            peaceMark.whereIsIt()->setFightability(true);
        }
        std::string cityName = UserInterface::callThePeaceMarkOwner(playerList[midGameData.indexOfPeaceMarkOwner], theMap);
        if(cityName != "0"){
            peaceMark.setMarkOn(theMap.toBeFoughtFor(cityName));
            peaceMark.whereIsIt()->setFightability(false);
        }
    }
}

int Game::findTheYoungest(){
    std::vector <int> indexOfTheYoungest;
    int leastAge = playerList[0].getAge();
    for(int i = 0; i < playerList.size(); i++){
        if(playerList[i].getAge() < leastAge){
            leastAge = playerList[i].getAge();
            indexOfTheYoungest.clear();
            indexOfTheYoungest.push_back(i);
        }
        else if(playerList[i].getAge() == leastAge){
            indexOfTheYoungest.push_back(i);
        }
    }
    int index = rand() % indexOfTheYoungest.size();
    return indexOfTheYoungest[index];
}

//------------------------------------------------------------------

Player* Game::playerInTurn()const{
    return playedPurpleCards.back().second;
}

//------------------------------------------------------------------

void Game::war(){
    std::string playerInput;
    for(int i = midGameData.indexOfWarStarter; !endOfWar(midGameData.passed); i++){
        if(!midGameData.passed[i]){
            UserInterface::bringThePlayer(playerList[i].getName());
            while(true){
                system("cls");
                UserInterface::displayPlayersAndTheirPlayed(playerList, playedPurpleCards);
                UserInterface::displayPlayersCities(playerList);
                UserInterface::displayBlackMarkCity(blackMark.whereIsIt());
                UserInterface::displaySeason(season);
                playerInput = UserInterface::play(playerList[i]);
                if(playerInput != "help" && playerInput != "empty"){
                    if(playerInput != "pass" && playerList[i].cardExistance(playerInput)){
                        addToPlayedPurpleCards(playerList[i].playACard(playerInput), &playerList[i]);
                        if(playerInput == "scarecrow" || playerInput == "bishop"){
                            static_cast<PurpleCard*>(playedPurpleCards.back().first)->ability(*this);
                            deckOfCards.push_back(playedPurpleCards.back().first);
                            playedPurpleCards.pop_back();
                            if(playerInput == "bishop"){
                                midGameData.indexOfPeaceMarkOwner = i;
                            }
                        }
                        else if(playerInput == "winter" || playerInput == "spring"){
                            setSeason(playedPurpleCards.back().first);
                            playedPurpleCards.pop_back();
                        }
                        break;
                    }
                    else if(playerInput == "pass"){
                        midGameData.passed[i] = true;
                        midGameData.indexOfWarStarter = i;
                        break;
                    }
                    else{
                        /*cardNonExistenceError()*/
                    }
                }
            }
        }
        if(i == playerList.size() - 1){
            i = -1;
        }
    }
    int highestSpyIndex = 0, count = 0;
    for(int i = 0; i < midGameData.spyCount.size(); i++){
        if(midGameData.spyCount[highestSpyIndex] < midGameData.spyCount[i]){
            count = 1;
            highestSpyIndex = i;
        }
        else if(midGameData.spyCount[highestSpyIndex] == midGameData.spyCount[i]){
            count++;
        }
    }
    if(count == 1){
        midGameData.indexOfWarStarter = highestSpyIndex;
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



Player* Game::whoWonTheWar(){
    std::vector <Player*> highestPowers;
    int highestPower = playerList[0].getArmyPower();
    for(int i = 0; i < playerList.size(); i++){
        if(playerList[i].getArmyPower() > highestPower){
            highestPower = playerList[i].getArmyPower();
            highestPowers.clear();
            highestPowers.push_back(&playerList[i]);
        }
        else if(highestPower == playerList[i].getArmyPower()){
            highestPowers.push_back(&playerList[i]);
        }
    }

    if(highestPowers.size() == 1){
        return highestPowers[0];
    }
    else{
        return NULL;
    }
}

void Game::warWinnerAward(Player* winner){
    std::vector <Mark> tempMarks = winner->getMarks();
    for(int i = 0; i < tempMarks.size(); i++){
        if(tempMarks[i].whereIsIt() == NULL){
            tempMarks[i].setMarkOn(blackMark.whereIsIt());
            winner->setMarks(tempMarks);
            break;
        }
    }
}

//------------------------------------------------------------------

bool Game::oneVicinity(std::vector <City*> adjacency){
    for(int i = 0; i < adjacency.size() - 1; i++){
        for(int j = i; j < adjacency.size(); j++){ 
            if(adjacency[i]->isAdjacent(adjacency[j]->getName())){
                return true;
            }
        }
    }
    return false;
}

//------------------------------------------------------------------

bool Game::gameWinner(Player* warWinner){
    if(warWinner->numberOfTakenCities() == 5){
        return true;
    }
    if(warWinner->numberOfTakenCities() >= 3){
        std::vector <Mark> marks = warWinner->getMarks();
        std::vector <City*> adjacency; 
        for(int i = 0; i < warWinner->numberOfTakenCities(); i++){
            adjacency.clear();
            for(int j = 0; j < warWinner->numberOfTakenCities(); j++){
                if(marks[i].whereIsIt()->isAdjacent(marks[j].whereIsIt()->getName())){ 
                    adjacency.push_back(marks[j].whereIsIt());
                }
            }
            if(oneVicinity(adjacency)){
                return true;
            }  
        }
    }
    return false;
}



void Game::runGame(){
    midGameData.indexOfWarStarter = findTheYoungest();
    while(true){
        midGameData.reset();
        setTheBlackMark();
        burnHandIfPossible();
        if(timeToDistribute()){
            distributeCards();
        }
        war();

        if(season != NULL){
            std::pair <Card*, Player*> toBeAdded;
            toBeAdded.first = season;
            toBeAdded.second = NULL;
            playedPurpleCards.push_back(toBeAdded);
        }
        mergeSort(playedPurpleCards, 0, playedPurpleCards.size() - 1);
        std::reverse(playedPurpleCards.begin(), playedPurpleCards.end());
        std::vector <Card*> purpleCards = calculateThePowers();
        Player* winner = whoWonTheWar();
        resetingArmies(purpleCards);
        if(winner != NULL){
            warWinnerAward(winner);
            UserInterface::announceTheLocalWarWinner(winner);
            if(gameWinner(winner)){
                UserInterface::announceTheWinner(winner);
                return;
            }
            for(int i = 0; i < playerList.size() && !ownershipDeterminedBySpy; i++){
                if(playerList[i].getName() == winner->getName()){
                    midGameData.indexOfWarStarter = i;
                    break;
                }
            }
            blackMark.whereIsIt()->setFightability(false);
        }
        setThePeaceMark();
    }
}