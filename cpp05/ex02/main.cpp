#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat hary("Hary", 138);
    ShrubberyCreationForm sh("sh");
    RobotomyRequestForm rb("rb");
    PresidentialPardonForm pr("pr");
	try
    {
        hary.signForm(sh);
        hary.executeForm(sh);
        //std::cout << sh << std::endl;
        //std::cout << hary << std::endl;

        hary.signForm(rb);
        hary.executeForm(rb);

        //hary.signForm(pr);
        hary.executeForm(pr);
        

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}