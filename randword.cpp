#include "randword.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

std::vector<std::string> dictionary;

void InitDictionary(std::string filename)
{
    std::ifstream file(filename);
    std::vector<std::string> words;
    std::string word;
    while (std::getline(file, word))
    {
        dictionary.push_back(word);
    }
}

std::string ChooseRandomWord()
{
    srand(time(0));
    return dictionary[rand() % dictionary.size()];
}
