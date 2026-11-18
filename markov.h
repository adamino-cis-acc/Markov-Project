#ifndef MARKOV_H
#define MARKOV_H
#include <string>
using namespace std;

string joinWords(const std::string words[], int startIndex, int count);
int readWordsFromFile(std::string filename, std::string words[], int maxWords);
int buildMarkovChain(const string words[], int numWords, int order, 
    string prefixes[], string suffixes[], int maxChainSize);
std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[],
                            int chainSize, std::string currentPrefix);
std::string getRandomPrefix(const std::string prefixes[], int chainSize);




#endif