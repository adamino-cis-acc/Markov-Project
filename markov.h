#ifndef MARKOV_H
#define MARKOV_H
#include <string>
using namespace std;

string joinWords(const std::string words[], int startIndex, int count);
int readWordsFromFile(std::string filename, std::string words[], int maxWords);
int buildMarkovChain(const string words[], int numWords, int order, 
    string prefixes[], string suffixes[], int maxChainSize);

#endif