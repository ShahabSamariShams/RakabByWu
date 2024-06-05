#include <vector>

#include "card.h"
#include "player.h"
#include "mark.h"
#include "map.h"

class Game{
    public:
        
    private:
        std::vector <Card*> cards;
        std::vector <Card*> burntCards;
        std::vector <Player> playerList;
        Mark blackMark;
        Map theMap;
};