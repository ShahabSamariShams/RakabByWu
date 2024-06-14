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
        int yellowArmySize();
        int getRawYellowPower();

        int getArmyPower()const;
        void setArmyPower(int);
        void addToArmyPower(int);

        void setMarksColor(Color);
        short numberOfTakenCities();

        void setCardsInHand(std::vector <Card*>);
        std::vector <Card*> getCardsInHand()const;
        
    private:
        std::string name;
        float age;

        std::vector <Card*> yellowArmy;
        int armyPower;

        std::vector <Card*> cardsInHand;

        std::vector <Mark> marks;
};

#endif