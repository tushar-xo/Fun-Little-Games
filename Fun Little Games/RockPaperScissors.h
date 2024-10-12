#pragma once
#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include <string>

enum Moves { ROCK, PAPER, SCISSORS };

std::string moveToString(Moves move);
Moves getComputerMove();
Moves getPlayerMove();
void determineWinner(Moves player, Moves computer);
void playRockPaperScissors();

#endif // ROCKPAPERSCISSORS_H
