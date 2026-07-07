#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "Shrubbery: Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): _target(other._target)
{
	std::cout << "Shrubbery: Copy constructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm:: operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	std::cout << "Shrubbery: Copy assignment operator called." << std::endl;
	return *this;
}

PresidentialPardonForm:: ~PresidentialPardonForm()
{
	std::cout << "Shrubbery: Destructor called." << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}