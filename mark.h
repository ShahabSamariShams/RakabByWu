#include <string>

#ifndef CITY_H
#define CITY_H
#include "city.h"
#endif

enum Color{
    white,
    black,
    red,
    blue,
    green,
    yellow,
    purple,
    lightBlue
};

class Mark{
    public:
        Mark();
        City whereIsIt()const;
        void setMarkOn(City*);
        void setColor(Color);
    private:
        City* cityAddress;
        Color color;
};