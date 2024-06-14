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
        static short receiveNumberOfPlayers();
        static void numberOfPlayersError(short);
        static std::string receivePlayerName(int);
        static void nameError();
        static float receivePlayerAge(int);
        static void ageError();
        static std::string receivePlayerColor(int, std::unordered_map<std::string, std::pair<Color, bool> >);
        static void colorError();
        static std::vector <Player> receivePlayerList(int);
        static void displayPlayerAvailableCards(Player&);
        static void displayPlayerPlayedCards (Player&, std::vector <std::pair <Card*, Player*> >&);
    private:
};

#endif