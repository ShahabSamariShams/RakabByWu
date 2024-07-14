#ifndef PURPLECARD_H

#define PURPLECARD_H
#include "card.h"
#include "game.h"

class Game;

class PurpleCard: public Card{
    public:
    //Setters:
        void setPriority(short);
    //Getters:
        short getPriority()const;
    //To-Be-Overrided:
        virtual void ability(Game&) = 0;
    private:   
        short priority;
};

#endif