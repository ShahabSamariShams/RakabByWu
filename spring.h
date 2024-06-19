#ifndef SPRING_H

#define SPRING_H
#include "purpleCard.h"

class Spring: public PurpleCard{
    public:
    //Constructor:
        Spring();
    //Overrided functions:
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif