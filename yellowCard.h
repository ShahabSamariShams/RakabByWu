#ifndef YELLOWCARD_H

#define YELLOWCARD_H
#include "card.h"

class YellowCard: public Card{
    public:
    //Constructor:
        YellowCard(unsigned short);
    //Overrided Functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif