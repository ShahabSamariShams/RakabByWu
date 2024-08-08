#include "condottiere.h"

#include <filesystem>
#include <fstream>

#include "userinterface.h"
#include "game.h"

Condottiere::Condottiere(){
    std::filesystem::directory_entry fileChecker("GameFiles");
    if(!fileChecker.exists()){
        std::filesystem::create_directory("GameFiles");
        for(int i = 0; i < 5; i++){
            std::ofstream fileInitializer("GameFiles\\Game " + std::to_string(i + 1) + ".txt");
            fileInitializer << "empty";
        }
    }
}

void Condottiere::runGame(){
    while(true){
        std::string fileNumber;
        switch(UserInterface::menu()){
            case 1:
                fileNumber = UserInterface::newGameMenu();
                break;
            case 2:
                fileNumber = UserInterface::loadGameMenu();
                break;
            case 3:
                return;
            default:
                break;
        }
        if(fileNumber != "0"){
            Game theGame;
            theGame.runGame();
        }
    }
}