#ifndef PLAYER_H

#define PLAYER_H
#include <vector>
#include <string>

#include "card.h"
#include "mark.h"

class Card;

class Player{
    public:
        Player();
        void setName(std::string);
        std::string getName()const;
        void setAge(float);
        float getAge()const;
        int highestYellowCard();
        std::vector <Card*> getYellowArmy()const;
        void setYellowArmy(std::vector <Card*>);
    private:
        std::string name;
        float age;
        std::vector <Card*> yellowArmy;
        int power;
        std::vector <Card*> cardsInHand;
        std::vector <Mark> marks;
};

#endif