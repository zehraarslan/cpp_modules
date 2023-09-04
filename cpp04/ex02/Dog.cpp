#include "Dog.hpp"

Dog::Dog()
{ 
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    brain = new Brain();
    brain->setIdeas("dogs are sweet");
}

Dog::Dog(const Dog &dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->type = dog.type;
    this->brain = new Brain();
    *(this->brain) = *(dog.brain);
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "havhav" << std::endl;
}

Brain *Dog::getBrain()
{
    return brain;
}