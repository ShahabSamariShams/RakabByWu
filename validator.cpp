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