
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Card.hpp"
#include "Game.hpp"

#define m_ 7
using namespace std;

namespace coup
{
    class Game;
    class Player
    {
    protected:
        string name;
        string _card_name;
        string actor_draw;
        CardType _role;
        Game *_game;
        ActionType last_action;
        int _money;
        unsigned int turn_number;
        bool alive;

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
        bool is_turn();
        /**
         *@brief  checking if player is still in the game
         *
         * @return True or False.
         */
        bool is_alive() const;
        /**
         * @brief player's turn number
         *
         * @return The turn number.
         */
        unsigned int turn_num() const;
        /**
         *
         * @return Player description.
         */
        string description();
        /**
         * operator * overloading.
         */
        friend std::ostream &operator<<(std::ostream &out, const Player &p1);
        /**
         * operator == overloading.
         */
        bool operator==(const Player &p) const;
        /**
         * @brief last action of the player
         *
         * @return The last action of the player.
         */
        ActionType last_act();
        /**
         * @brief add the money to the player
         *
         * @return None.
         */
        void set_money(int m);
        /**
         * @brief set player condition.
         *
         * @return None.
         */
        void set_alive(bool);
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
        Game *game_name();
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
         *@brief attacked action
         *
         * @return Player obj.
         */
        virtual Player *getAttacked();
        /**
         * @brief removing a player from the game
         *
         * @return None.
         */
        virtual void coup(Player &);
    };

}
#endif