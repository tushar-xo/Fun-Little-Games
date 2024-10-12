#include "Hangman.h"
#include <iostream>
#include <vector>
#include <algorithm>

void display(const std::string& word, const std::vector<bool>& guessed) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (guessed[i]) {
            std::cout << word[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << "\n" << std::endl;
}

bool isComplete(const std::vector<bool>& guessed) {
    return std::all_of(guessed.begin(), guessed.end(), [](bool v) { return v; });
}

void playHangman() {
    std::string word = "GLASS";
    std::vector<bool> guessed(word.size(), false);
    std::vector<char> incorrect;
    int tries = 10;
    std::cout << "\nGiving You 10 Tries to start with !\n" << std::endl;

    std::cout << "Answer is a 5 Letter word ! \n" << std::endl;
    while (tries > 0 && !isComplete(guessed)) {
        display(word, guessed);
        std::cout << "\nIncorrect guesses: ";
        for (char c : incorrect) {
            std::cout << c << " ";
        }
        std::cout << "Tries left: " << tries << std::endl;

        char guess;
        std::cout << "Enter a guess (HINT: one letter at a time): ";
        std::cin >> guess;
        guess = std::toupper(guess);

        bool correct = false;
        for (size_t i = 0; i < word.size(); ++i) {
            if (word[i] == guess) {
                guessed[i] = true;
                correct = true;
            }
        }

        if (!correct) {
            incorrect.push_back(guess);
            --tries;
        }
    }

    if (isComplete(guessed)) {
        std::cout << "Congratulations! You guessed the word: " << word << std::endl;
    }
    else {
        std::cout << "Out of tries! The word was: " << word << std::endl;
    }
}
