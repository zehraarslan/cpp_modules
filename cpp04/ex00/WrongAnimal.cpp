#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{ 
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = WrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    this->type = WrongAnimal.type;
    return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

std::string WrongAnimal::getType() const
{
    return this->type;
}


void WrongAnimal::makeSound() const
{
    std::cout << "Ses yok!!!" << std::endl; 
}