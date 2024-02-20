#include "FileReader.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

vector<string> FileReader::readFileIntoVector(string fileName) {
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

vector<string> FileReader::vectorParse(vector<string> fileLines) {
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

vector<string> FileReader::removeNumbers(vector<string> v) {
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

vector<string> FileReader::removeDuplicates(vector<string> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

int FileReader::positionFind(vector<string> candidates, string key) {
    std::vector<string>::iterator it = find(candidates.begin(), candidates.end(), key);
    return it - candidates.begin();
}

vector<vector<int>> FileReader::fillVoteIndex(vector<string> candidates, vector<string> outputLines) {
    vector<vector<int>> voteIndex;
    voteIndex.resize(candidates.size(), { 0,0,0 });

    for (int i = 0; i < outputLines.size(); i++) {
        int index = positionFind(candidates, outputLines[i]);
        int modex = i % 3;
        voteIndex[index][modex]++;
    }

    return voteIndex;
}