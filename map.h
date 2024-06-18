#ifndef MAP_H

#define MAP_H
#include "city.h"

class Map{
    public:
        Map();
        void addCity(City);
        City* toBeFoughtFor(std::string);
        std::unordered_map <std::string, City> getTheMap();
    private:
        std::unordered_map <std::string, City> theMap;
};

#endif