#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "card.h"
#include "mark.h"
#include "yellowArmy.h"

class Player{
    public:
        Player();
        void setName(std::string);
        std::string getName()const;
        void setAge(float);
        float getAge()const;
    private:
        std::string name;
        float age;
        //YellowArmy army;
        std::vector <Card*> cardsInHand;
        std::vector <Mark> marks;
};

#endif