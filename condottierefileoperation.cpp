#include "condottierefileoperation.h"

#include <fstream>
#include <vector>
#include <iostream>

#include "yellowCard.h"
#include "scarecrow.h"
#include "turncoat.h"
#include "drummer.h"
#include "spring.h"
#include "winter.h"
#include "spy.h"
#include "bishop.h"
#include "heroine.h"
#include "jungleSpirit.h"
#include "mountainBreaker.h"
#include "hercules.h"

#include "game.h"
#include "player.h"
#include "card.h"
#include "mark.h"
#include "midGameData.h"

void CondottiereFileOperation::writeTheGame(std::string fileName, Game currentGame){
    std::ofstream write(fileName);
    
    //Players:
    std::vector <Player> playerList = currentGame.playerList;
    write << playerList.size() << "\n";
    for(int i = 0; i < playerList.size(); i++){
        write << playerList[i].getName() <<"\n";
        write << playerList[i].getAge() << "\n";
        write << playerList[i].getColor() << "\n";

        std::vector <Card*> cardsInHand = playerList[i].getCardsInHand();
        write << cardsInHand.size() << "\n";
        for(int i = 0; i < cardsInHand.size(); i++){
            write << cardsInHand[i]->getType() << " " << (cardsInHand[i]->getType() == soldier? std::to_string(cardsInHand[i]->getPower()): " ") << " ";
        }
        write << "\n";

        std::vector <Card*> yellowArmy = playerList[i].getYellowArmy();
        write << yellowArmy.size() << "\n";
        for(int i = 0; i < yellowArmy.size(); i++){
            write << yellowArmy[i]->getPower() << " ";
        }
        write << "\n";

        write << playerList[i].getArmyPower() << "\n";

        write << playerList[i].numberOfTakenCities() << "\n";
        std::vector <Mark> marks = playerList[i].getMarks();
        for(int i = 0; i < playerList[i].numberOfTakenCities(); i++){
            write << marks[i].whereIsIt()->getName() << " ";
        }
        write << "\n";

        std::unordered_map <std::string, std::pair <int, CityGuards>> wonCities = playerList[i].getWonCities();
        write << wonCities.size() << "\n";
        for(auto i: wonCities){
            write << i.first << " " << i.second.first << " " << i.second.second.castle << " " << i.second.second.mountain << " " << i.second.second.jungle << " ";
        }
        write << "\n";
    }

    //Deck of cards:
    std::vector <Card*> deckOfCards = currentGame.deckOfCards;
    write << deckOfCards.size() << "\n";
    for(int i = 0; i < deckOfCards.size(); i++){
        write << deckOfCards[i]->getType() << " " << (deckOfCards[i]->getType() == soldier? std::to_string(deckOfCards[i]->getPower()): " ") << " ";
    }
    write << "\n";

    //Played purple cards:
    std::vector <std::pair <Card*, Player*>> playedPurpleCards = currentGame.playedPurpleCards;
    write << playedPurpleCards.size() << "\n";
    for(int i = 0; i < playedPurpleCards.size(); i++){
        write << playedPurpleCards[i].first->getType() << "\n" << playedPurpleCards[i].second->getName() << "\n";
    }

    //Season:
    if(currentGame.season == NULL){
        write << "0\n";
    }
    else{
        write << currentGame.season->getType() << "\n";
    }

    //Black mark and peace mark:
    write << currentGame.blackMark.whereIsIt()->getName() << "\n";
    if(currentGame.peaceMark.whereIsIt() == NULL){
        write << "0\n";
    }
    else{
        write << currentGame.peaceMark.whereIsIt()->getName() << "\n";
    }

    //Mid-Game Data:
    MidGameData midGameData = currentGame.midGameData;
    write << midGameData.indexOfPeaceMarkOwner << " " << midGameData.indexOfPlayerInTurn << " " 
    << midGameData.indexOfWarStarter << "\n" << (midGameData.winner == NULL? "0": midGameData.winner->getName()) << "\n" << 
    midGameData.isTurncoatPlayed << "\n";
    for(int i = 0; i < playerList.size(); i++){
        write << midGameData.passed[i] << " " << midGameData.spyCount[i] << " ";
    }

    write.close();
}

