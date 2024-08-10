#ifndef CONDOTTIEREFILEOPERATION_H

#define CONDOTTIEREFILEOPERATION_H
#include <string>

class Game;
class Card;

class CondottiereFileOperation{
    public:
        static void writeTheGame(std::string, Game);
        static void readTheGame(std::string, Game&);
        static Card* cardMaker(int);
        static Card* cardMaker(int, float);
    private:
};

#endif