#include "RockPaperScissors.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string moveToString(Moves move) {
    switch (move) {
    case ROCK: return "Rock";
    case PAPER: return "Paper";
    case SCISSORS: return "Scissors";
    default: return "";
    }
}

Moves getComputerMove() {
    return static_cast<Moves>(std::rand() % 3);
}

Moves getPlayerMove() {
    int choice;
    std::cout << "Enter your move (0: Rock, 1: Paper, 2: Scissors): ";
    std::cin >> choice;
    return static_cast<Moves>(choice);
}

void determineWinner(Moves player, Moves computer) {
    std::cout << "You chose: " << moveToString(player) << "\n";
    std::cout << "Computer chose: " << moveToString(computer) << "\n";

    if (player == computer) {
        std::cout << "It's a tie!" << std::endl;
    }
    else if ((player == ROCK && computer == SCISSORS) ||
        (player == PAPER && computer == ROCK) ||
        (player == SCISSORS && computer == PAPER)) {
        std::cout << "You win!" << std::endl;
    }
    else {
        std::cout << "You lose!" << std::endl;
    }
}

void playRockPaperScissors() {
    std::srand(std::time(0)); // Seed random number generator
    Moves playerMove = getPlayerMove();
    Moves computerMove = getComputerMove();
    determineWinner(playerMove, computerMove);
}
