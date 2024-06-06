#ifndef MARK_H

#define MARK_H
#include <string>

#include "city.h"

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

#endif