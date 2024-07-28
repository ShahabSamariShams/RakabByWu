#ifndef MIDGAMEDATA_H

#define MIDGAMEDATA_H
#include <vector>

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
    //Vectors that overlap with player list:
        std::vector <int> spyCount;
        std::vector <bool> passed;
    //Functions:
        void reset();
        void resizeList(int);
};

#endif