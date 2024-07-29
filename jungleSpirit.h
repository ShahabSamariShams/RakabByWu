#ifndef JUNGLESPIRIT_H

#define JUNGLESPIRIT_H
#include "purpleCard.h"

class JungleSpirit: public PurpleCard{
    public:
    //Constructor:
        JungleSpirit();
    //Overrided Functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif