#include "hangman.h"
#include <array>
#include <cassert>
#include <iostream>
#include "common.h"
#include <algorithm>
#include <string>

using namespace std;


std::string secret_word=pick_a_random_word();
int max_chances=secret_word.length()+3;//give the player number of chance equals number of the word plus 3 chances . 
char player_guess;
int num_of_wrong_guesses = 0;

const char* pick_a_random_word() 
{
    static constexpr std::array  word_list = { 
        "toyota", 
        "honda", 
        "chevrolet", 
        "ford",
        "mercedes",
        "jeep",
        "bmw",
        "porsche",
        "nissan",
        "volkswagen",
        "audi",
        "tesla",
        "peugeot",
        "citroen",
        
    };
 return word_list[rand<size_t>(0,word_list.size()- 1)];
} 

int letterFill(char player_guess,string secret_word,string& hashed_word)
{
  int i;
  int matches = 0;
  int len = secret_word.length();
  for (i = 0; i < len; i++)
  {
    // Did we already match this letter in a previous guess?
    if ( player_guess == hashed_word[i])
      return 0;
    // Is the guess in the secret word?
    if ( player_guess == secret_word[i])
    {
      hashed_word[i] = player_guess;
      matches++;
    }
  }
  return matches;
}



std::string hashed_word(secret_word.length(), ('_'));


void play_hangman(){

  std::cout << "\n\n Are you a car lover ! then guess a car brand name";
  std::cout << "You have " << max_chances << " chances to do so ";
  std::cout << "-the game rules are simple : type one letter in each try-";
  
    
while (num_of_wrong_guesses < max_chances)
  {
    
    std::cout << "\n\n" << hashed_word;       
    std::cout << "\n\nGuess a letter: ";    
    get_input(player_guess);
    if (letterFill(player_guess,secret_word,hashed_word) == 0)
    {
        std::cout << std::endl << "\n Whoops!the names doesn't include that letter !" << std::endl; 
        num_of_wrong_guesses++;
    }
    else
    {
      std::cout << endl << "\n Great!You found a letter!" << std::endl; 
    }
    std::cout << "\n\nYou have " << max_chances - num_of_wrong_guesses<<" chances left" << std::endl; 
    if (secret_word == hashed_word)
    {
      std::cout << secret_word << endl; //prints the word selected for the user to guess. 
      std::cout << "\n Yeah! You got it!" << std::endl;
    }

    if (num_of_wrong_guesses == max_chances) 
    {
    std::cout << "\n\nSorry, you lose." << std::endl;
    std::cout << "\nhe word was " << secret_word << std::endl;

    }
 }
  }