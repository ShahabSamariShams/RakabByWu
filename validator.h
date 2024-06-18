#ifndef VALIDATOR_H

#define VALIDATOR_H
#include <vector>
#include <unordered_map>

#include "player.h"

class Validator{
    public:
        static bool validateNumberOfPlayers(short);
        static bool validatePlayerName(std::vector <Player>, std::string);
        static bool validatePlayerAge(float);
        static bool validatePlayerColor(std::unordered_map <std::string, std::pair <Color, bool>>, std::string);
        static bool validateKnownWord(std::string);
        static bool validateCityName(std::string, Map&);
    private:
};

#endif