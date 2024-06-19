#ifndef CITY_H

#define CITY_H
#include <string>
#include <unordered_map>

class City{
    public:
    //Constructor:
        City();
    //Setters:
        void setName(std::string);
        void setFightability(bool);
    //Getters:
        std::string getName()const;
        bool getFightability()const;
    //Useful functions:
        bool isAdjacent(std::string);
        void addCity(std::string, bool);
        void emptyVicinitiess();
        
    private:
        std::string name;
        std::unordered_map <std::string, bool> otherCities;
        bool fightable;
};

#endif