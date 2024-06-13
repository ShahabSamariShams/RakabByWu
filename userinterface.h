#ifndef USERINTERFACE_H

#define USERINTERFACE_H
#include <vector>
#include <unordered_map>
#include <utility>

#include "player.h"
#include "mark.h"
#include "color.h"

class UserInterface{
    public:
        short receiveNumberOfPlayers();
        void numberOfPlayersError(short);
        std::string receivePlayerName(int);
        void nameError();
        float receivePlayerAge(int);
        void ageError();
        std::string receivePlayerColor(int, std::unordered_map<std::string, std::pair<Color, bool> >);
        void colorError();
        std::vector <Player> receivePlayerList(int);
    private:
};

#endif