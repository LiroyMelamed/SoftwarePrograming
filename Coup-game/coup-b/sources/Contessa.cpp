#include "Contessa.hpp"

#include <vector>
#include <string>

using namespace std;
using namespace coup;

Contessa::Contessa(Game &game, const string &name) : Player(name, 0, CardType::Contessa, game) {}

void Contessa::block(Player &p)
{
    last_act = ActionType::err;

    if (!p.is_playing())
    {
        throw invalid_argument("player already couped");
    }
    if (*this == p)
    {
        throw invalid_argument("self block unavaible");
    }
    if (p.last_action() == ActionType::coup)
    {
        if (p.get_card_name() == "Assassin" && p.coupcost() == MAXTOCOUP)
        {
            throw invalid_argument("blocked");
        }
        p.got_attacked()->set_playing(true);
        this->game_name->set_active_player(1);
        last_act = ActionType::block;
    }
    else
    {
        throw invalid_argument("foreign aid cannot be blocked by " + *this->get_name() + " " + this->get_card_name());
    }
}
