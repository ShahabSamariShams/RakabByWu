#ifndef DRUMMER_H

#define DRUMMER_H
#include "purpleCard.h"

class Drummer: public PurpleCard{
    public:
        Drummer();
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif