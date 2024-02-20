#include "FileReader.h"
#include "Ballot.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    FileReader fr;
    Ballot b;

    vector<string> fileLines = fr.readFileIntoVector("LargeListBallots.csv");
    vector<string> outputLines = fr.vectorParse(fileLines);
    outputLines = fr.removeNumbers(outputLines);

    vector<string> candidates = fr.removeDuplicates(outputLines);
    vector<vector<int>> voteIndex = fr.fillVoteIndex(candidates, outputLines);

    b.BallotRound(candidates, voteIndex);

    return 0;
}