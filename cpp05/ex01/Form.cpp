#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), gradeSign(1), gradeExec(1)
{
    std::cout << "[Form] Default constructor called" << std::endl;
}

Form::Form(const std::string _name, const int _gradeSign, const int _gradeExec) 
    : name(_name), isSigned(false), gradeSign(_gradeSign), gradeExec(_gradeExec)
{
    std::cout << "[Form] constructor called" << std::endl;
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
}

Form &Form::operator=(const Form &form)
{
    std::cout << "[Form] Copy constructor called" << std::endl;
    this->isSigned = form.isSigned;
    return *this;
}

Form::Form(const Form &form) 
    : name(form.getName()), isSigned(false), gradeSign(form.getGradeSign()), gradeExec(form.getGradeExec())
{ 
    std::cout << "[Form] Copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "[Bureaucrat] Destructor called" << std::endl;
}

std::string Form::getName() const { return this->name; }
bool Form::getIsSigned() const { return this->isSigned; }
int Form::getGradeSign() const { return this->gradeSign; }
int Form::getGradeExec() const { return this->gradeExec; }

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!!\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!!\n";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeSign())
    {
        throw Form::GradeTooLowException();
    }
    isSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
    out << form.getName()   << ", is form signed : " << std::boolalpha << form.getIsSigned() 
                            << "  Grade required for signing : "<<form.getGradeSign()
                            << "  Grade required for executing: "<<form.getGradeExec();
    return out;
}

