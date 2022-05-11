
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Card.hpp"
#include "Game.hpp"

#define MAXTOCOUP 7

using namespace std;

namespace coup
{
    class Game;
    class Player
    {
    protected:
        string name;
        int num_of_coin;
        CardType title;
        Game *game_name;
        ActionType last_act;
        bool playing;
        unsigned int turn_num;
        string card_name;
        int coup_cost;

    public:
        /**
         * Constructor.
         */
        Player(const string &, int, CardType, Game &);

        /**
         * @brief  take one coins.
         * @return None.
         */
        void income();

        /**
         * @brief  Double pay take two coins from the pile.
         * @return None.
         */
        void foreign_aid();

        /**
         *
         * @return returns the role of the player.
         */
        string role();

        /**
         *@brief  coins of the player
         *
         * @return returns The amount of coins of the player.
         */
        int coins() const;

        /**
         *@brief  is it the player's turn
         *
         * @return True or False
         */
        bool player_turn(string const &);

        /**
         *@brief  checking if player is still in the game
         *
         * @return True or False.
         */
        bool is_playing() const;

        /**
         * @brief player's turn number
         *
         * @return The turn number.
         */
        unsigned int get_turn_num() const;


        /**
         * @brief operator << overloading.
         */
        friend std::ostream &operator<<(std::ostream &out, const Player &p1);

        /**
         * @brief operator == overloading.
         */
        bool operator==(const Player &p) const;

        /**
         * @brief last action of the player
         *
         * @return The last action of the player.
         */
        ActionType last_action();

        /**
         * @brief add the money to the player
         *
         * @return None.
         */
        void set_coins(int m);

        /**
         * @brief set player condition.
         *
         * @return None.
         */
        void set_playing(bool);

        /**
         * @brief set the player name
         *
         * @return None.
         */
        void set_name(const string &);

        /**
         * @brief getting the name of the player
         *
         * @return player name.
         */
        string *get_name();

        /**
         * @brief Card Name.
         *
         * @return The role of the actor
         */
        string get_card_name();

        /**
         * @brief object of the game.
         *
         * @return The object of the game
         */
        Game *get_game_name();

        /**
         *@brief attacked action
         *
         * @return Player obj.
         */
        virtual Player *got_attacked();

        /**
         *@brief The player that got stollen
         *
         * @return Player obj.
         */
        virtual Player *stolen_from();

        /**
         *@brief block action.
         *
         * @return None.
         */
        virtual void block(Player &);

        /**
         *@brief steal action
         *
         * @return None.
         */
        virtual void steal(Player &);

        /**
         *@brief tax action
         *
         * @return None.
         */
        virtual void tax();

        /**
         *@brief  transfer action
         *
         * @return None.
         */
        virtual void transfer(Player &, Player &);

        /**
         * @brief removing a player from the game
         *
         * @return None.
         */
        virtual void coup(Player &);

        /**
         * @brief the cost of coup.
         *
         * @return Return the cost of the last coup.
         */
        int coupcost() const;
    };

}
#endif