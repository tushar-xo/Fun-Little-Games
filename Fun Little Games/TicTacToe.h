#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

const int SIZE = 3;
extern char board[SIZE][SIZE];

void displayBoard();
bool checkWin();
bool isDraw();
void makeMove(char player);
void resetBoard();

#endif // TICTACTOE_H
