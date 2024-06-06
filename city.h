#ifndef CITY_H
#define CITY_H

#include <string>
#include <unordered_map>

class City{
    public:
        City();
        void setName(std::string);
        std::string getName()const;
        void setFightability(bool);
        bool getFightability()const;
        bool isAdjacent(std::string);
        void addCity(std::string, bool);
    private:
        std::string name;
        std::unordered_map <std::string, bool> otherCities;
        bool fightable;
};

#endif