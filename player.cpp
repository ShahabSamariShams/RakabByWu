#include "player.h"

Player::Player(){
    marks.reserve(5);
}

void Player::setName(std::string inputName){
    name = inputName;
}

std::string Player::getName()const{
    return name;
}

void Player::setAge(float inputAge){
    if(inputAge < 1){
        inputAge = 1;
    }
    age = inputAge;
}

float Player::getAge()const{
    return age;
}

int Player::highestYellowCard(){
    try{
        yellowArmy.at(0);
    }
    catch(std::out_of_range exception){
        return 0;
    }
    int highestPower = yellowArmy[0]->getPower();
    for(auto i: yellowArmy){
        if(i->getPower() > highestPower){
            highestPower = i->getPower();
        }
    }
    return highestPower;
}

std::vector <Card*> Player::getYellowArmy()const{
    return yellowArmy;
}

void Player::setYellowArmy(std::vector <Card*> inputArmy){
    yellowArmy = inputArmy;
}

int Player::getArmyPower()const{
    return armyPower;
}

void Player::setArmyPower(int inputPower){
    armyPower = inputPower;
}

void Player::addToArmyPower(int increment){
    armyPower += increment;
}

int Player::yellowArmySize(){
    return yellowArmy.size();
}

int Player::getRawYellowPower(){
    int sumOfPowers = 0;
    for(int i = 0; i < yellowArmySize(); i++){
        sumOfPowers += yellowArmy[i]->getPower();
    }
    return sumOfPowers;
}

void Player::setMarksColor(Color inputColor){
    for(int i = 0; i < marks.size(); i++){
        marks[i].setColor(inputColor);
    }
}

void Player::setCardsInHand(std::vector <Card*> givenHand){
    cardsInHand = givenHand;
}

std::vector <Card*> Player::getCardsInHand()const{
    return cardsInHand;
}

short Player::numberOfTakenCities(){
    short cityCount = 0;
    for(int i = 0; i < marks.size(); i++){
        if(marks[i].whereIsIt() != NULL)
            cityCount++;
    }
    return cityCount;
}

bool Player::cardExistance(std::string toBeChecked){
    try{
        int soldierPower = stoi(toBeChecked);
        for(int i = 0; i < cardsInHand.size(); i++){
            if(cardsInHand[i]->getPower() == soldierPower && cardsInHand[i]->getType() == soldier){
                return true;
            }
        }
        return false;
    }

    catch(std::invalid_argument invalid){
        for(int i = 0; i < cardsInHand.size(); i++){
            if(cardsInHand[i]->getTypeName() == toBeChecked){
                return true;
            }
        }
        return false;
    }
}

Card* Player::playACard(std::string toBePlayed){
    try{
        int soldierPower = stoi(toBePlayed);
        std::vector <Card*>::iterator pointer = cardsInHand.begin();
        for(int i = 0; i < cardsInHand.size(); i++, pointer++){
            if(cardsInHand[i]->getType() == soldier && cardsInHand[i]->getPower() == soldierPower){
                yellowArmy.push_back(cardsInHand[i]);
                cardsInHand.erase(pointer);
                break;
            }
        }
        return NULL;
    }
    catch(std::invalid_argument invalid){
        std::vector <Card*>::iterator pointer = cardsInHand.begin();
        Card* tempPointer = NULL;
        for(int i = 0; i < cardsInHand.size(); i++, pointer++){
            if(cardsInHand[i]->getTypeName() == toBePlayed && cardsInHand[i]->getType() != soldier){
                tempPointer = cardsInHand[i];
                cardsInHand.erase(pointer);
                break;
            }
        }
        return tempPointer;
    }
}

std::vector <Mark> Player::getMarks()const{
    return marks;
}