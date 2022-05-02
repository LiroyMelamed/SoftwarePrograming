#include "Game.hpp"

using namespace coup;

Game::Game()
{
    _game = "Coup";
    act_turn = 0;
    running = false;
    num_of_player = 0;
}
string Game::turn()
{
    return (num_of_player >= 2) ? *_players[act_turn]->get_name() : "Waiting for more players";
}
vector<string> Game::players()
{
    vector<string> names;
    for (Player *obj : _players)
    {
        if (obj->is_alive())
        {
            names.push_back(*obj->get_name());
        }
    }
    return names;
}
vector<Player *> Game::players_obj()
{
    return _players;
}
string Game::winner()
{
    vector<string> names = players();
    if (names.size() == 1)
    {
        return names[0];
    }
    return "The game is still running";
}
void Game::inc_player_num()
{
    this->num_of_player++;
}
void Game::add_player(Player *p)
{
    if (num_of_player > 6)
    {
        throw invalid_argument("Only 2-6 players");
    }
    cout << "Hello Player " << *p << endl;
    _players.push_back(p);
    inc_player_num();
}
unsigned int Game::get_turn() const
{
    return act_turn;
}
void Game::next_turn()
{
    act_turn = (act_turn + 1) % num_of_player;
}
unsigned int Game::get_num_of_players() const
{
    return num_of_player;
}
