#ifndef SPRING_H

#define SPRING_H
#include "purpleCard.h"

class Spring: public PurpleCard{
    public:
        Spring();
        void ability(Game&);
        std::string getTypeName()const override;
    private:
};

#endif