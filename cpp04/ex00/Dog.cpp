#include "Dog.hpp"

Dog::Dog()
{ 
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &Dog)
{
     std::cout << "Dog copy constructor called" << std::endl;
    *this = Dog;
}

Dog &Dog::operator=(const Dog &Dog)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->type = Dog.type;
    return *this;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound() const
{
    std::cout << "havhav" << std::endl;
}