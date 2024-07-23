#ifndef MIDGAMEDATA_H

#define MIDGAMEDATA_H
#include <vector>

struct MidGameData{
    //Indices:
        int indexOfWarStarter;
        int indexOfPeaceMarkOwner;
        int indexOfPlayerInTurn;
    //Vectors that overlap with player list:
        std::vector <int> spyCount;
        std::vector <bool> passed;
    //Functions:
        void reset();
        void resizeList(int);
};

#endif