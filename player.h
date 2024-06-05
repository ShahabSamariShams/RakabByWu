#include <vector>
#include <string>

#include "card.h"
#include "mark.h"

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
        std::vector <Card*> playedCards;
        std::vector <Card*> cardsInHand;
        std::vector <Mark> marks;
};