void CondottiereFileOperation::readTheGame(std::string fileName, Game& currentGame){
    std::ifstream read(fileName);

    int size;

    //Players:
    int numberOfPlayers;

    std::string name;
    float age;
    int enumSaver, soldierPower, armyPower;

    read >> numberOfPlayers;
    std::vector <Player> playerList(numberOfPlayers);
    for(int i = 0; i < numberOfPlayers; i++){
        name = "\0";
        do{
            getline(read, name);
        }while(name == "\0");
        playerList[i].setName(name);
        read >> age;         playerList[i].setAge(age);
        read >> enumSaver;   playerList[i].setMarksColor(enumSaver);

        read >> size;
        std::vector <Card*> cardsInHand(size);
        for(int i = 0; i < size; i++){
            read >> enumSaver;
            if(enumSaver == 0){
                read >> soldierPower;
                cardsInHand[i] = cardMaker(enumSaver, soldierPower);
            }
            else{
                cardsInHand[i] = cardMaker(enumSaver);
            }
        }
        playerList[i].setCardsInHand(cardsInHand);

        read >> size;
        std::vector <Card*> yellowArmy(size);
        for(int i = 0; i < size; i++){
            read >> soldierPower;
            yellowArmy[i] = cardMaker(0, soldierPower);
        }
        playerList[i].setYellowArmy(yellowArmy);

        read >> armyPower; playerList[i].setArmyPower(armyPower);

        read >> size;
        std::vector <Mark> marks(5);
        for(int i = 0; i < size; i++){
            read >> name;
            marks[i].setMarkOn(currentGame.theMap.toBeFoughtFor(name));
            currentGame.theMap.toBeFoughtFor(name)->setFightability(false);
        }
        playerList[i].setMarks(marks);

        std::unordered_map <std::string, std::pair <int, CityGuards>> wonCities;
        read >> size;
        for(int i = 0; i < size; i++){
            read >> name;
            read >> wonCities[name].first >> wonCities[name].second.castle >> wonCities[name].second.mountain >> wonCities[name].second.jungle; 
        } 
    }
    currentGame.playerList = playerList;
    std::cout << "out of players" << std::endl;

    std::cout << "1"; system("pause");
    //Deck of cards:
    read >> size;
    std::vector <Card*> deckOfCards(size);
    for(int i = 0; i < size; i++){
        read >> enumSaver;
        if(enumSaver == 0){
            read >> soldierPower;
            deckOfCards[i] = cardMaker(enumSaver, soldierPower);
        }
        else{
            deckOfCards[i] = cardMaker(enumSaver);
        }
    }
    currentGame.deckOfCards = deckOfCards;

    std::cout << "1"; system("pause");
    //Played purple cards:
    read >> size;
    std::vector <std::pair <Card*, Player*>> playedPurpleCard(size);
    for(int i = 0; i < size; i++){
        read >> enumSaver;   playedPurpleCard[i].first = cardMaker(enumSaver);
        name = "\0";
        do{
            getline(read, name);
        }while(name == "\0");
        playedPurpleCard[i].second = &(currentGame.playerList[currentGame.playerInTurnIndex(name)]);
    }
    currentGame.playedPurpleCards = playedPurpleCard;

    std::cout << "1"; system("pause");
    //Season:
    read >> enumSaver;
    if(enumSaver != 0){
        currentGame.season = cardMaker(enumSaver);
    }
    else{
        currentGame.season = NULL;
    }

    std::cout << "1"; system("pause");
    //Black mark and peace mark:
    read >> name;
    currentGame.blackMark.setMarkOn(currentGame.theMap.toBeFoughtFor(name));
    read >> name;
    if(name != "0"){
        currentGame.peaceMark.setMarkOn(currentGame.theMap.toBeFoughtFor(name));
    }
    else{
        currentGame.peaceMark.setMarkOn(NULL);
    }

    std::cout << "1"; system("pause");
    //Mid-Game Data:
    read >> currentGame.midGameData.indexOfPeaceMarkOwner
    >> currentGame.midGameData.indexOfPlayerInTurn
    >> currentGame.midGameData.indexOfWarStarter;
    std::cout << "2"; system("pause");
    name = "\0";
    do{
        getline(read, name);
    }while(name == "\0");
    std::cout << "2"; system("pause");
    if(name != "0"){
        currentGame.midGameData.winner = &currentGame.playerList[currentGame.playerInTurnIndex(name)];
    }
    else{
        currentGame.midGameData.winner = NULL;
    }
    std::cout << "2"; system("pause");
    read >> currentGame.midGameData.isTurncoatPlayed;
    std::cout << "2"; system("pause");
    std::vector <bool> passed(numberOfPlayers);
    std::vector <int> spyCount(numberOfPlayers);
    bool temp;
    for(int i = 0; i < currentGame.playerList.size(); i++){
        read >> temp >> spyCount[i];
        passed[i] = temp;
    }
    currentGame.midGameData.passed = passed;
    currentGame.midGameData.spyCount = spyCount;
    std::cout << "2"; system("pause");

    read.close();
}

Card* CondottiereFileOperation::cardMaker(int enumType){
    Card* pointer;
    switch(enumType){
        case 1:
            pointer = new Scarecrow;
            break;
        case 2:
            pointer = new Turncoat;
            break;
        case 3:
            pointer = new JungleSpirit;
            break;
        case 4:
            pointer = new MountainBreaker;
            break;
        case 5:
            pointer = new Hercules;
            break;
        case 6:
            pointer = new Bishop;
            break;
        case 7:
            pointer = new Winter;
            break;
        case 8:
            pointer = new Drummer;
            break;
        case 9:
            pointer = new Spring;
            break;
        case 10:
            pointer = new Spy;
            break;
        case 11:
            pointer = new Heroine;
            break;
    }
    return pointer;
}

Card* CondottiereFileOperation::cardMaker(int enumType, int soldierPower){
    Card* pointer = new YellowCard(soldierPower);
    return pointer;
}