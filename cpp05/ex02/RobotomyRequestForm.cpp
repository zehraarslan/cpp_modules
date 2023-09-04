#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy", "default", 72, 45)
{ 
    std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robot) : AForm(robot)
{
    std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("robotomy", target, 72, 45)
{
    std::cout << "[RobotomyRequestForm] constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robot) 
{
    std::cout << "[RobotomyRequestForm] Copy assignment operator called" << std::endl;
    *this = robot;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    std::cout << "Makes some drilling noises" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << this->getTarget() << " has failed." << std::endl;
}