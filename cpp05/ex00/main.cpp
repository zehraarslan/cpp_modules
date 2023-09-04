#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat harry("Harry", 2);
	Bureaucrat hermione("Hermione", 149);
	try
	{
		Bureaucrat ass(harry);
		std::cout << ass << std::endl;
		std::cout << harry << std::endl;
		std::cout << hermione << std::endl;
		harry.incrementGrade();
		hermione.decrementGrade();
		std::cout << harry << std::endl;
		std::cout << hermione << std::endl;
		//harry.incrementGrade();
		hermione.decrementGrade();
		std::cout << harry << std::endl;
		std::cout << hermione << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}