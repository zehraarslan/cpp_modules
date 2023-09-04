#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
    private:
        
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubbery);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};


#endif