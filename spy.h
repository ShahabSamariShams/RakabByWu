#ifndef SPY_H

#define SPY_H
#include "purpleCard.h"

class Spy: public PurpleCard{
    public:
    //Constructor:
        Spy();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const;
    private:

};

#endif