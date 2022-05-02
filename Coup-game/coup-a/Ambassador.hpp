#ifndef AMBASSADOR_H
#define AMBASSADOR_H
#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using coup::CardType;

using namespace std;

namespace coup
{
    class Ambassador : public Player

    {
    private:
        Player *transfer_from;
        Player *transfer_to;

    public:
        /**
         * Constructor.
         *
         * @return None.
         */
        Ambassador(Game &, const string &);
        /**
         * @brief preventing the theft of Captain.
         *
         * @return None.
         */
        void block(Player &);
        /**
         * @brief transfer of coins between players
         *
         * @return None.
         */
        void transfer(Player &, Player &);
        /**
         * @brief returns the players name that got the coins or transfer the coins
         *
         * @return Player.
         */
        Player *getTransferPlayer(int);
    };

}
#endif