#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145,137), _target(target)
{
	std::cout << "Shrubbery: Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): _target(other._target)
{
	std::cout << "Shrubbery: Copy constructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm:: operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	std::cout << "Shrubbery: Copy assignment operator called." << std::endl;
	return *this;
}

ShrubberyCreationForm:: ~ShrubberyCreationForm()
{
	std::cout << "Shrubbery: Destructor called." << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());

	if (!file.is_open())
		throw std::runtime_error("Could not create shrubbery file.");

	file << "          &&& &&  & &&\n";
	file << "      && &\\/&\\|& ()|/ @, &&\n";
	file << "      &\\/(/&/&||/& /_/)_&/_&\n";
	file << "   &() &\\/&|()|/&\\/ '%\" & \\() \n";
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	file << "&&   && & &| &| /& & % ()& /&&\n";
	file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	file << "     &&     \\|||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "       , -=-~  .-^-\n";

	file.close();
}