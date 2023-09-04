#include "Cat.hpp"

Cat::Cat()
{ 
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &Cat)
{
     std::cout << "Cat copy constructor called" << std::endl;
    *this = Cat;
}

Cat &Cat::operator=(const Cat &Cat)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = Cat.type;
    return *this;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound() const
{
    std::cout << "miyavvv" << std::endl;
}