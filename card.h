#ifndef CARD_H

#define CARD_H
#include <string>

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