#ifndef HEROINE_H

#define HEROINE_H
#include "purpleCard.h"

class Heroine: public PurpleCard{
    public:
        Heroine();
        void ability(Game&)override;
        std::string getTypeName()const override;
    private:
};

#endif

