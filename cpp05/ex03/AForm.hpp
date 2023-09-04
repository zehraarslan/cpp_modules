#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSign;
        const int gradeExec;
        const std::string target;
    public:
        AForm();
        AForm(const AForm &form);
        AForm(const std::string name, const std::string target, const int gradeSing, const int gradeExec);
        AForm &operator=(const AForm &form);
        ~AForm();

        std::string getName() const;
        std::string getTarget() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &out, AForm &form);

#endif