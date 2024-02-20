#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Ballot {
public:
    /**
    * Simulates a round of voting based on the given candidates and their vote index.
    * @param candidates: A vector of strings containing the names of the candidates.
    * @param voteIndex: A 2D vector representing the vote counts for each candidate.
    */
	void BallotRound(vector<string> candidates, vector<vector<int>> voteIndex);
};