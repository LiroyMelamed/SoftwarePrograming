#ifndef EX5A_ITERATOR_H
#define EX5A_ITERATOR_H

#endif // EX5A_ITERATOR_H
#pragma once
#include <iostream>
#include <string.h>

namespace ariel
{
    class Team
    {
    public:
        int wins;
        int loses;
        bool team_stt;
        std::string _name;
        double _talent;
        int curr_wins_spree;
        int curr_lose_spree;
        int max_win_spree;
        int max_lose_spree;
        double score;
        int score_pts;
        int s_pts;

        Team(std::string team_name, double team_talent)
        {
            if (team_name == "\t" || team_name == "\n" || team_name.empty() || team_name == " " || team_name == "\r")
            {
                throw std::invalid_argument("Invalid team _name\n");
            }
            if (team_talent < 0 || team_talent > 1)
            {
                throw std::invalid_argument("Invalid _talent range(Must be in range of [0,1])\n");
            }
            this->_name = team_name;
            this->_talent = team_talent;
            this->max_win_spree = 0;
            this->curr_wins_spree = 0;
            this->curr_lose_spree = 0;
            this->max_lose_spree = 0;
            this->wins = 0;
            this->loses = 0;
            this->score_pts = 0;
            this->s_pts = 0;
        }
        ~Team()
        {
        }
        bool operator==(const Team &other) const
        {
            return _name == other._name;
        }

        bool operator!=(const Team &other) const
        {
            return _name != other._name;
        }
    };
}
