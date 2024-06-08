#ifndef YELLOWCARD_H

#define YELLOWCARD_H
#include "card.h"

class YellowCard: public Card{
    public:
        YellowCard(unsigned short);
        std::string getTypeName()const override;
    private:
};

#endif