#include "Duke.hpp"

#include <vector>
#include <string>

using namespace std;
using namespace coup;

Duke::Duke(Game &game, const string &name) : Player(name, 0, CardType::Duke, game) {}

void Duke::block(Player &p)
{
    this->last_act = ActionType::err;

    if (!p.is_playing())
    {
        throw invalid_argument("player already couped");
    }
    if (*this == p)
    {
        throw invalid_argument("self block unaviable");
    }
    if (p.last_action() == ActionType::foreign_aid)
    {
        p.set_coins(-2);
        last_act = ActionType::block;
    }
    else
    {
        throw invalid_argument("income cannot be blocked by any role");
    }
}
void Duke::tax()
{
    last_act = ActionType::err;
    player_turn("tax");
    set_coins(3);
    last_act = ActionType::tax;
    this->game_name->next_turn();
}
