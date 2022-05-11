#include "Assassin.hpp"

#include <vector>
#include <string>

using namespace std;
using namespace coup;

Assassin::Assassin(Game &game, const string &name) : Player(name, 0, CardType::Assassin, game), attacked(NULL) {}

void Assassin::coup(Player &p)
{
        this->last_act = ActionType::err;
        player_turn("coup");
        if (!p.is_playing())
        {
                throw invalid_argument("The player was eliminated from the game");
        }
        if (*this == p)
        {
                throw invalid_argument("self coup unavaible");
        }
        if (num_of_coin >= 3)
        {
                num_of_coin = num_of_coin - 3;
                p.set_playing(false);
                this->game_name->next_turn();
                this->game_name->set_active_player(-1);
                last_act = ActionType::coup;
                attacked = &p;
                return;
        }
        throw invalid_argument("coup unavaible - player does not have enough coins");
}
Player *Assassin::got_attacked()
{
        return attacked;
}
