#include "condottiere.h"

#include <filesystem>
#include <fstream>

#include "userinterface.h"
#include "game.h"
#include "fileloader.h"

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
        FileLoader fileLoader;
        switch(UserInterface::menu()){
            case 1:
                fileNumber = UserInterface::newGameMenu();
                fileLoader = NewGame;
                break;
            case 2:
                fileNumber = UserInterface::loadGameMenu();
                fileLoader = LoadGame;
                break;
            case 3:
                return;
            default:
                break;
        }
        if(fileNumber != "0"){
            std::string filePath = "GameFiles\\Game " + fileNumber + ".txt";
            Game theGame(filePath, fileLoader);
            theGame.runGame();
        }
    }
}