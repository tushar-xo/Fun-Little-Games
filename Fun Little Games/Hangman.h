#pragma once
#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

void display(const std::string& word, const std::vector<bool>& guessed);
bool isComplete(const std::vector<bool>& guessed);
void playHangman();

#endif // HANGMAN_H
