#ifndef CARD_H

#define CARD_H
#include <string>

enum CardType{
    soldier = 0,
    scarecrow = 1,          //Immediate effect.
    turncoat = 2,           //Immediate effect.
    jungleSpirit = 3,       //Immediate effect.
    mountainBreaker = 4,    //Immediate effect.
    hercules = 5,           //Immediate effect.
    pegasus = 6,            //Immidiate effect.
    harpseal = 7,           //Immediate effect.
    bishop = 8,             //First.
    winter = 9,             //Second.
    drummer = 10,            //Third.
    spring = 11,             //Fourth.
    spy = 12,                //Fifth.
    heroine  = 13            //Fifth.
};

class Card{
    public:
    //Constructor:
        Card();
    //Setters:
        void setType(CardType);
        void setPower(float);
    //Getters:
        CardType getType()const;
        float getPower()const;
    //Functions to be overrided:
        virtual std::string getTypeName()const = 0;
        
    private:
        CardType type;
        float power;
};

#endif