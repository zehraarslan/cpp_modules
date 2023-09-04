#include "Cat.hpp"

Cat::Cat()
{ 
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
    this->brain->setIdeas("cats are sweet");
}

Cat::Cat(const Cat &cat)
{
     std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = cat.type;
    this->brain = new Brain();
    *(this->brain) = *(cat.brain);
    return *this;
}

Cat::~Cat()
{ 
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miyavvv" << std::endl;
}

Brain *Cat::getBrain()
{
    return brain;
}