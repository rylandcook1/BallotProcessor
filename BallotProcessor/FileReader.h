#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class FileReader {
public:
    /**
    * Function to read lines from a file into a vector of strings, skipping the first line.
    * @param fileName: The name of the file to read.
    * @return A vector of strings containing the lines read from the file.
    */
    vector<string> readFileIntoVector(string fileName);

    /**
    * Function to parse each line of a vector of strings into tokens separated by commas.
    * @param fileLines: A vector of strings containing lines to parse.
    * @return A vector of strings containing the parsed tokens.
    */
    vector<string> vectorParse(vector<string> fileLines);

    /**
    * Function to remove strings from a vector that start with a number.
    * @param v: The vector of strings to remove numbers from.
    * @return The vector with numbers removed.
    */
    vector<string> removeNumbers(vector<string> v);

    /**
    * Function to remove duplicate strings from a vector.
    * @param v: The vector of strings to remove duplicates from.
    * @return The vector with duplicates removed.
    */
    vector<string> removeDuplicates(vector<string> v);

    /**
    * Function to find the position of a string in a vector of strings.
    * @param candidates: The vector of strings to search within.
    * @param key: The string to search for.
    * @return The position of the string in the vector, or -1 if not found.
    */
    int positionFind(vector<string> candidates, string key);

    /**
    * Function to fill a 2D vector representing vote counts for each candidate.
    * @param candidates: The vector of candidate names.
    * @param outputLines: The vector of strings containing parsed vote data.
    * @return A 2D vector representing vote counts for each candidate.
    */
    vector<vector<int>> fillVoteIndex(vector<string> candidates, vector<string> outputLines);
};