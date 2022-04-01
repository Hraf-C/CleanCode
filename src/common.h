#pragma once
#include <random>
#include <iostream>
#include <iomanip>

template<typename T>
T rand(T min, T max)
{
    static std::default_random_engine generator{std::random_device{}()};
    std::uniform_int_distribution<T>  distribution{min, max};
    return distribution(generator);
}
template<typename T>
void get_input(T& choice)
{
    //std::cout << "- Enter a Choice: ";
    std::cin >> std::setw(1) >> choice ; //ignoring everything after space

    //Error check
    while (!std::cin.good())
    {
        std::cout << " Invalid input! please try again ."<< std::endl;

        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');

        std::cout << "- Enter a Choice: ";
        std::cin >> std::setw(1) >> choice ;

    }
    std::cin.clear();
    std::cin.ignore(INT_MAX,'\n');
}