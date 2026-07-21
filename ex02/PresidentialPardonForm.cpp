#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "Presidential Pardon: Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): _target(other._target)
{
	std::cout << "Presidential Pardon: Copy constructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm:: operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator = (other);
		_target = other._target;
	}
	std::cout << "Presidential Pardon: Copy assignment operator called." << std::endl;
	return *this;
}

PresidentialPardonForm:: ~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon: Destructor called." << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}