#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    int i = -1;
    while (++i < 100)
        this->ideas[i] = "no idea!";
}

Brain::Brain(const std::string idea)
{
    std::cout << "Brain idea constructor called" << std::endl;
    int i = -1;
    while (++i < 100)
        this->ideas[i] = idea;
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    int i = -1;
    while (++i < 100)
        this->ideas[i] = brain.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdeas(const std::string idea)
{
    int i = -1;
    while (++i < 100)
        this->ideas[i] = idea;
}

std::string Brain::getIdeas(int i)
{
    if ( i < 0 || i > 99)
        return "Error";
    else
        return this->ideas[i];
}