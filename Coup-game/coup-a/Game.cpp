#include "Game.hpp"

using namespace coup;

Game::Game()
{
    game = "Coup";
    turn = 0;
    active = false;
    num_of_player = 0;
}
string Game::turn()
{
    return (num_of_player >= 2) ? *players[turn]->getName() : "The game is waiting for more players";
}
vector<string> Game::_players()
{
    vector<string> names;
    for (Player *obj : players)
    {
        if (obj->is_alive())
        {
            names.push_back(*obj->getName());
        }
    }
    return names;
}
vector<Player *> Game::players_obj()
{
    return players;
}
string Game::winner()
{
    vector<string> names = players();
    if (names.size() == 1)
    {
        return names[0];
    }
    return "The game is not over yet";
}
void Game::inc_player_number()
{
    this->num_of_player++;
}
void Game::add_player(Player *p)
{
    if (num_of_player > MAXplayers)
    {
        throw invalid_argument("The game is designed for 2-6 players");
    }
    cout << "Hello Player " << *p << endl;
    players.push_back(p);
    incPlayerNumber();
}
unsigned int Game::get_turn() const
{
    return turn;
}
void Game::next_turn()
{
    turn = (turn + 1) % num_of_player;
    ;
}
unsigned int Game::get_num_ofplayers() const
{
    return num_of_player;
}
