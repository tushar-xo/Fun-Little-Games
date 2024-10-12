#include <iostream>
#include "TicTacToe.h" // Include TicTacToe header
#include "NumberGuessingGame.h" // Include Number Guessing Game header
#include "RockPaperScissors.h" // Include Rock-Paper-Scissors header
#include "AdventureGame.h" // Include Adventure Game header
#include "Hangman.h" // Include Hangman header

int main() {
    int choice;
    char playAgain;

    do {
        std::cout << "Choose a game:" << std::endl;
        std::cout << "1. Tic-Tac-Toe" << std::endl;
        std::cout << "2. Number Guessing Game" << std::endl;
        std::cout << "3. Rock-Paper-Scissors" << std::endl;
        std::cout << "4. Adventure Game" << std::endl;
        std::cout << "5. Hangman" << std::endl;
        std::cout << "Enter your choice (1, 2, 3, 4, or 5): ";
        std::cin >> choice;

        if (choice == 1) {
            // Play Tic-Tac-Toe
            char currentPlayer;
            char playAgainTicTacToe;

            do {
                resetBoard();
                currentPlayer = 'X';

                while (true) {
                    displayBoard();
                    makeMove(currentPlayer);

                    if (checkWin()) {
                        displayBoard();
                        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                        break;
                    }
                    else if (isDraw()) {
                        displayBoard();
                        std::cout << "It's a draw!" << std::endl;
                        break;
                    }

                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }

                std::cout << "Do you want to play again? (y/n): ";
                std::cin >> playAgainTicTacToe;

            } while (playAgainTicTacToe == 'y' || playAgainTicTacToe == 'Y');
        }
        else if (choice == 2) {
            // Play Number Guessing Game
            numberGuessingGame();
        }
        else if (choice == 3) {
            // Play Rock-Paper-Scissors
            playRockPaperScissors();
        }
        else if (choice == 4) {
            // Play Adventure Game
            playAdventureGame();
        }
        else if (choice == 5) {
            // Play Hangman
            playHangman();
        }
        else {
            std::cout << "Invalid choice. Please choose 1, 2, 3, 4, or 5." << std::endl;
        }

        std::cout << "Do you want to play another game? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
