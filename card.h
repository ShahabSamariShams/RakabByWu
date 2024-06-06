#include <string>

#include "game.h"

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
        std::string getTypeName()const;
        CardType getType()const;
        void setPower(unsigned short);
        unsigned short getPower()const;
        virtual void ability(Game);
    private:
        CardType type;
        unsigned short power;
};