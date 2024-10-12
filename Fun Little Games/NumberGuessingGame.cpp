#include "NumberGuessingGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // for std::numeric_limits

void numberGuessingGame() {
    std::srand(std::time(0)); // Seed the random number generator
    int numberToGuess = std::rand() % 100 + 1; // Random number between 1 and 100
    int userGuess = 0;
    int numberOfTries = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Can you guess it?" << std::endl;

    while (userGuess != numberToGuess) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        // Input validation
        if (std::cin.fail() || userGuess < 1 || userGuess > 100) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
            continue;
        }

        numberOfTries++;

        if (userGuess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        }
        else if (userGuess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        }
        else {
            std::cout << "Congratulations! You guessed the number in " << numberOfTries << " tries." << std::endl;
        }
    }
}
