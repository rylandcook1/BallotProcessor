#include "Ballot.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

void Ballot::BallotRound(vector<string> candidates, vector<vector<int>> voteIndex) {
    int voteOver = 0;
    int roundNumber = 1;
    while (voteOver == 0) {
        double totalVoteSum = 0;
        double maxPercentage = 0;
        int percIndex = 0;
        int indexLowestFirst = 10000;
        vector<int> candidateVotes;

        cout << "ROUND " << roundNumber << endl;
        cout << "-----------------------" << endl;
        // Adds up each indivdual candidates vote count and also tracks the total number of votes
        for (int i = 0; i < candidates.size(); i++) {
            int sum = voteIndex[i][0] + voteIndex[i][1] + voteIndex[i][2];
            candidateVotes.push_back(sum);
            totalVoteSum += sum;
        }

        // Finds lowest number of first choice votes
        for (int i = 0; i < candidates.size(); i++) {
            if (voteIndex[i][0] < indexLowestFirst) {
                indexLowestFirst = voteIndex[i][0];
            }

        }

        // Calculates percentages of votes that candidates got and signifies whether they got eliminated or not
        for (int i = 0; i < candidates.size(); i++) {
            double voteDecimalConversion = candidateVotes[i];
            double currentPercentage = voteDecimalConversion / totalVoteSum * 1.0;

            // Sets the maximum percentage of votes found
            if (currentPercentage > maxPercentage) {
                maxPercentage = currentPercentage;
                percIndex = i;
            }

            // Prints the results for each candidate
            cout << candidates[i] << ": " << currentPercentage * 100.0 << "% (" << candidateVotes[i] << " votes)";

            if (candidateVotes[i] == 0 || voteIndex[i][0] == indexLowestFirst) {
                cout << " <---- [ELIMINATED]" << endl;
            }
            else {
                cout << endl;
            }
        }

        // Spacer
        cout << endl;
        
        // If a win is found in the current round, the loop exits. If not, eliminations are made
        if (maxPercentage > 0.5) {
            cout << "Winner: " << candidates[percIndex] << endl;
            voteOver++;
        }
        else {
            cout << "Nobody won. Another round is needed." << endl;

            // Removes candidates if they received no votes or received the lowest amount of first choice votes
            for (int j = 0; j < candidates.size(); j++) {
                for (int i = 0; i < candidates.size(); i++) {
                    if (candidateVotes[i] == 0 || voteIndex[i][0] == indexLowestFirst) {
                        candidates.erase(candidates.begin() + i);
                        voteIndex.erase(voteIndex.begin() + i);
                        candidateVotes.erase(candidateVotes.begin() + i);

                    }
                }
            }
        }

        cout << endl;

        roundNumber++;
    }
}