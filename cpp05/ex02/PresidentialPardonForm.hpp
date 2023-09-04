#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
private:
    
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &pardon);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &pardon);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;
};


#endif