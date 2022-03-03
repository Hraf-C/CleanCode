#include "guess_number.h"
#include <iostream>
#include <random>
#include <iomanip>

int rand(int min, int max)
{
    static std::default_random_engine generator{std::random_device{}()};
    std::uniform_int_distribution<int>  distribution{min, max};
    return distribution(generator);
}

int get_choice( )
{
    int choice ;
    std::cout << "- Enter a Choice: ";
    std::cin >> std::setw(1) >> choice ;

    //Error check
    while (!std::cin.good())
    {
        std::cout << " Invalid choice ! please try again .";

        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');

        std::cout << "- Enter a Choice: ";
        std::cin >> std::setw(1) >> choice ;

    }
    std::cin.clear();
    std::cin.ignore(INT_MAX,'\n');

    return choice;
}
int game_level()
{
    std::cout << "Choose from 1 to 3 how lucky you think you are today : \n 1-Lucky \t 2-Very lucky \t 3-God of luck "<< std::endl ;
    int choice,max_to_guess=100;
    choice=get_choice();
    
   switch(choice) {
  case 1:
    max_to_guess=10;
    break;
  case 2:
    max_to_guess=50;
    break;
  case 3:
    max_to_guess=100;
    break;
  default:
		std::cout << "invalid choice !"<< std::endl ;
		game_level() ;
    break;
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
        int player_guess=get_choice();
        if (player_guess< number_to_guess) {
            std::cout << "wrong ! Guess a number greater then " << player_guess << std::endl;
        }
        else if (player_guess > number_to_guess) {
            std::cout << "wrong ! Guess a number lower then " << player_guess << std::endl;}
        else {
            std::cout << "Congrats, you won!\n";
            finished = true;
            }
    }
    }