#include <vector>
#include <string>

#ifndef CARD_H
#define CARD_H
#include "card.h"
#endif
#ifndef MARK_H
#define MARK_H
#include "mark.h"
#endif
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
        YellowArmy army;
        std::vector <Card*> cardsInHand;
        std::vector <Mark> marks;
};