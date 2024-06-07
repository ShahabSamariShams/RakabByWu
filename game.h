#ifndef GAME_H

#define GAME_H
#include <vector>
#include <utility>

#include "card.h"
#include "player.h"
#include "mark.h"
#include "map.h"

class Card;
class Player;

class Game{
    public:
        int highestYellowCardPlayed();
    private:
        std::vector <Card*> deckOfCards;
        std::vector <Card*> burntCards;
        std::vector <std::pair<Card*, std::string> > playedPurpleCards;
        std::vector <Player> playerList;
        Mark blackMark;
        Map theMap;
        Card* season;
};

#endif