#ifndef DUKE_H
#define DUKE_H

#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
using coup::CardType;

namespace coup
{
    class Duke : public Player
    {
    private:

    public:
        /**
         * Constructor.
         *
         * @return None.
         */
        Duke(Game& , const string& );   
        /**
         * @brief blocking the double pay.
         *
         * @return None.
         */
        void block(Player &); 
        /**
         * @brief duke takes a tax of 3 coins from the .
         *
         * @return None.
         */
        void tax(); 
    };

}
#endif