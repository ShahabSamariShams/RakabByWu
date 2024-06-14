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
        Game();
        int highestYellowCardPlayed();
        std::vector <Player> getPlayerList()const;
        void setPlayerList(std::vector <Player>);
        std::string getSeason()const;
        Player* playerInTurn()const; //Player in turn for their played purpleCard.
        void distributeCards();
        void addToPlayedPuroleCards(Card*, Player*);
    private:
        std::vector <Card*> deckOfCards;
        std::vector <Card*> burntCards;
        std::vector <std::pair<Card*, Player*> > playedPurpleCards;
        std::vector <Player> playerList;
        Mark blackMark;
        Map theMap;
        Card* season;

};

#endif