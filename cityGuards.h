#ifndef CITYGUARDS_h

#define CITYGUARDS_h

struct CityGuards{
    bool jungle;
    bool mountain;
    bool castle;

    //Constructor:
    CityGuards(){
        jungle = mountain = castle = false;
    }
};

#endif