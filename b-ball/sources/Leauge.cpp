#include <iostream>
#include "Leauge.hpp"
using namespace std;

namespace ariel
{

    Leauge::Leauge()
    {
        this->end_league = false;
        for (int i = 0; i < 20; ++i)
        {
            this->teams.push_back(new Team(to_string(i), 0.5));
        }
    }
    Leauge::Leauge(vector<Team *> teams)
    {
        if (teams.size() > 20)
        {
            throw invalid_argument("Too much teams\n");
        }
        this->end_league = false;
        for (unsigned int i = 0; i < teams.size(); ++i)
        {
            this->teams.push_back(teams.at(i));
        }
        int i = 0;
        while (teams.size() < 20)
        {
            this->teams.push_back(new Team(to_string(i), 0.5));
            i++;
        }
    }

    Leauge::~Leauge()
    {
        for (int i = (int)teams.size() - 1; i >= 0; --i)
        {
            delete teams.at((unsigned int)i);
        }
    }

    void Leauge::startLeauge()
    {
        Schedule *sch = new Schedule(this->teams);
        vector<Game *> games = sch->makeSchedule();
        for (unsigned int i = 0; i < games.size(); ++i)
        {
            games.at(i)->startGame();
        }
        this->end_league = true;
        fixLeauge();
    }

    void Leauge::fixLeauge()
    {
        if (!this->end_league)
        {
            throw invalid_argument("Cant do leauge functions as long as leauge didnt start\n");
        }
        for (unsigned int i = 0; i < 20; ++i)
        {
            this->teams.at(i)->score = this->teams.at(i)->wins + 0.0001 * (this->teams.at(i)->scorePts - this->teams.at(i)->sufferedPts);
        }
        for (size_t i = 0; i < this->teams.size() - 1; ++i)
        {
            for (size_t j = 0; j < this->teams.size() - i - 1; ++j)
            {
                if (this->teams.at(j)->score < this->teams.at(j + 1)->score)
                    std::swap(this->teams.at(j), this->teams.at(j + 1));
            }
        }
    }
    void Leauge::printLeauge(int limit)
    {
        if (!this->end_league)
        {
            throw invalid_argument("Cant do leauge functions as long as leauge didnt start\n");
        }
        std::cout << "Leauge Ranking" << std::endl;
        for (unsigned int i = 0; i < limit; ++i)
        {
            std::cout << i + 1 << ") " << this->teams.at(i)->name << " Wins-Loses: " << this->teams.at(i)->wins
                      << "-" << this->teams.at(i)->loses << ". Score-Suffer: " << this->teams.at(i)->scorePts << "-"
                      << this->teams.at(i)->sufferedPts << ". TOTAL SCORE: " << this->teams.at(i)->score << std::endl;
        }
        int maxWINS = 0;
        Team *maxWin;
        int maxLOSES = 0;
        Team *maxLose;
        for (unsigned int i = 0; i < 20; ++i)
        {
            if (this->teams.at(i)->winSpree_max > maxWINS)
            {
                maxWINS = this->teams.at(i)->winSpree_max;
                maxWin = this->teams.at(i);
            }
            if (this->teams.at(i)->loseSpree_max > maxLOSES)
            {
                maxLOSES = this->teams.at(i)->loseSpree_max;
                maxLose = this->teams.at(i);
            }
        }
        std::cout << "Most wins spree by " << maxWin->name << " with: " << maxWINS << " spree wins!" << std::endl;
        std::cout << "Most loses spree by " << maxLose->name << " with: " << maxLOSES << " spree loses!" << std::endl;
        std::cout << "Teams that scored more than they suffered:" << std::endl;
        for (unsigned int i = 0; i < 20; ++i)
        {
            if (this->teams.at(i)->scorePts - this->teams.at(i)->sufferedPts > 0)
            {
                std::cout << this->teams.at(i)->name << " with: " << this->teams.at(i)->scorePts << ":" << this->teams.at(i)->sufferedPts << std::endl;
            }
        }
    }

}