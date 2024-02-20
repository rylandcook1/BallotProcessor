#include "FileReader.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

/**
 * Function to read lines from a file into a vector of strings, skipping the first line.
 * @param fileName: The name of the file to read.
 * @return A vector of strings containing the lines read from the file.
 */
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

/**
 * Function to parse each line of a vector of strings into tokens separated by commas.
 * @param fileLines: A vector of strings containing lines to parse.
 * @return A vector of strings containing the parsed tokens.
 */
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

/**
 * Function to remove strings from a vector that start with a number.
 * @param v: The vector of strings to remove numbers from.
 * @return The vector with numbers removed.
 */
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

/**
 * Function to remove duplicate strings from a vector.
 * @param v: The vector of strings to remove duplicates from.
 * @return The vector with duplicates removed.
 */
vector<string> FileReader::removeDuplicates(vector<string> v) {
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
int FileReader::positionFind(vector<string> candidates, string key) {
    std::vector<string>::iterator it = find(candidates.begin(), candidates.end(), key);
    return it - candidates.begin();
}

/**
 * Function to fill a 2D vector representing vote counts for each candidate.
 * @param candidates: The vector of candidate names.
 * @param outputLines: The vector of strings containing parsed vote data.
 * @return A 2D vector representing vote counts for each candidate.
 */
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