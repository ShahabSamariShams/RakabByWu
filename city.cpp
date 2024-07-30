#include "city.h"

City::City(){
    setFightability(true);
}

void City::setName(std::string inputName){
    name = inputName;
}

void City::setFightability(bool position){
    fightable = position;
}

void City::setGuards(bool jungle, bool mountain, bool castle){
    this->guards.jungle = jungle;
    this->guards.mountain = mountain;
    this->guards.castle = castle;
}

std::string City::getName()const{
    return name;
}

bool City::getFightability()const{
    return fightable;
}

bool City::haveJungle()const{
    return guards.jungle;
}

bool City::haveMountain()const{
    return guards.mountain;
}

bool City::haveCastle()const{
    return guards.castle;
}

bool City::isAdjacent(std::string toBeChecked){
    try{
        return otherCities.at(toBeChecked);
    }
    catch(const std::out_of_range exception){
        return false;
    }
}

void City::addCity(std::string toBeAdded, bool position){
    try{
        otherCities.at(toBeAdded);
        otherCities[toBeAdded] = position;
    }
    catch(std::out_of_range doesntExist){
        otherCities[toBeAdded] = position;
    }
}

void City::emptyVicinitiess(){
    otherCities.clear();
}

int City::timesToConquer(){
    int sum = 1;
    if(guards.castle)
        sum += 4;
    if(guards.mountain)
        sum += 3;
    if(guards.jungle)
        sum += 2;
    return sum;
}