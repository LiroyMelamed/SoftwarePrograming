#ifndef EX5A_ITERATOR_H
#define EX5A_ITERATOR_H

#endif // EX5A_ITERATOR_H
#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Team.hpp"

namespace ariel
{
    class Game
    {
    public:
        Team *home;
        Team *away;

        Game(Team *a, Team *b)
        {
            this->home = a;
            this->away = b;
        }
        ~Game() {}

        int randNum(int A, int B)
        {
            int r = (rand() % (B - A)) + A;
            return r;
        }

        Team *startGame()
        {
            int home_rnd = randNum(55, 100);
            int away_rnd = randNum(50, 100);
            home_rnd += (int)(this->home->talent * 10);
            away_rnd += (int)(this->away->talent * 10);
            this->home->score_pts += (home_rnd);
            this->home->s_pts += (away_rnd);
            this->away->score_pts += (away_rnd);
            this->away->s_pts += (home_rnd);
            if (home_rnd >= away_rnd)
            {
                this->home->team_stt = true;
                this->home->curr_lose_spree = 0;
                this->home->curr_wins_spree += 1;
                this->home->wins += 1;
                if (this->home->curr_wins_spree > this->home->max_win_spree)
                {
                    this->home->max_win_spree = this->home->curr_wins_spree;
                }
                this->away->team_stt = false;
                this->away->curr_wins_spree = 0;
                this->away->curr_lose_spree += 1;
                this->away->loses += 1;
                if (this->away->curr_lose_spree > this->away->max_lose_spree)
                {
                    this->away->max_lose_spree = this->away->curr_lose_spree;
                }
                std::cout << this->home->_name << " Won " << this->away->_name << " "
                          << home_rnd << ":" << away_rnd << std::endl;
                return this->home;
            }
            this->away->team_stt = true;
            this->away->curr_lose_spree = 0;
            this->away->curr_wins_spree += 1;
            this->away->wins += 1;
            if (this->away->curr_wins_spree > this->away->max_win_spree)
            {
                this->away->max_win_spree = this->away->curr_wins_spree;
            }
            this->home->team_stt = false;
            this->home->curr_wins_spree = 0;
            this->home->curr_lose_spree += 1;
            this->home->loses += 1;
            if (this->home->curr_lose_spree > this->home->max_lose_spree)
            {
                this->home->max_lose_spree = this->home->curr_lose_spree;
            }
            std::cout << this->away->_name << " Won " << this->home->_name << " "
                      << away_rnd << ":" << home_rnd << std::endl;
            return this->away;
        }
    };
}
