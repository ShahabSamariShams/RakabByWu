#ifndef MARK_H

#define MARK_H
#include <string>

#include "city.h"
#include "color.h"

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