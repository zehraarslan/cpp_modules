#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat&operator=(const Bureaucrat &bureaucrat);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form);

    class GradeTooHighException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif