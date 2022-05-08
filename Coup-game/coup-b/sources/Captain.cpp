#include "Captain.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace coup;

Captain::Captain(Game &game,const string &name) : Player(name, 0, CardType::Captain, game){
    stolen=NULL;
}

void Captain::block(Player &p)
{
    this->last_action = ActionType::err;
    if (*this == p)
    {
        throw invalid_argument("Can not block himself");
    }
    if (!p.is_alive())
    {
        throw invalid_argument("The player was eliminated from the game");
    }
    if (p.last_act() == ActionType::steal)
    {
        p.set_money(-2);
        p.stolen_from()->set_money(2);
        this->last_action = ActionType::block;
        cout << "Hello block from " << *this << " to " << p << endl;
    }
    else
    {
        throw invalid_argument("the last operation " + *p.get_name() + " " + p.get_card_name() + " performed is income, which cannot be blocked by any role");
    }
}
void Captain::steal(Player &p)
{
    this->last_action = ActionType::err;
    if (*this == p)
    {
        throw invalid_argument("Can not steal himself");
    }
    if (!p.is_alive())
    {
        throw invalid_argument("The player was eliminated from the game");
    }
    if (is_turn())
    {
        if (_money < 2)
        {
            throw invalid_argument("Can not steal from ...");
        }
        this->last_action = ActionType::steal;
        this->stolen = &p;
        _money += 2;
        p.set_money(-2);
        cout << "Hello steal from " << *this << " to " << p << endl;
    }
}
Player *Captain::stolen_from()
{
    return stolen;
}
