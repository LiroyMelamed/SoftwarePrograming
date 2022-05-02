#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <string>
#include "Card.hpp"
#include "Player.hpp"
using coup::CardType;
using namespace std;

namespace coup
{
  class Player;
  class Game
  {
  private:
    string _game;
    vector<Player *> _players;
    bool running;
    unsigned int num_of_player;
    unsigned int act_turn;

  public:
    /**
     * @brief creates a new object
     *
     * @return None.
     */
    Game();
    /**
     * @brief The player name turn in the gameץ
     *
     * @return Returns the name of the player turn.
     */
    string turn();
    /**
     * @brief creating a vector that contains the names of the players.
     *
     * @return Returns a vector that contains the players names in the game.
     */
    vector<string> players();
    /**
     * @brief creating a vector that contains the object of the players.
     *
     * @return Returns a vector that contains the object of all the  players.
     */
    vector<Player *> players_obj();
    /**
     *@brief adding players into the players vector by the address of the object.
     *
     * @param Player The obj of player
     * @return None.
     */
    void add_player(Player *);
    /**
     *@brief increases the number of players.
     *
     * @return None.
     */
    void inc_player_num();
    /**
     *@brief returns the number of players that started the game.
     *
     * @return Number of players in the game.
     */
    unsigned int get_num_of_players() const;
    /**
     * @brief promoting the turn to the next player.
     *
     * @return None.
     */
    void next_turn();
    /**
     * @brief returning the name of the player who won the game
     *
     * @return The name of the winner.
     */
    string winner();
    
    void set_name();
 
    string get_name();

    void set_turn();
    
    unsigned int get_turn() const;
 
    void set_running();

    bool get_running();
  };

}
#endif