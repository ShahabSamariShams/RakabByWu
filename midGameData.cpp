#include "midGameData.h"

void MidGameData::reset(){
    indexOfPeaceMarkOwner = -1;
    std::fill(passed.begin(), passed.end(), false);
    std::fill(spyCount.begin(), spyCount.end(), 0);
}