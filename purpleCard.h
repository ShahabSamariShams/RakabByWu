#include "card.h"

class PurpleCard: public Card{
    public:
        void setPriority(short);
        short getPriority()const;
    private:
        short priority;    
};