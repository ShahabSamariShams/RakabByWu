#ifndef CITY_H

#define CITY_H
#include <string>
#include <unordered_map>

#include "cityGuards.h"

class City{
    public:
    //Constructor:
        City();
    //Setters:
        void setName(std::string);
        void setFightability(bool);
        void setGuards(bool, bool, bool);
    //Getters:
        std::string getName()const;
        bool getFightability()const;
    //Guard related:
        bool haveJungle()const;
        bool haveMountain()const;
        bool haveCastle()const;
    //Useful functions:
        bool isAdjacent(std::string);
        void addCity(std::string, bool);
        void emptyVicinitiess();
        int timesToConquer();
        
    private:
        std::string name;
        std::unordered_map <std::string, bool> otherCities;
        bool fightable;

        CityGuards guards;
};

#endif