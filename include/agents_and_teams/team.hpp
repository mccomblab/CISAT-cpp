#ifndef AGENTS_AND_TEAMS__TEAM_HPP
#define AGENTS_AND_TEAMS__TEAM_HPP

#include "agent.hpp"

class Team {
public:
    //// Functions
    Team(ParameterSet p);
    void solve(void);
    void new_start(void);
    void iterate(int iter);
    void pull_best_solution(int iter);

    //// Variables
    ParameterSet p; // ParameterSet used for SA
    std::vector<Agent> agent_list;     // A vector to store agents in
    std::vector< std::vector <long double> > best_solution; // A vector to store the time-string of best solutions in

private:
    // nothing yet
};

#endif