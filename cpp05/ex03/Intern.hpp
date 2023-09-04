#ifndef INTERN_HPP
#define INTERN_HPP
 
 #include "Bureaucrat.hpp"
 #include "AForm.hpp"
 #include "ShrubberyCreationForm.hpp"
 #include "RobotomyRequestForm.hpp"
 #include "PresidentialPardonForm.hpp"

 class Intern
 {
 private:
    
 public:
    Intern();
    Intern(const Intern &intern);
    Intern&operator=(const Intern &intern);
    ~Intern();

    AForm *makeForm(const std::string formName, const std::string formTarget);
    class InvalidFormException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
 };
 

#endif