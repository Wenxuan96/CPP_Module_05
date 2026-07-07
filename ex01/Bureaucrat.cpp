#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name(""), _grade(0)
{
	std::cout << "Default constructor called. Grade set to 0." << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name), _grade(grade)
{
	std::cout << "Parameterized constructor called." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureacrat destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name),_grade(other._grade)
{
	std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

int Bureaucrat:: getGrade() const
{
	return _grade;
}

const std::string& Bureaucrat:: getName() const
{
	return _name;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade too low";
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
} 

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
} 

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return os;
}