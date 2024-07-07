#ifndef BISHOP_H

#define BISHOP_H
#include "purpleCard.h"

class Bishop: public PurpleCard{
    public:
    //Constructor:
        Bishop();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif