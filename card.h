#ifndef CARD_H

#define CARD_H
#include <string>

#include "game.h"

class Game;

enum CardType{
    soldier,
    scarecrow, //Immediate effect.
    turncoat,  //Immediate effect.
    bishop,    //First.
    winter,    //Second.
    drummer,   //Third.
    spring,    //Fourth.
    spy,       //Fifth.
    heroine    //Fifth.
};

class Card{
    public:
        Card();
        void setType(CardType);
        virtual std::string getTypeName()const = 0;
        CardType getType()const;
        void setPower(unsigned short);
        unsigned short getPower()const;
        virtual void ability(Game&) = 0;
    private:
        CardType type;
        unsigned short power;
};

#endif