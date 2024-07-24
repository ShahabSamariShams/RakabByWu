#ifndef YELLOWCARD_H

#define YELLOWCARD_H
#include "card.h"

class YellowCard: public Card{
    public:
    //Constructor:
        YellowCard(unsigned short);
    //Overrided Functions:
        std::string getTypeName()const override;
    private:
};

#endif