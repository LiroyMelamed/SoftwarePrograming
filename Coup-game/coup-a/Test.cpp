#include "doctest.h"
#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include "Card.hpp"

using namespace std;
using namespace coup;

TEST_CASE("initialization")
{
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    vector<Player *> players = game_1.players_obj();

    SUBCASE("Game address")
    {
        CHECK(duke.game_name() == &game_1);
        CHECK(assassin.game_name() == &game_1);
        CHECK(ambassador.game_name() == &game_1);
        CHECK(captain.game_name() == &game_1);
        CHECK(contessa.game_name() == &game_1);
    }

    SUBCASE("Name Check")
    {
        // Checking the player name
        CHECK(*duke.get_name() == "Moshe");
        CHECK(*assassin.get_name() == "Yossi");
        CHECK(*ambassador.get_name() == "Meirav");
        CHECK(*captain.get_name() == "Reut");
        CHECK(*contessa.get_name() == "Gilad");

        // Attempt to change player name
        duke.set_name("Barak");
        CHECK(*duke.get_name() == "Barak");
        CHECK(*players[0]->get_name() == "Barak");
    }
    SUBCASE("Player's role"){
        CHECK(duke.role() == "Duke");
        CHECK(assassin.role() == "Assassin");
        CHECK(ambassador.role() == "Ambassador");
        CHECK(captain.role() == "Captain");
        CHECK(contessa.role() == "Contessa");

    }
    SUBCASE("Player's coins after init")
    {
        // Checking the player money
        CHECK(duke.coins() == 0);
        CHECK(assassin.coins() == 0);
        CHECK(ambassador.coins() == 0);
        CHECK(captain.coins() == 0);
        CHECK(contessa.coins() == 0);
    }
    SUBCASE("Players num")
    {
        Game game{};
        CHECK(game.get_num_of_players() == 0);

        Duke duke1{game, "Moshe"};
        CHECK(game.get_num_of_players() == 1);

        Assassin assassin1{game, "Yossi"};
        CHECK(game.get_num_of_players() == 2);

        Ambassador ambassador1{game, "Meirav"};
        CHECK(game.get_num_of_players() == 3);

        Captain captain1{game, "Reut"};
        CHECK(game.get_num_of_players() == 4);

        Contessa contessa1{game, "Gilad"};
        CHECK(game.get_num_of_players() == 5);

        Contessa contessa2{game, "Gilad"};
        CHECK(game.get_num_of_players() == 6);
    }
    SUBCASE("Player active")
    {
        CHECK(duke.is_alive() == true);
        CHECK(assassin.is_alive() == true);
        CHECK(ambassador.is_alive() == true);
        CHECK(captain.is_alive() == true);
        CHECK(contessa.is_alive() == true);
    }
    SUBCASE("Turn number")
    {
        CHECK(duke.turn_num() == 0);
        CHECK(assassin.turn_num() == 1);
        CHECK(ambassador.turn_num() == 2);
        CHECK(captain.turn_num() == 3);
        CHECK(contessa.turn_num() == 4);
    }
}
TEST_CASE("Functionality test")
{
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    vector<Player *> players = game_1.players_obj();

    SUBCASE("Income action")
    {
        vector<Player *> players = game_1.players_obj();
        duke.income();
        assassin.income();
        ambassador.income();
        captain.income();
        contessa.income();
        for (Player *p : players)
        {
            CHECK(p->coins() == 1);
        }
    }
    SUBCASE("Foreign_aid action")
    {
        duke.foreign_aid();
        assassin.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();
        for (Player *p : players)
        {
            CHECK(p->coins() == 2);
        }
    }
    SUBCASE("Player turn")
    {

        for (Player *p : players)
        {
            CHECK(p->turn_num() == game_1.get_turn());
            p->income();
        }
        CHECK(duke.turn_num() == game_1.get_turn());
        CHECK_FALSE(assassin.turn_num() == game_1.get_turn());
        CHECK_FALSE(ambassador.turn_num() == game_1.get_turn());
        CHECK_FALSE(captain.turn_num() == game_1.get_turn());
        CHECK_FALSE(contessa.turn_num() == game_1.get_turn());
        
    }
}
TEST_CASE("operator overloading")
{
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    vector<Player *> players = game_1.players_obj();
    

    SUBCASE("Equality between objects")
    {

        CHECK(duke == duke);
        CHECK_FALSE(duke == assassin);
        CHECK_FALSE(duke == ambassador);
        CHECK_FALSE(duke == captain);
        CHECK_FALSE(duke == contessa);

    }
}
TEST_CASE("Action test")
{
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    vector<Player *> players = game_1.players_obj();

    SUBCASE("Block action")
    {
        CHECK_THROWS(duke.block(assassin));
        CHECK_THROWS(duke.block(captain));
        CHECK_THROWS(duke.block(ambassador));
        CHECK_THROWS(duke.block(contessa));
        CHECK_THROWS(duke.block(duke));
        duke.income();
        CHECK(duke.coins() == 1);
        assassin.foreign_aid();
        CHECK(assassin.coins() == 2);
        duke.block(assassin);
        CHECK(assassin.coins() == 0);
        CHECK(game_1.get_turn() == 2);

    }
    SUBCASE("Tax action")
    {
        CHECK(duke.coins() == 0);
        CHECK_NOTHROW(duke.tax());
        CHECK(duke.coins() == 3);
    }
    SUBCASE("Transfer action")
    {
        CHECK_THROWS(duke.transfer(duke, duke));
        CHECK_THROWS(duke.transfer(duke, assassin));
        CHECK_THROWS(duke.transfer(duke, ambassador));
        CHECK_THROWS(duke.transfer(duke, captain));
        CHECK_THROWS(duke.transfer(duke, contessa));

    }
    SUBCASE("Steal action")
    {
        CHECK_THROWS(duke.steal(duke));
        CHECK_THROWS(duke.steal(assassin));
        CHECK_THROWS(duke.steal(ambassador));
        CHECK_THROWS(duke.steal(captain));
        CHECK_THROWS(duke.steal(contessa));

    }
}