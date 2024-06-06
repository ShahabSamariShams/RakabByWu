#ifndef CITY_H
#define CITY_H
#include "city.h"
#endif

class Map{
    public:
        Map();
        void addCity(City);
    private:
        std::unordered_map <std::string, City> theMap;
};

