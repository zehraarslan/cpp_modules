#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level)
{
    int i;
    std::string levels[4]= {"DEBUG", "INFO", "WARNING", "ERROR"};
    i = 0;

    while (i < 4)
    {
        if(level == levels[i])
            break;
        i++;
    }
    
    if (i == 4)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    
    switch (i)
    {
        case 0:
            debug();
            break;
        case 1:
            info();
            break;
        case 2:
            warning();
            break;
        case 3:
            error();
            break;
        default:
            break;
    }
}

void Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money."  << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more" << std::endl;
    std::cout << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free."  << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month" << std::endl;
    std::cout << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}