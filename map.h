#include "city.h"

class Map{
    public:
        Map();
        void addCity(City);
    private:
        std::unordered_map <std::string, City> theMap;
};

