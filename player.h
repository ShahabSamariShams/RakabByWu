#ifndef PLAYER_H

#define PLAYER_H
#include <vector>
#include <string>

#include "card.h"
#include "mark.h"

class Card;

class Player{
    public:
    //Constructor:
        Player();
    //Setters: set
        void setName(std::string);
        void setAge(float);
        void setYellowArmy(std::vector <Card*>);
        void setArmyPower(int);
        void setCardsInHand(std::vector <Card*>);
        void setMarksColor(Color);
        void setMarks(std::vector <Mark>);
    //Getters:
        std::string getName()const;
        float getAge()const;
        std::vector <Card*> getYellowArmy()const;
        int getRawYellowPower();
        int getArmyPower()const;
        std::vector <Mark> getMarks()const;
        std::vector <Card*> getCardsInHand()const;
        int yellowArmySize();
    //Other useful functions:
        int highestYellowCard();
        std::vector <Card*> burnYellowArmy();
        short numberOfTakenCities();
        void addToArmyPower(int);
        std::vector <Card*> burnCardsInHand();
        bool emptyHand();
        
        bool cardExistance(std::string);
        Card* playACard(std::string);

    private:
        std::string name;
        float age;

        std::vector <Card*> cardsInHand;
        std::vector <Card*> yellowArmy;
        int armyPower;

        std::vector <Mark> marks;
        
};

#endif