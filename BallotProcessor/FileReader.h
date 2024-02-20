#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class FileReader {
public:
    vector<string> readFileIntoVector(string fileName);
    vector<string> vectorParse(vector<string> fileLines);
    vector<string> removeNumbers(vector<string> v);
    vector<string> removeDuplicates(vector<string> v);
    int positionFind(vector<string> candidates, string key);
    vector<vector<int>> fillVoteIndex(vector<string> candidates, vector<string> outputLines);
};