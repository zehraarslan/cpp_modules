#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", "default", 143, 137)
{ 
    std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery) : AForm(shrubbery)
{
    std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("shrubbery", target, 143, 137)
{
    std::cout << "[ShrubberyCreationForm] constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubbery) 
{
    std::cout << "[ShrubberyCreationForm] Copy assignment operator called" << std::endl;
    *this = shrubbery;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string sh_target = (this->getTarget() + "_shrubbery");
	std::ofstream ofs;
	ofs.open(sh_target);
	if(ofs.fail())
		std::cout << "Error" << std::endl;


ofs << "          &&& &&  & &&\n";
ofs << "      && &//&||& ()|/ @, &&\n";
ofs << "      &//(/&/&||/& /_/)_&/_&\n";
ofs << "   &() &//&|()|/&/// '%' & ()\n";
ofs << "  &_/_&&_/ |& |&&/&__%_/_& &&\n";
ofs << "&&   && & &| &| /& & % ()& /&&\n";
ofs << " ()&_---()&/&/|&&-&&--%---()~\n";
ofs << "     &&     /|||\n";
ofs << "             |||\n";
ofs << "             |||\n";
ofs << "             |||\n";
ofs << "       , -=-~  .-^- _\n";
	
	ofs.close();
}