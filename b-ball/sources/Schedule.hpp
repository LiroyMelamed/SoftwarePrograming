#ifndef EX5_PARTA_NODE_H
#define EX5_PARTA_NODE_H

#endif // EX5_PARTA_NODE_H
#pragma once
#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"

using namespace std;
namespace ariel
{
    class Schedule
    {
    public:
        vector<Team *> teams;

        Schedule(vector<Team *> game_set)
        {
            this->teams = game_set;
        }
        ~Schedule() {}

        vector<Game *> makeSchedule()
        {
            vector<Game *> schedule;
            for (unsigned int i = 0; i < this->teams.size(); ++i)
            {
                for (unsigned int j = i; j < this->teams.size(); ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    schedule.push_back(new Game(this->teams.at(i), this->teams.at(j)));
                }
            }
            for (unsigned int i = 0; i < this->teams.size(); ++i)
            {
                for (unsigned int j = i; j < this->teams.size(); ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    schedule.push_back(new Game(this->teams.at(j), this->teams.at(i)));
                }
            }
            return schedule;
        }
    };
}
