#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "Shrubbery: Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): _target(other._target)
{
	std::cout << "Shrubbery: Copy constructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm:: operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	std::cout << "Shrubbery: Copy assignment operator called." << std::endl;
	return *this;
}

RobotomyRequestForm:: ~RobotomyRequestForm()
{
	std::cout << "Shrubbery: Destructor called." << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* drilling noises *" << std::endl;

	srand(time(NULL));

	if (rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully."
		          << std::endl;
	}
	else
	{
		std::cout << "Robotomy of " << _target << " failed."
		          << std::endl;
	}
}