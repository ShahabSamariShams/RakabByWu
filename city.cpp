#include "city.h"

void City::setName(std::string inputName){
    name = inputName;
}

std::string City::getName()const{
    return name;
}

void City::setFightability(bool position){
    fightable = position;
}

bool City::getFightability()const{
    return fightable;
}

bool City::isAdjacent(std::string toBeChecked){
    return otherCities[toBeChecked];
}

void City::addCity(std::string toBeAdded, bool position){
    otherCities[toBeAdded] = position;
}