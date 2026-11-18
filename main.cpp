#include <iostream>
#include "markov.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    cout << "Read " << count << " words" << std::endl;
    cout<< '\n';
    for (int i = 0; i < 10 && i < count; i++) {
        cout << words[i] << endl;
    }
    cout<< '\n';
    std::string prefixes[1000], suffixes[1000];
    int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 1000);
    for (int i = 0; i < 20 && i < chainSize; i++) {
        std::cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << std::endl;
    }
    cout<< '\n';
    for (int i = 0; i < 10; i++) {
        std::cout << getRandomSuffix(prefixes, suffixes, chainSize, "The") << std::endl;
    }
    cout<< '\n';
    for (int i = 0; i < 5; i++) {
        std::cout << getRandomPrefix(prefixes, chainSize) << std::endl;
    }
    cout<< '\n';
    std::string output = generateText(prefixes, suffixes, chainSize, 1, 20);
    std::cout << output << std::endl;



    return 0;
}

