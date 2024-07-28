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
        void setIndexOfPeaceMarkOwner(int);
        void setFortuneNumbers();
    //Getters:
        std::vector <Player> getPlayerList()const;
        std::string getSeason()const;
        int playerInTurnIndex(std::string)const;
        std::vector <Card*> getPlayedPurpleCards();
    //Cards related:
        int highestYellowCardPlayed();
        void burnHandIfPossible();
        void burnCards(std::vector <Card*>);
        void distributeCards();
        bool timeToDistribute();
        void addToPlayedPurpleCards(Card*, Player*);
        void resetingArmies(std::vector <Card*>);
        void prepareForCalculation();
        std::vector <Card*> calculateThePowers();
        void turncoatPlayed();
        void pegasusPlayed();
    //Black mark related:
        int findTheYoungest();
        void ownerOfBlackMark();
        void setTheBlackMark();
        void spyCountIncrementation(int);
    //Peace mark related:
        void setThePeaceMark();
    //Player related:
        Player* playerInTurn()const; //Player in turn for their played purpleCard.
    //War related:
        void war();
        bool endOfWar();
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