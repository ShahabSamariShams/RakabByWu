#ifndef MAP_H

#define MAP_H
#include "city.h"

class Map{
    public:
    //Constructor:
        Map();
    //Getter:
        std::unordered_map <std::string, City> getTheMap();
    //Useful Functions:
        void addCity(City);
        City* toBeFoughtFor(std::string);
        
    private:
        std::unordered_map <std::string, City> theMap;
};

#endif