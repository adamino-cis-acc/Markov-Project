#include <iostream>
#include "markov.h"
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


