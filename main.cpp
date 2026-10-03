#include <iostream>
#include "markov.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    cout << "Read " << count << " words" << std::endl;
    for (int i = 0; i < 10 && i < count; i++) {
        cout << words[i] << endl;
    }
    return 0;
}

