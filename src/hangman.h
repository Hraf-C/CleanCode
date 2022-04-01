#pragma once
#include <iostream>
#include <string>


void play_hangman();
const char* pick_a_random_word();
int letterFill(char player_guess, std::string secret_word, std::string& hashed_word);