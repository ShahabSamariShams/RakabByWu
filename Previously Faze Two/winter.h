#ifndef WINTER_H

#define WINTER_H
#include "purpleCard.h"

class Winter: public PurpleCard{
    public:
    //Constructor:
        Winter();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif