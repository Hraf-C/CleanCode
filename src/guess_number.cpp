#include "guess_number.h"
#include "common.h"
#include <iostream>
#include <random>
#include <iomanip>


//check if player choice is in the range of the generated random number 
void range_control(int min,int max,int player_choice)
{
    if (player_choice < min || player_choice > max) {
            std::cout << "Out of the range of the game ! Remamber the correct number is between " << min<<" and "<<max<< std::endl;
        }
}
//let the player choose how hard the game they want to play
int game_level()
{
    bool valid_choice = false;
    int choice,max_to_guess=100;
    while (!valid_choice) {
    std::cout << "Choose from 1 to 3 how lucky you think you are today : \n 1-Lucky \t 2-Very lucky \t 3-God of luck "<< std::endl ;
    get_input(choice); //input check 
    
    
        switch(choice) {
        case 1:
            max_to_guess=10; 
            valid_choice=true;
            break;
        case 2:
            max_to_guess=50;
            valid_choice=true;
            break;
        case 3:
            max_to_guess=100;
            valid_choice=true;
            break;
        default:
                std::cout << "invalid choice ! try again "<< std::endl ;
                valid_choice=false;
            break;
        }
    }
 return max_to_guess;
   
}


void guess_number()
{
    const int max_to_guess = game_level();
    static constexpr int min= 0;
    const int max= max_to_guess; 
    const int number_to_guess = rand(min,max);
    std::cout << "guess a number between 0 and " << max << std::endl;
    bool finished = false;
    while (!finished) {
        int player_guess;
        get_input(player_guess);
        range_control(min,max,player_guess);
        if (player_guess< number_to_guess && player_guess > min ) {
            std::cout << "wrong ! Guess a number greater then " << player_guess << std::endl;
        }
        else if (player_guess > number_to_guess && player_guess < max ) {
            std::cout << "wrong ! Guess a number lower then " << player_guess << std::endl;}
        else if (player_guess < max && player_guess > min ){
            std::cout << "Congrats, you won!\n";
            finished = true;
            }
    }
}