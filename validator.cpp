#include "validator.h"

bool Validator::validateNumberOfPlayers(short inputNumber){
    if(inputNumber >= 3 && inputNumber <= 6){
        return true;
    }
    else{
        return false;
    }
}

bool Validator::validatePlayerName(std::vector <Player> playerList, std::string nameToBeAdded){
    for(int i = 0; i < playerList.size(); i++){
        if(nameToBeAdded == playerList[i].getName()){
            return false;
        }
    }
    return true;
}

bool Validator::validatePlayerAge(float inputAge){
    if(inputAge >= 10){
        return true;
    }
    return false;
}

bool Validator::validatePlayerColor(std::unordered_map <std::string, std::pair <Color, bool>> colorList, std::string colorToBeAdded){
    try{
        colorList.at(colorToBeAdded);
    }
    catch(std::out_of_range exception){
        return false;
    }
    if(colorList[colorToBeAdded].second){
        return false;
    }
    return true;
}

bool Validator::validateKnownWord(std::string input){
    try{
        int soldierPower = std::stoi(input);
        if(soldierPower == 1 || soldierPower == 2 || soldierPower == 3 || soldierPower == 4 || soldierPower == 5 || soldierPower == 6 || soldierPower == 10){
            return true;
        }
        else{
            return false;
        }
    }
    catch(std::invalid_argument invalid){
        std::string validWords[] = {"spring", "winter", "drummer", "heroine", "scarecrow", "help", "pass"};
        for(int i = 0; i < 7; i++){
            if(input == validWords[i]){
                return true;
            }
        }
        return false;
    }
    
}

bool Validator::validateCityName(std::string cityName, Map& theMap){
    if(theMap.toBeFoughtFor(cityName) == NULL){
        return false;
    }
    return true;
}

bool Validator::validateResurrection(std::string toBeResurrected, std::vector <Card*> playedCards){
    try{
        int tempResurrected = std::stoi(toBeResurrected);
        for(int i = 0; i < playedCards.size(); i++){
            if(tempResurrected == playedCards[i]->getPower()){
                return true;
            }
        }
        return false;
    }
    catch(std::invalid_argument& invalid){
        return false;
    }
}