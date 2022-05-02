#include "Duke.hpp"
#include <vector>
#include <string>
using namespace std;
using namespace coup;

Duke::Duke(Game &game, const string &name) : Player(name, 0, CardType::Duke, game){}

void Duke::block(Player &p)
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
    if (p.last_act() == ActionType::foreign_aid)
    {
        p.set_money(-2);
        last_action = ActionType::block;
        cout << "blocked from " << *this << " to " << p << endl;
    }
    else
    {
        throw invalid_argument("the last operation " + *p.get_name() + " " + p.get_card_name() + " performed is income, which cannot be blocked by any role");
    }
}
void Duke::tax()
{
    last_action = ActionType::err;
    is_turn();
    set_money(3);
    last_action = ActionType::tax;
    cout << "taxed from " << *this << endl;
}
