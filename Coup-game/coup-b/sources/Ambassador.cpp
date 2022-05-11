#include "Ambassador.hpp"

#include <vector>
#include <string>

using namespace std;
using namespace coup;

Ambassador::Ambassador(Game &game, const string &name) : Player(name, 0, CardType::Ambassador, game)
{
    transfer_from = NULL;
    transfer_to = NULL;
}

void Ambassador::block(Player &p)
{
    this->last_act = ActionType::err;

    if (!p.is_playing())
    {
        throw invalid_argument("player already couped");
    }
    if (*this == p)
    {
        throw invalid_argument("self block unavaible");
    }
    if (p.last_action() == ActionType::steal)
    {
        p.set_coins(-2);
        p.stolen_from()->set_coins(2);
        last_act = ActionType::block;
    }
    else
    {
        throw invalid_argument("income cannot be blocked by any role");
    }
}
void Ambassador::transfer(Player &p1, Player &p2)
{
    last_act = ActionType::err;
    player_turn("transfer");
    if (!p1.is_playing() || !p2.is_playing())
    {
        throw invalid_argument("player already couped");
    }
    if (p1 == p2)
    {
        throw invalid_argument("self transfer unavaible");
    }
    if (p1.coins() < 1)
    {
        throw invalid_argument("transfer unaviable - players does not have enough money");
    }
    last_act = ActionType::transfer;
    transfer_from = &p1;
    transfer_to = &p2;
    this->game_name->next_turn();
    p1.set_coins(-1);
    p2.set_coins(1);
}
Player *Ambassador::get_transfered_p(int mode)
{
    if (mode < 0 || mode > 1)
    {
        throw invalid_argument("Err");
    }
    if (mode == 0)
    {
        return transfer_from;
    }

    return transfer_to;
}