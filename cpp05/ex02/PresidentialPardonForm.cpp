#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("pardon", "default", 25, 5)
{ 
    std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pardon) : AForm(pardon)
{
    std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("pardon", target, 25, 5)
{
    std::cout << "[PresidentialPardonForm] constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &pardon) 
{
    std::cout << "[PresidentialPardonForm] Copy assignment operator called" << std::endl;
    *this = pardon;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}