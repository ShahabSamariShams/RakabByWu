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

int Player::getYellowPower(){
    int sumOfPowers = 0;
    for(int i = 0; i < yellowArmySize(); i++){
        sumOfPowers += yellowArmy[i]->getPower();
    }
    return sumOfPowers;
}