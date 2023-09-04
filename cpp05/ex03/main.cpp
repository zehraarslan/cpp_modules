#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{

	try
    {
        Bureaucrat harry("Haryy", 25);
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery reation", "Bender");
        std::cout << rrf->getTarget() << std::endl;

        harry.signForm(*rrf);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}