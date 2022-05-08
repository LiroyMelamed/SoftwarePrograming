#ifndef CAPTAIN_H
#define CAPTAIN_H
#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"

using coup::CardType;

using namespace std;

namespace coup
{
    class Captain : public Player
    {
    private:
        Player *stolen;
    public:
      /**
         * Constructor.
         *
         * @return None.
         */
        Captain(Game &,const  string&);
        /**
         * @brief blocks the captain's steal.
         *
         * @return None.
         */
        void block(Player &);
        /**
         * @brief steal 2 coins from another player.
         *
         * @return None.
         */
        void steal(Player &);
        /**
         * @brief the stolen player.
         * 
         * @return Player.
         */
        Player *stolen_from();
    };

}
#endif