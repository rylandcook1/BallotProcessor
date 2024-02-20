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

    // Initializes the data set and cleans it so that it can be used with the ballot algorithm
    vector<string> fileLines = fr.readFileIntoVector("LargeListBallots.csv"); // I used the sample dataset given from the assignment but you can change this to whatever
    vector<string> outputLines = fr.vectorParse(fileLines);
    outputLines = fr.removeNumbers(outputLines);

    vector<string> candidates = fr.removeDuplicates(outputLines);
    vector<vector<int>> voteIndex = fr.fillVoteIndex(candidates, outputLines);
    
    // Runs the guts of the program
    b.BallotRound(candidates, voteIndex);

    return 0;
}
