#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "[Bureaucrat] Default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    std::cout << "[Bureaucrat] constructor called\n";
    if ( grade > 150 )
    {
        Bureaucrat::GradeTooLowException();
    }
    else if (grade < 1)
    {
        Bureaucrat::GradeTooHighException();
    }
    else
    {
        this->grade = grade;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) 
    : name(bureaucrat.getName()), grade(bureaucrat.getGrade())
{
    std::cout << "[Bureaucrat] Copy constructor called\n";
   
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    std::cout << "[Bureaucrat] Copy assignment operator called\n";
    this->grade = bureaucrat.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[Bureaucrat] Destructor called\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade too high!!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade too low!!\n";
}

void Bureaucrat::decrementGrade()
{
    if (this->grade >= 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade <= 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}