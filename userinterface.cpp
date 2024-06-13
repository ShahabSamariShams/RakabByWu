#include <iostream>

#include "userinterface.h"
#include "validator.h"

short UserInterface::receiveNumberOfPlayers(){
    short numberOfPlayers;
    while(true){
        std::cout << "How many players are going to play this wonderful game?(Note that the number of players must be between 3 and 6.) ";
        std::cin >> numberOfPlayers;
        if(Validator::validateNumberOfPlayers(numberOfPlayers)){
            system("cls");
            break;
        }
        else{
            numberOfPlayersError(numberOfPlayers);
        }
    }
    return numberOfPlayers;
}

void UserInterface::numberOfPlayersError(short numberOfPlayers){
    if(numberOfPlayers < 3){
        std::cout << "Go find some more friends and stop being a loner.";
    }
    else if(numberOfPlayers > 6){
        std::cout << "Your friends are just too much and the programmer of this game isn't going to allow it sience he is a poor loner.";
    }
    system("pause");
    system("cls");
}

std::string UserInterface::receivePlayerName(int index){
    system("cls");
    std::string playerName;
    std::cout << "What is the name of the player number " << index << "? ";
    std::cin >> playerName;
    return playerName;
}

void UserInterface::nameError(){
    std::cout << "The name already exists.\n";
    system("pause");
    system("cls");
}

float UserInterface::receivePlayerAge(int index){
    system("cls");
    float playerAge;
    std::cout << "How old is the player number " << index << "?(10 and above.) ";
    std::cin >> playerAge;
    return playerAge;
}

void UserInterface::ageError(){
    std::cout << "Dude! How are ypu playing this while you are under 10?";
    system("pause");
    system("cls");
}

std::string UserInterface::receivePlayerColor(int index, std::unordered_map<std::string, std::pair <Color, bool>> colorList){
    std::string playerColor;
    system("cls");
    for(auto i: colorList){
        if(!i.second.second){
            std::cout << i.first << "\t\t";
        }
    }
    std::cout <<"\n";
    std::cout << "Player number " << index << ", choose a color from the list above: ";
    std::cin >> playerColor;
    return playerColor;
}

void UserInterface::colorError(){
    std::cout << "You have chosen a color that is not available in the list. try again." ;
    system("pause");
    system("cls");
}

std::vector <Player> UserInterface::receivePlayerList(int numberOfPlayers){
    std::vector <Player> playerList;
    Player playerToBeAdded;
    std::string nameToBeAdded;
    std::string colorToBeAdded;
    float ageToBeAdded;

    for(int i = 0; i < numberOfPlayers; i++){
        while(true){
            nameToBeAdded = receivePlayerName(i + 1);
            if(Validator::validatePlayerName(playerList, nameToBeAdded)){
                playerToBeAdded.setName(nameToBeAdded);
                break;
            }
            else{
                nameError();
            }
        }
        
        while(true){
            ageToBeAdded = receivePlayerAge(i + 1);
            if(Validator::validatePlayerAge(ageToBeAdded)){
                playerToBeAdded.setAge(ageToBeAdded);
                break;
            }
            else{
                ageError();
            }
        }
        
        std::unordered_map <std::string, std::pair <Color, bool>> colorList;
        colorList["red"].first = red, colorList["red"].second = false;
        colorList["blue"].first = blue, colorList["blue"].second = false;
        colorList["green"].first = green, colorList["green"].second = false;
        colorList["light blue"].first = lightBlue, colorList["light blue"].second = false;
        colorList["yellow"].first = yellow, colorList["yellow"].second = false;
        colorList["purple"].first = purple, colorList["purple"].second = false;

        while(true){
            colorToBeAdded = receivePlayerColor(i + 1, colorList);
            if(Validator::validatePlayerColor(colorList, colorToBeAdded)){
                playerToBeAdded.setMarksColor(colorList[colorToBeAdded].first);
                break;
            }
            else{
                colorError();
            }
        }

        playerList.push_back(playerToBeAdded);
    }

    return playerList;
}