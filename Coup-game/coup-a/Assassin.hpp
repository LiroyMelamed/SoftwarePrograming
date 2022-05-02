#ifndef ASSASSIN_H
#define ASSASSIN_H
#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;
namespace coup
{
    class Assassin : public Player

    {private:
        Player *attacked;
    public:
      /**
         * Constructor.
         *
         * @return None.
         */
        Assassin(Game &, const string&);
         /**
         * @brief coup another player
         *
         * @return None.
         */
        void coup(Player&);
         /**
         * @brief the player that coup
         *
         * @return Player.
         */
        Player *getAttacked();
    };

}
#endif