#ifndef USERINTERFACE_H

#define USERINTERFACE_H
#include <vector>
#include <unordered_map>
#include <utility>

#include "player.h"
#include "mark.h"
#include "color.h"
#include "map.h"

class UserInterface{
    public:
    //Receivers:
        static short receiveNumberOfPlayers();
        static std::string receivePlayerName(int);
        static float receivePlayerAge(int);
        static std::string receivePlayerColor(int, std::unordered_map<std::string, std::pair<Color, bool> >);
        static std::vector <Player> receivePlayerList(int);
        static std::string receicveAnswer(std::string);
        static int scarecrowEntry(std::vector <Card*>);
        static std::string play(Player);
        static std::string callTheBlackMarkOwner(Player, Map&);
        static std::string callThePeaceMarkOwner(Player, Map&);
        static int receiveTheLuckyNumber(std::string);
        static int receiveTheOminousNumber(std::string, int);

    //Errors:
        static void numberOfPlayersError(short);
        static void nameError();
        static void ageError();
        static void colorError();
        static void scarecrowError();
        static void answerError();
        static void cityNameError();
        static void luckyNumberError();
        static void ominousNumberError();
        
    //Displayers:
        static void displayPlayerAvailableCards(Player&);
        static void displayPlayerPlayedCards (Player&, std::vector <std::pair <Card*, Player*> >&);
        static void displayPlayersCities(std::vector <Player>);
        static void drawLine();
        static void displayPlayersAndTheirPlayed(std::vector <Player>, std::vector <std::pair <Card*, Player*> >&);
        static void displaySeason(Card*);
        static void bringThePlayer(std::string);
        static void instructions(std::string);
        static void announceTheLocalWarWinner(Player*);
        static void announceTheWinner(Player*);
        static void displayBlackMarkCity(City*);

    private:
};

#endif