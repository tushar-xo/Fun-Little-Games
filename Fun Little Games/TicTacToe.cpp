#include "TicTacToe.h"

char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void displayBoard() {
    std::cout << "Tic-Tac-Toe Board:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin() {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void makeMove(char player) {
    int choice;
    while (true) {
        std::cout << "Player " << player << ", enter a number (1-9): ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 9) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
            continue;
        }

        int row = (choice - 1) / SIZE;
        int col = (choice - 1) % SIZE;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            break;
        }
        else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
}

void resetBoard() {
    char initialBoard[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    std::copy(&initialBoard[0][0], &initialBoard[0][0] + SIZE * SIZE, &board[0][0]);
}
