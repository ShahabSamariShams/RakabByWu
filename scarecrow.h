#ifndef SCARECROW_H

#define SCARECROW_H
#include "purpleCard.h"

class Scarecrow: public PurpleCard{
    public:
    //Constructor:
        Scarecrow();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
        
    private:
};

#endif