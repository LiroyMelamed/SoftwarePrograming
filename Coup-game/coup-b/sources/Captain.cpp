#include "Captain.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace coup;

Captain::Captain(Game &game, const string &name) : Player(name, 0, CardType::Captain, game)
{
    stolen = NULL;
}

void Captain::block(Player &p)
{
    this->last_act = ActionType::err;
    if (!p.is_playing())
    {
        throw invalid_argument("player already couped");
    }
    if (*this == p)
    {
        throw invalid_argument("self block is unavaible");
    }
    if (p.last_action() == ActionType::steal)
    {
        p.set_coins(-2);
        p.stolen_from()->set_coins(2);
        this->last_act = ActionType::block;
    }
    else
    {
        throw invalid_argument("income cannot be blocked by any role");
    }
}
void Captain::steal(Player &p)
{
    this->last_act = ActionType::err;
    if (!p.is_playing())
    {
        throw invalid_argument("player already couped");
    }
    if (*this == p)
    {
        throw invalid_argument("self stealing unavaivle");
    }
    if (player_turn("steal"))
    {
        if (p.coins() <= 0)
        {
            throw invalid_argument("Cant steal from this player");
        }
        this->last_act = ActionType::steal;
        this->stolen = &p;
        this->game_name->next_turn();
        num_of_coin += (p.coins() < 2) ? p.coins() : 2;
        p.set_coins((p.coins() < 2) ? -p.coins() : -2);
    }
}
Player *Captain::stolen_from()
{
    return stolen;
}
