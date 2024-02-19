#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Ballot {
public:
	void BallotRound(vector<string> candidates, vector<vector<int>> voteIndex);
};