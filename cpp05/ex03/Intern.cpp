#include "Intern.hpp"

Intern::Intern() 
{ 
    std::cout << "[Intern] Default constructor called" << std::endl;
}

Intern::Intern(const Intern &intern)
{
    std::cout << "[Intern] Copy constructor called" << std::endl;
    *this = intern;
}


Intern &Intern::operator=(const Intern &intern) 
{
    std::cout << "[Intern] Copy assignment operator called" << std::endl;
    *this = intern;
    return *this;
}

Intern::~Intern()
{
    std::cout << "[Intern] Destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string formName, const std::string formTarget)
{
    int i;
    std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    i = 0;
    while (i < 3)
    {
        if (names[i] == formName)
            break;
        i++;
    }
    
    
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << names[i] << std::endl;
        return new ShrubberyCreationForm(formTarget);
        break;
    case 1:
        std::cout << "Intern creates " << names[i] << std::endl;
        return new RobotomyRequestForm(formTarget);
        break;
    case 2:
        std::cout << "Intern creates " << names[i] << std::endl;
        return new PresidentialPardonForm(formTarget);
        break;
    default:
        throw Intern::InvalidFormException();
        break;
    }
}

const char* Intern::InvalidFormException::what() const throw()
{
    return "Invalid form name!!";
}