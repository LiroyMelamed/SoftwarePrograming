#ifndef CONTESSA_H
#define CONTESSA_H
#include <iostream>
#include <vector>
#include <string>

#include "Player.hpp"

#include "Game.hpp"

using coup::CardType;

using namespace std;

namespace coup
{
    class Contessa : public Player
    {
    private:
    public:
        /**
         * Constructor.
         *
         * @return None.
         */
        Contessa(Game &, const string &);
        /**
         * @brief blocks the assassin's coup ..
         *
         * @return None.
         */
        void block(Player &);
    };

}
#endif
