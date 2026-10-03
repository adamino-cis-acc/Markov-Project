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

