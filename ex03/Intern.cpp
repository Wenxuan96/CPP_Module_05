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

AForm* Intern::createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string names[3] =
	{
		"Shrubbery Creation Form",
		"Robotomy Request Form",
		"Presidential Pardon Form"
	};

	AForm* (Intern::*creators[3])(std::string) =
	{
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*creators[i])(target);
		}
	}

	std::cout << "Provided form name does not exist." << std::endl;
	return NULL;
}