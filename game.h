#include <vector>
#include <utility>

#ifndef CARD_H
#define CARD_H
#include "card.h"
#endif
#ifndef PLAYER_H
#define PLAYER_H
#include "player.h"
#endif
#ifndef MARK_H
#define MARK_H
#include "mark.h"
#endif
#ifndef MAP_H
#define MAP_H
#include "map.h"
#endif

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