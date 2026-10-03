#ifndef MARKOV_H
#define MARKOV_H
#include <string>
using namespace std;

string joinWords(const std::string words[], int startIndex, int count);
int readWordsFromFile(std::string filename, std::string words[], int maxWords);

#endif