#include <iostream>
#include "markov.h"
#include <fstream>
using namespace std;

string joinWords(const string words[], int startIndex, int count){
    string result = "";
    for(int i = startIndex; i < startIndex + count; i++){
        result += words[i];
        if(i < startIndex + count){
            result += " ";
        }
    }
    return result;
}

int readWordsFromFile(std::string filename, std::string words[], int maxWords){
    ifstream inputFile;
    inputFile.open(filename);
    if(inputFile.is_open()){
        int counter = 0;
        while(counter < maxWords && inputFile >> words[counter]){
            counter++;
            
        } 
        return counter;

    }
    return 0;
    
}

int buildMarkovChain(const string words[], int numWords, int order, 
    string prefixes[], string suffixes[], int maxChainSize){
        if(!(order >= 1 && order <= 3) || numWords <= order || maxChainSize <= 0){
            return 0;
        }
        int count = 0;
        int i = 0;
        while(i < numWords - order && count < maxChainSize){
            string prefix = joinWords(words, i, order);
            string suffix = words[i + order];
            prefixes[count] = prefix;
            suffixes[count] = suffix;
            ++count;
            ++i;
        }
        return count;

}

