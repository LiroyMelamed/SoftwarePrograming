#include "Game.hpp"

using namespace coup;

Game::Game()
{
    game_name = "Coup";
    act_turn = 0;
    running = false;
    num_of_player = 0;
    active_player = 0;
}
string Game::turn()
{
    return (num_of_player >= MINPLAYER) ? *_players[act_turn]->get_name() : "Waiting for more players";
}
vector<string> Game::players()
{
    vector<string> p_names;
    for (Player *p : _players)
    {
        if (p->is_playing())
        {
            p_names.push_back(*p->get_name());
        }
    }
    return p_names;
}
vector<Player *> Game::players_obj()
{
    return _players;
}
string Game::winner()
{
    vector<string> p_names = players();
    if (p_names.size() == 1 && num_of_player > 1)
    {
        return p_names[0];
    }
    throw invalid_argument("no winner yet");
}
void Game::inc_player_num()
{
    this->num_of_player++;
    this->active_player++;
}
void Game::add_player(Player *p)
{
    if (num_of_player > MAXPLAYER)
    {
        throw invalid_argument("Only 2-6 players");
    }
    _players.push_back(p);
    inc_player_num();
}
unsigned int Game::get_turn() const
{
    return act_turn;
}
void Game::next_turn()
{
    do
    {
        act_turn = (act_turn + 1) % num_of_player;
    } while (!_players[act_turn]->is_playing());
}
unsigned int Game::get_num_of_players() const
{
    return num_of_player;
}
void Game::set_active_player(int m)
{
    active_player += m;
}
int Game::get_active_player() const
{
    return active_player;
}
bool Game::get_running() const
{
    return running;
}
void Game::set_running()
{
    running = (num_of_player > MINPLAYER);
}