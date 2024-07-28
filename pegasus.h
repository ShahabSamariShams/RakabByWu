#ifndef PEGASUS_H

#define PEGASUS_H
#include "purpleCard.h"

class Pegasus: public PurpleCard{
    public:
    //Constructor:
        Pegasus();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif