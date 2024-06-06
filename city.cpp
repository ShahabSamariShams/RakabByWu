#include "city.h"

City::City(){
    setFightability(true);
}

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