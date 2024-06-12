#ifndef COLORFORPLAYER_H

#define COLORFORPLAYER_H
#include <string>

#include "color.h"

struct ColorForPlayer{
    std::string colorName;
    Color color;
    bool used = false;
};

#endif