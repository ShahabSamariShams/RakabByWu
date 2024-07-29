#ifndef MOUNTAINBREAKER_H

#define MOUNTAINBREAKER_H
#include "purpleCard.h"

class MountainBreaker: public PurpleCard{
    public:
    //Constructor:
        MountainBreaker();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif