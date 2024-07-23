#include "midGameData.h"

void MidGameData::reset(){
    indexOfPeaceMarkOwner = -1;
    winner = NULL;
    std::fill(passed.begin(), passed.end(), false);
    std::fill(spyCount.begin(), spyCount.end(), 0);
}

void MidGameData::resizeList(int size){
    passed.resize(size);
    spyCount.resize(size);
    MidGameData::reset();
}