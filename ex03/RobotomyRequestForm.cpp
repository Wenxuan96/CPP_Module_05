#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "Robotomy Request: Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): _target(other._target)
{
	std::cout << "Robotomy Request: Copy constructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm:: operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "Robotomy Request: Copy assignment operator called." << std::endl;
	return *this;
}

RobotomyRequestForm:: ~RobotomyRequestForm()
{
	std::cout << "Robotomy Request: Destructor called." << std::endl;
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