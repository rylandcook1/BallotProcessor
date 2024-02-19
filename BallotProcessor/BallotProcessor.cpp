#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

/**
 * Function to read lines from a file into a vector of strings, skipping the first line.
 * @param fileName: The name of the file to read.
 * @return A vector of strings containing the lines read from the file.
 */
vector<string> readFileIntoVector(string fileName) {
    vector<string> fileLines;
    string myText;
    ifstream myReadFile(fileName);

    // skips the first line
    getline(myReadFile, myText);

    // takes the remaining lines and pushes to vector
    while (getline(myReadFile, myText)) {
        fileLines.push_back(myText);
    }

    return fileLines;
}

/**
 * Function to parse each line of a vector of strings into tokens separated by commas.
 * @param fileLines: A vector of strings containing lines to parse.
 * @return A vector of strings containing the parsed tokens.
 */
vector<string> vectorParse(vector<string> fileLines) {
    vector<string> myStringTokens;
    for (int i = 0; i < fileLines.size(); i++) {
        
        string outputString;
        stringstream ss(fileLines[i]);

        while (getline(ss, fileLines[i], ',')) {
            myStringTokens.push_back(fileLines[i]);
        }
    }
    return myStringTokens;
}

/**
 * Function to remove strings from a vector that start with a number.
 * @param v: The vector of strings to remove numbers from.
 * @return The vector with numbers removed.
 */
vector<string> removeNumbers(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        if (isdigit(v[i][0])) {
            v.erase(v.begin() + i);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "") {
            v.erase(v.begin() + i);
        }
    }
    return v;
}

/**
 * Function to remove duplicate strings from a vector.
 * @param v: The vector of strings to remove duplicates from.
 * @return The vector with duplicates removed.
 */
vector<string> removeDuplicates(vector<string> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

/**
 * Function to find the position of a string in a vector of strings.
 * @param candidates: The vector of strings to search within.
 * @param key: The string to search for.
 * @return The position of the string in the vector, or -1 if not found.
 */
int positionFind(vector<string> candidates, string key) {
    std::vector<string>::iterator it = find(candidates.begin(), candidates.end(), key);
    return it - candidates.begin();
}

/**
 * Function to fill a 2D vector representing vote counts for each candidate.
 * @param candidates: The vector of candidate names.
 * @param outputLines: The vector of strings containing parsed vote data.
 * @return A 2D vector representing vote counts for each candidate.
 */
vector<vector<int>> fillVoteIndex(vector<string> candidates, vector<string> outputLines) {
    vector<vector<int>> voteIndex;
    voteIndex.resize(candidates.size(), { 0,0,0 });

    for (int i = 0; i < outputLines.size(); i++) {
        int index = positionFind(candidates, outputLines[i]);
        int modex = i % 3;
        voteIndex[index][modex]++;
    }

    return voteIndex;
}

void BallotRound(vector<string> candidates, vector<vector<int>> voteIndex) {
    int voteOver = 0;
    int roundNumber = 1;
    while (voteOver == 0) {
        vector<int> candidateVotes;
        double totalVoteSum = 0;
        double maxPercentage = 0;
        int percIndex = 0;
        int indexLowestFirst = 10000;
        
        cout << "ROUND " << roundNumber << endl;
        cout << "-----------------------" << endl;
        // Adds up each indivdual candidates vote count and also tracks the total number of votes
        for (int i = 0; i < candidates.size(); i++) {
            int sum = voteIndex[i][0] + voteIndex[i][1] + voteIndex[i][2];
            candidateVotes.push_back(sum);
            totalVoteSum += sum;
        }

        for (int i = 0; i < candidates.size(); i++) {
            double a = candidateVotes[i];
            double perc = a / totalVoteSum * 1.0;

            // Sets the maximum percentage of votes found
            if (perc > maxPercentage) {
                maxPercentage = perc;
                percIndex = i;
            }

            for (int i = 0; i < candidates.size(); i++) {
                if (voteIndex[i][0] < indexLowestFirst) {
                    indexLowestFirst = voteIndex[i][0];
                }
                
            }

            // Prints the results for each candidate
            cout << candidates[i] << ": " << perc * 100.0 << "% (" << candidateVotes[i] << " votes)" << endl;
        }

        cout << endl;

        int oldVectorSize = candidates.size();

        if (maxPercentage > 0.5) {
            cout << "Winner: " << candidates[percIndex] << endl;
            voteOver++;
        }
        else {
            cout << "Nobody won. Another round is needed." << endl;

            for (int j = 0; j < candidates.size(); j++) {
                for (int i = 0; i < candidates.size(); i++) {
                    if (candidateVotes[i] == 0) {
                        candidates.erase(candidates.begin() + i);
                        voteIndex.erase(voteIndex.begin() + i);
                        candidateVotes.erase(candidateVotes.begin() + i);

                    }
                }
            }
            
            for (int j = 0; j < candidates.size(); j++) {
                for (int i = 0; i < candidates.size(); i++) {
                    if (voteIndex[i][0] == indexLowestFirst) {
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


int main() {
    vector<string> fileLines = readFileIntoVector("LargeListBallots.csv");
    vector<string> outputLines = vectorParse(fileLines);
    outputLines = removeNumbers(outputLines);

    vector<string> candidates = removeDuplicates(outputLines);
    vector<vector<int>> voteIndex = fillVoteIndex(candidates, outputLines);
    


    /*for (int i = 0; i < candidates.size(); i++) {
        cout << candidates[i];
        for (int j = 0; j < 3; j++) {
            cout << voteIndex[i][j] << endl;
        }
    } */

    



    BallotRound(candidates, voteIndex);

    
}


