#include "WrongCat.hpp"

WrongCat::WrongCat()
{ 
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongCat)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    this->type = wrongCat.type;
    return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

std::string WrongCat::getType() const
{
    return this->type;
}


void WrongCat::makeSound() const
{
    std::cout << "miyavvvvvvvvv" << std::endl; 
}