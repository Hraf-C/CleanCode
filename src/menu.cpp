#include <iostream>
#include "guess_number.h"
#include "hangman.h"
#include "common.h"

void Menu()
{
    bool quit = true;
    char choice;
    while (quit) {
    std::cout << "\n\nWhat do you want to play ?\n 1: Play Guess the Number\n 2: Play Hangman\n q: Quit "<< std::endl;
    get_input(choice); //input check 
    switch(choice) {
        case '1':
            guess_number();
            break;
        case '2':
            play_hangman();
            break;
        case 'q' :
            quit=false;
            break;
        default:
                std::cout << "invalid command ! try again "<< std::endl ;
            break;
        }
    }
   
}