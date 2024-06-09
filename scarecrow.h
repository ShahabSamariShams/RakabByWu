#ifndef SCARECROW_H

#define SCARECROW_H
#include "purpleCard.h"

class Scarecrow: public PurpleCard{
    public:
        Scarecrow();
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif