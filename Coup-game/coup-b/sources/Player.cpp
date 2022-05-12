#include "Player.hpp"

#include <vector>
#include <iostream>
#include <string>

using namespace std;
using namespace coup;

namespace coup
{
    Player::Player(const string &name, int money, CardType role, Game &g)
    {

        if (g.get_running() || g.get_num_of_players() >= MAXPLAYER)
        {
            throw invalid_argument("game unavaible");
        }

        this->name = name;
        num_of_coin = money;
        title = role;
        game_name = &g;
        last_act = ActionType::start;
        playing = true;
        turn_num = (*(game_name)).get_num_of_players();
        coup_cost = 0;

        switch (title)
        {
        case CardType::Duke:
            this->card_name = "Duke";
            break;
        case CardType::Assassin:
            this->card_name = "Assassin";
            break;
        case CardType::Ambassador:
            this->card_name = "Ambassador";
            break;
        case CardType::Captain:
            this->card_name = "Captain";
            break;
        case CardType::Contessa:
            this->card_name = "Contessa";
            break;
        }
        (*(game_name)).add_player(this);
    };

    void Player::income()
    {
        if (player_turn("income"))
        {
            last_act = ActionType::income;
            this->num_of_coin++;
            this->game_name->next_turn();
        }
    }
    void Player::foreign_aid()
    {
        if (player_turn("foreign_aid"))
        {
            last_act = ActionType::foreign_aid;
            this->num_of_coin += 2;
            this->game_name->next_turn();
        }
    }
    void Player::coup(Player &p)
    {
        if (!p.is_playing())
        {
            throw invalid_argument("The player already couped");
        }
        if (num_of_coin < MAXTOCOUP)
        {
            throw invalid_argument("not enough coin");
        }
        if (*this == p)
        {
            throw invalid_argument("A player cant coup himself");
        }
        player_turn("coup");
        last_act = ActionType::coup;
        num_of_coin -= MAXTOCOUP;
        p.set_playing(false);
        this->game_name->set_active_player(-1);
        this->game_name->next_turn();
    }
    string Player::role()
    {
        return card_name;
    }
    int Player::coins() const
    {
        return num_of_coin;
    }
    string *Player::get_name()
    {
        return &name;
    }
    string Player::get_card_name()
    {
        return card_name;
    }
    bool Player::player_turn(string const &act_name)
    {
        (*(game_name)).set_running();
        if (!(*(game_name)).get_running())
        {
            throw invalid_argument("start the game first");
        }
        if (this->coins() > MAXCOINSTOCOUP && act_name != "coup")
        {
            throw invalid_argument("need to coup");
        }
        if (turn_num != (*(game_name)).get_turn())
        {
            throw invalid_argument("not player turn");
        }
        if (!is_playing())
        {
            (*(game_name)).next_turn();
            throw invalid_argument("player out of the game");
        }
        return true;
    }
    bool Player::is_playing() const
    {
        return playing;
    }
    ActionType Player::last_action()
    {
        return last_act;
    }
    Game *Player::get_game_name()
    {
        return game_name;
    }
    unsigned int Player::get_turn_num() const
    {
        return turn_num;
    }
    void Player::block(Player &p)
    {
        throw invalid_argument("Probably this player cant preforme block");
    }
    void Player::steal(Player &p)
    {
        throw invalid_argument("Probably this player cant preforme steal");
    }
    void Player::tax()
    {
        throw invalid_argument("Probably this player cant preforme tax");
    }
    void Player::transfer(Player &p1, Player &p2)
    {
        throw invalid_argument("Probably this player cant preforme transfer");
    }
    void Player::set_name(const string &name)
    {
        this->name = name;
    }
    bool Player::operator==(const Player &p) const
    {
        return this == &p;
    }
    void Player::set_coins(int m)
    {
        num_of_coin += m;
    }
    Player *Player::stolen_from()
    {
        throw invalid_argument("Probably this player cant preforme this act");
    }
    void Player::set_playing(bool die)
    {
        last_act = (die) ? ActionType::back : ActionType::out;
        playing = die;
    }
    Player *Player::got_attacked()
    {
        throw invalid_argument("Probably this player cant preforme attack");
    }
    ostream &operator<<(std::ostream &out, const Player &p1)
    {
        return out;
    }
    int Player::coupcost() const
    {
        return coup_cost;
    }
}
