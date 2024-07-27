#ifndef TURNCOAT_H

#define TURNCOAT_H
#include "purpleCard.h"

class Turncoat: public PurpleCard{
    public:
    //Constructor:
        Turncoat();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif