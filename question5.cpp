#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "randword.h"
#include "randword.cpp"

int main()
{
    int guesses = 8;
    int correct = 0;
    std::vector<char> alreadyGuess = {};
    InitDictionary("words.txt");
    auto choosenWord = ChooseRandomWord();
    auto looksNow = std::string(choosenWord.length(), '-');
    std::cout << "Welcome to Hangman" << std::endl
              << "I will guess a secret word. On each turn, you guess a letter. If the letter is in the secret word, I will show you where it appears; if not, a part of your body gets strung up on the scaffold. The object is to guess the word before you are hung."
              << std::endl;
    char guess;
    while (guesses > 0 && correct != choosenWord.length())
    {
        std::cout << "The word now looks like this: " << looksNow << std::endl
                  << "You have " << guesses << " guesses left." << std::endl
                  << "Guess a letter: ";
        std::cin >> guess;
        bool isCorrect = false;
        for (int i = 0; i < choosenWord.length(); i++)
        {
            if (guess == choosenWord[i])
            {
                looksNow[i] = guess;
                isCorrect = true;
                ++correct;
            }
        }
        if (isCorrect)
        {
            std::cout << "That guess is correct" << std::endl;
        }
        else
        {
            std::cout << "That guess is incorrect" << std::endl;
            --guesses;
        }
    }
    if (guess > 0)
    {
        std::cout << "You win." << std::endl;
    }
    else
    {
        std::cout << "You loss." << std::endl;
    }
    std::cout << "Answer: " << choosenWord << std::endl;
    return 0;
}
