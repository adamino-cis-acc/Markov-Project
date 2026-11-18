#include <iostream>
#include "markov.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    string fileName;
    int order;
    int maxWords;
    cout << "Enter file name: ";
    cin >> fileName;
    cout <<"Enter the order between 1 and 3: ";
    cin >> order;
    while(1 > order || 3 < order) {
        cout << "Order must a number ranging from 1 to 3" << '\n';
        cout <<"Enter the order between 1 and 3: ";
        cin >> order;
    }
    cout << "Enter the maximum amount of words: ";
    cin >> maxWords;
    string words[maxWords], prefixes[maxWords], suffixes[maxWords];
    int count = readWordsFromFile(fileName, words, 1000);
    if(count == -1){
        cout << "Couldn't Open File";
    }
    if(count <= order){
        cout << "Minimum " << order + 1 << " training words are needed." << endl;
    }

    int chainSize = buildMarkovChain(words, count, order, prefixes, suffixes, maxWords);
    if(count == maxWords){
        cout << "Only used the first " << maxWords << " words of the input text" << endl;
    }

    string markov = generateText(prefixes, suffixes, chainSize, order, maxWords);
    cout << markov << endl;


    return 0;
}

