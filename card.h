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
    //Constructor:
        Card();
    //Setters:
        void setType(CardType);
        void setPower(unsigned short);
        void setPriority(short);
    //Getters:
        CardType getType()const;
        unsigned short getPower()const;
        short getPriority()const;
    //Functions to be overrided:
        virtual void ability(Game&) = 0;
        virtual std::string getTypeName()const = 0;
        
    private:
        CardType type;
        unsigned short power;
        short priority;
};

#endif