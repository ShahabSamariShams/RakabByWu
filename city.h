#include <string>
#include <vector>

class City{
    public:
        void setName(std::string);
        std::string getName()const;
        void setFightability(bool);
        bool getFightability()const;
        bool isAdjacent(City);
        void addToVicinity(City*);
    private:
        std::string name;
        std::vector <City*> vicinities;
        bool fightable;
};