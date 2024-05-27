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

bool City::isAdjacent(City toBeChecked){
    for(auto i: vicinities){
        if(toBeChecked.getName() == i->getName()){
            return true;
        }
    }
    return false;
}

void City::addToVicinity(City* adjacentCity){
    vicinities.push_back(adjacentCity);
}