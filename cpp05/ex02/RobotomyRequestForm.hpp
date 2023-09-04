#ifndef ROBOTMYREQUESTFORM_HPP
#define ROBOTMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : virtual public AForm
{
    private:
        
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &robot);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &robot);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};

#endif