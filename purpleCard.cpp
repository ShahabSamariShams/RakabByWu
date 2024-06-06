#ifndef PURPLECARD_H
#define PURPLECARD_H
#include "purpleCard.h"
#endif

void PurpleCard::setPriority(short inputPriority){
    priority = inputPriority;
}

short PurpleCard::getPriority()const{
    return priority;
}