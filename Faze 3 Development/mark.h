#ifndef MARK_H

#define MARK_H
#include <string>

#include "city.h"
#include "color.h"

class Mark{
    public:
    //Constructor:
        Mark();
    //Setters:
        void setMarkOn(City*);
        void setColor(Color);
    //Useful function:
        City* whereIsIt()const;
        
    private:
        City* cityAddress;
        Color color;
};

#endif