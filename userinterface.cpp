#include <iostream>

#include "userinterface.h"
#include "validator.h"

class InvalidInputType{};

short UserInterface::receiveNumberOfPlayers(){
    short numberOfPlayers;
    while(true){
        std::cout << "How many players are going to play this wonderful game?(Note that the number of players must be between 3 and 6.) \n";
        std::cout << "Enter the number: ";
        try{
            if(!(std::cin >> numberOfPlayers)){
                throw InvalidInputType();
            }
            if(Validator::validateNumberOfPlayers(numberOfPlayers)){
                system("cls");
                break;
            }
            else{
                numberOfPlayersError(numberOfPlayers);
            }
        }
        catch(InvalidInputType&){
            system("cls");
            std::cout << "Your entry is not only inavliad, but also of a whole other type.\n";
            system("pause");
            system("cls");
            std::cin.clear();
            std::cin.ignore();
        }
            
    }
    return numberOfPlayers;
}

void UserInterface::numberOfPlayersError(short numberOfPlayers){
    if(numberOfPlayers < 3){
        system("cls");
        std::cout << "Go find some more friends and stop being a loner.\n";
    }
    else if(numberOfPlayers > 6){
        std::cout << "Your friends are just too much and the programmer of this game isn't going to allow it sience he is a poor loner.\n";
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

void UserInterface::displayPlayerAvailableCards(Player& playerInTurn){
    std::cout << "Available cards of " << playerInTurn.getName() << ": ";
    std::vector <Card*> playerTempCardList = playerInTurn.getCardsInHand();
    for(int i = 0; i < playerTempCardList.size(); i++){
        if(playerTempCardList[i]->getType() == soldier){
            std::cout << playerTempCardList[i]->getPower() << "\t";
        }
        else{
            std::cout << playerTempCardList[i]->getTypeName() << "\t";
        }
    }
    std::cout << "\n";
}

void UserInterface::displayPlayerPlayedCards(Player& playerInTurn, std::vector <std::pair <Card*, Player*> >& playedPurpleCards){
    std::cout << playerInTurn.getName() << ": ";
    for(int i = 0; i < playedPurpleCards.size(); i++){
        if(playedPurpleCards[i].second->getName() == playerInTurn.getName()){
            std::cout << playedPurpleCards[i].first->getTypeName() << "\t";
        }
    }

    std::vector <Card*> tempYellowArmy = playerInTurn.getYellowArmy();
    for(int i = 0; i < tempYellowArmy.size(); i++){
        std::cout << tempYellowArmy[i]->getPower() << "\t";
    }

    std::cout << "\n"; 
}

std::string UserInterface::play(Player playerInTurn){
    displayPlayerAvailableCards(playerInTurn);
    std::cout << "@" << playerInTurn.getName() << ": ";
    std::string input;
    std::cin >> input;
    if(Validator::validateKnownWord(input)){
        if(input == "help"){
            std::string nextWord, mainWord;
            std::getline(std::cin, nextWord);
            for(int i = 0; i < nextWord.size(); i++){
                if(nextWord[i] != ' '){
                    mainWord = mainWord + nextWord[i];
                }
            }
            instructions(mainWord);
            return input;
        }
        else{
            return input;
        }
    }
    else{
        
    }
}

void UserInterface::instructions(std::string input){
    if(input == "\0"){
        std::cout << "This game is....";
        system("pause");
    }
    else if(input == "spring"){
        std::cout << "This card does...";
        system("pause");
    }
    else if(input == "winter"){
        std::cout << "This card does...";
        system("pause");
    }
    else if(input == "heroine"){
        std::cout << "This card does...";
        system("pause");
    }
    else if(input == "drummer"){
        std::cout << "This card does...";
        system("pause");
    }
    else if(input == "scarecrow"){
        std::cout << "This card does...";
        system("pause");
    }
    else if(input == "pass"){
        std::cout << "This card does...";
        system("pause");
    }
}

void UserInterface::displayPlayersAndTheirPlayed(std::vector <Player> playerList, std::vector <std::pair <Card*, Player*> >& playedPurpleCards){
    for(int i = 0; i < playerList.size(); i++){
        displayPlayerPlayedCards(playerList[i], playedPurpleCards);
    }
    drawLine();
}

void UserInterface::displayPlayersCities(std::vector <Player> playerList){
    std::vector <Mark> tempMarkList;
    for(int i = 0; i < playerList.size(); i++){
        tempMarkList = playerList[i].getMarks();
        std::cout << playerList[i].getName() << ": "; 
        for(int i = 0; i < tempMarkList.size(); i++){
            std::cout << tempMarkList[i].whereIsIt()->getName() << "\t";
        }
        std::cout << "\n";
    }
    drawLine();
}

void UserInterface::bringThePlayer(std::string playerInTurn){
    system("cls");
    std::cout << "It's " << playerInTurn << "'s turn. Give him the system.\n";
    system("pause");
}

void UserInterface::drawLine(){
    std::cout << "---------------------------------------\n"; 
}