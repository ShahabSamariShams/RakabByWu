#ifndef CARD_H
#define CARD_H
#include "card.h"
#endif

class PurpleCard: public Card{
    public:
        void setPriority(short);
        short getPriority()const;
    private:
        short priority;    
};