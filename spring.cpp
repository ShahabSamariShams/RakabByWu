#include "spring.h"

Spring::Spring(){
    setPriority(4);
    setPower(0);
}

void ability(Game& currentGame){
    int highestCard = currentGame.highestYellowCardPlayed();
    //for(auto i: )
}