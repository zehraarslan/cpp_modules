#include "Animal.hpp"

Animal::Animal()
{ 
    std::cout << "Animal default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &animal)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->type = animal.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

Brain *Animal::getBrain()
{
    std::cout << "No brain" << std::endl;
    return 0;
}