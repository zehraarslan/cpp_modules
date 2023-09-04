#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{ 
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    this->type = wrongAnimal.type;
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