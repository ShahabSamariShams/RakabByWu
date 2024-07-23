#ifndef GAME_H

#define GAME_H
#include <vector>
#include <utility>

#include "card.h"
#include "player.h"
#include "mark.h"
#include "map.h"
#include "midGameData.h"

class Card;
class Player;

class Game{
    public:
    //Constructor and Destructor:
        Game();
    //Setters:
        void setSeason(Card*);
        void setPlayerList(std::vector <Player>);
    //Getters:
        std::vector <Player> getPlayerList()const;
        std::string getSeason()const;
    //Cards related:
        int highestYellowCardPlayed();
        void burnHandIfPossible();
        void burnCards(std::vector <Card*>);
        void distributeCards();
        bool timeToDistribute();
        void addToPlayedPurpleCards(Card*, Player*);
        void resetingArmies(std::vector <Card*>);
        std::vector <Card*> calculateThePowers();
    //Black mark related:
        int findTheYoungest();
        void setTheBlackMark();
    //Piece mark related:
        void setThePeaceMark();
    //Player related:
        Player* playerInTurn()const; //Player in turn for their played purpleCard.
    //War related:
        void war();
        bool endOfWar(std::vector <bool>);
        Player* whoWonTheWar();
        void warWinnerAward(Player*);
    //Helping functions:
        bool oneVicinity(std::vector <City*>);
    //Whole game related:
        bool gameWinner(Player*);
        void runGame();

    private:
        std::vector <Player> playerList;

        std::vector <Card*> deckOfCards;
        std::vector <std::pair<Card*, Player*> > playedPurpleCards;
        Card* season;

        Mark blackMark;
        Mark peaceMark;
        Map theMap;

        MidGameData midGameData;
};

#endif