#include <vector>
#include <utility>

#ifndef CARD_H
#define CARD_H
#include "card.h"
#endif
#include "player.h"
#include "mark.h"
#include "map.h"

class Game{
    public:
        
    private:
        std::vector <Card*> deckOfCards;
        std::vector <Card*> burntCards;
        std::vector <std::pair<Card*, std::string> > playedPurpleCards;
        std::vector <Player> playerList;
        Mark blackMark;
        Map theMap;
        Card* season;
};