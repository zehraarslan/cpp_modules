#include "AForm.hpp"

AForm::AForm() : name("Default"), target(""), isSigned(false), gradeSign(1), gradeExec(1)
{
    std::cout << "[AForm] Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const std::string target, const int gradeSign, const int gradeExec) 
    : name(name), target(target), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    std::cout << "[AForm] constructor called" << std::endl;
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
}

AForm &AForm::operator=(const AForm &form)
{
    std::cout << "[AForm] Copy constructor called" << std::endl;
    this->isSigned = form.isSigned;
    return *this;
}

AForm::AForm(const AForm &form) 
    : name(form.getName()), target(form.getTarget()), isSigned(false), gradeSign(form.getGradeSign()), gradeExec(form.getGradeExec())
{ 
    std::cout << "[AForm] Copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "[AForm] Destructor called" << std::endl;
}

std::string AForm::getName() const { return this->name; }
std::string AForm::getTarget() const { return this->target; }
bool AForm::getIsSigned() const { return this->isSigned; }
int AForm::getGradeSign() const { return this->gradeSign; }
int AForm::getGradeExec() const { return this->gradeExec; }

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "The Form is not Signed!!";
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeSign())
    {
        throw AForm::GradeTooLowException();
    }
    isSigned = true; 
}

std::ostream &operator<<(std::ostream &out, AForm &form)
{
    out << form.getName()   << " target : " << form.getTarget()
                            << ", is form signed : " << std::boolalpha << form.getIsSigned() 
                            << "  Grade required for signing : "<<form.getGradeSign()
                            << "  Grade required for executing: "<<form.getGradeExec();
    return out;
}

