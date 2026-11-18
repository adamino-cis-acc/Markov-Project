#include <iostream>
#include "markov.h"
#include <fstream>
using namespace std;

string joinWords(const string words[], int startIndex, int count){
    string result = "";
    for(int i = 0; i < count; ++i)
    {
    result+= words[startIndex + i];
        if(i < count - 1){
            result += " ";
        }
    }    
    return result;
}

int readWordsFromFile(std::string filename, std::string words[], int maxWords){
    ifstream inputFile;
    inputFile.open(filename);
    if(!(inputFile.is_open())){
        return -1;

    } 
    int counter = 0;
    while(counter < maxWords && inputFile >> words[counter]){
        counter++;
            
    } 
    inputFile.close();
    return counter;
    
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

string getRandomSuffix(const std::string prefixes[], const std::string suffixes[],
    int chainSize, std::string currentPrefix){

        int matchCount = 0;
        for(int i = 0; i < chainSize; ++i){
            if(currentPrefix == prefixes[i]){
                ++matchCount;
            }
        }

        if(matchCount == 0){
            return "";
        }

        int pick = rand() % matchCount;
        int matchCount2 = 0;
        for(int i =0; i < chainSize; ++i){
            if(currentPrefix == prefixes[i]){
                if(pick == matchCount2){
                    return suffixes[i];  
                }
                matchCount2++;   
            }
            
        }
        return "";
}


