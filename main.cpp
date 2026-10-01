#include <iostream>
#include "markov.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    string testWords[] = {"the", "cat", "sat", "down"};
    cout << joinWords(testWords, 0, 2) << std::endl;  
    cout << joinWords(testWords, 1, 3) << std::endl;

    return 0;
}

