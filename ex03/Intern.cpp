#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern: Default constructor called." << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern: Copy constructor called." << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
	std::cout << "Intern: Copy assignment operator called." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern: Destructor called." << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	if (formName == "shrubbery creation")
	{
		std::cout << "Intern creates " << formName << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (formName == "robotomy request")
	{
		std::cout << "Intern creates " << formName << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (formName == "presidential pardon")
	{
		std::cout << "Intern creates " << formName << std::endl;
		return new PresidentialPardonForm(target);
	}

	std::cout << "Intern cannot create " << formName << std::endl;
	return NULL;
}