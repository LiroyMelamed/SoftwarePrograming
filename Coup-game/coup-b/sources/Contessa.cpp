#include "Contessa.hpp"
#include <vector>
#include <string>
using namespace std;
using namespace coup;

Contessa::Contessa(Game &game,const string &name) : Player(name, 0, CardType::Contessa, game){}

void Contessa::block(Player &p)
{
    last_action = ActionType::err;
    if (*this == p)
    {
        throw invalid_argument("Can not block himself");
    }
    if (!p.is_alive())
    {
        throw invalid_argument("The player was eliminated from the game");
    }
    if (p.last_act() == ActionType::coup)
    {
        p.getAttacked()->set_alive(true);
        last_action = ActionType::block;
        cout << "Hello block from " << *this << " to " << p << endl;
    }
    else
    {
        throw invalid_argument("the last operation " + *p.get_name() + " " + p.get_card_name() + " performed is foreign aid, which cannot be blocked by " + *this->get_name() + " " + this->get_card_name());
    }
}
