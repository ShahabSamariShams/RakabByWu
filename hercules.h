#ifndef HERCULES_H

#define HERCULES_H
#include "purpleCard.h"

class Hercules: public PurpleCard{
    public:
    //Constructor:
        Hercules();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif