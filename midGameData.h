#ifndef MIDGAMEDATA_H

#define MIDGAMEDATA_H
#include <vector>
#include <string>

#include "player.h"

struct MidGameData{
    //Indices:
        int indexOfWarStarter;
        int indexOfPeaceMarkOwner;
        int indexOfPlayerInTurn;
    //Pointers:
        Player* winner;
    //Booleans:
        bool isTurncoatPlayed;
    //Game-Status:
        std::string currentStatus;
        std::string finalStatus;
    //Vectors that overlap with player list:
        std::vector <int> spyCount;
        std::vector <bool> passed;
    //Functions:
        void reset();
        void resizeList(int);
};

#endif