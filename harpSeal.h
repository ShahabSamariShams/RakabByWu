#ifndef HARPSEAL_H

#define HARPSEAL_H
#include "purpleCard.h"

class HarpSeal: public PurpleCard{
    public:
    //Constructor:
        HarpSeal();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif