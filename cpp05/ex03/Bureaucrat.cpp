#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
    std::cout << "[Bureaucrat] Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    std::cout << "[Bureaucrat] constructor called" << std::endl;
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
{
    std::cout << "[Bureaucrat] Copy constructor called" << std::endl;
    *this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    std::cout << "[Bureaucrat] Copy assignment operator called" << std::endl;
    this->grade = bureaucrat.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[Bureaucrat] Destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!!\n";
}

std::string Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

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

void Bureaucrat::signForm(AForm &form)
{
    try
    {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << '\n';
	} 
    catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign "
		<< form.getName() << " because " << e.what();
	}  
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (!form.getIsSigned())
    {
        std::cout << this->getName() << " couldn't executed " << form.getName() << " because ";
        throw AForm::FormNotSignedException();
    }
    if (grade > form.getGradeSign())
    {
        std::cout << this->name << " couldn't  executed " << form.getName() << " because ";
        throw Bureaucrat::GradeTooLowException();
    }
	form.execute(*this);
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}