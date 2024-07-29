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

std::string City::getName()const{
    return name;
}

bool City::getFightability()const{
    return fightable;
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
    if(castle)
        sum += 4;
    if(mountain)
        sum += 3;
    if(jungle)
        sum += 2;
    return sum;
}