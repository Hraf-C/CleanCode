#include <iostream>
#include "guess_number.h"
#include "hangman.h"
#include "common.h"
#include "noughts_and_crosses.h"

void Menu()
{
    bool quit = true;
    char choice;
   

    while (quit) {
    std::cout << "\n\nWhat game do you want to play ?\n 1: Play Guess the Number\n 2: Play Hangman\n 3: Play noughts and crosses\n q: Quit "<< std::endl;
    get_input(choice); //input check 
    switch(choice) {
        case '1':
            guess_number();
            break;
        case '2':
            play_hangman();
            break;
        case '3':
            play_noughts_and_crosses();
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