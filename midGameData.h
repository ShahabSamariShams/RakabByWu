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
    //Fortune Numbers:
        int luckyNumber;
        int ominousNumber;
    //Pointers:
        Player* winner;
    //Booleans:
        bool isTurncoatPlayed;
        bool isPegasusPlayed;
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