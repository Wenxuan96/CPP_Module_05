#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name(""), grade(0)
{
	std::cout << "Default constructor called. Grade set to 0." << std::endl;
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name), grade(grade)
{
	std::cout << "Parameterized constructor called." << std::endl;
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureacrat destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name),grade(other.grade)
{
	std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
		grade = other.grade;
	return *this;
}

int Bureaucrat:: getGrade() const
{
	return grade;
}

const std::string& Bureaucrat:: getName() const
{
	return name;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return os;
}