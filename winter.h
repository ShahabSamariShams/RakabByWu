#ifndef WINTER_H

#define WINTER_H
#include "purpleCard.h"

class Winter: public PurpleCard{
    public:
        Winter();
        void ability(Game&);
        std::string getTypeName()const override;
    private:
};

#endif