#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat harry("Harry", 5);
	Bureaucrat hermione("Hermione", 149);
	Form lakeMonster ("Lake Monster", 3, 5);
	Form ghost("Ghost", 1, 89);

	std::cout << ghost << std::endl;
	std::cout << lakeMonster << std::endl;
	try
	{
		Form test1("Test1", 151, 3);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		harry.signForm(ghost);
		std::cout << lakeMonster << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		std::cout << harry << std::endl;
		harry.incrementGrade();
		std::cout << ghost << std::endl;
		std::cout << harry << std::endl;
		harry.signForm(ghost);
		std::cout << ghost << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}