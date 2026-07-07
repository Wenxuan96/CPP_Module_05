#include "Form.hpp"

Form::Form():_name(""), _isSigned(false), _signedGrade(0), _gradeToExecute(0)
{
	std::cout << "Default constructor called. Grade is neither signed nor executed, grade set to 0." << std::endl;
	if (_signedGrade < 1)
		throw GradeTooHighException();
	else if (_signedGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const std::string name, int gradeToSign):_name(name), _isSigned(false), _signedGrade(gradeToSign), _gradeToExecute(0)
{
	std::cout << "Parameterized constructor called." << std::endl;
	if (_signedGrade < 1)
		throw GradeTooHighException();
	else if (_signedGrade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Bureacrat destructor called." << std::endl;
}

Form::Form(const Form& other):_name(other._name), _isSigned(other._isSigned), _signedGrade(other._signedGrade), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy constructor called." << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

const int& Form:: getSignedGrade() const
{
	return _signedGrade;
}

const std::string& Form:: getName() const
{
	return _name;
}

const bool& Form:: getIsSigned() const
{
	return _isSigned;
}

const int& Form:: getGradeToExecute() const
{
	return _gradeToExecute;
}

const char* Form::GradeTooHighException::what() const noexcept
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
    return "Grade too low";
}

void Form::beSigned(const Bureaucrat& member)
{
	if (member.getGrade() <= _signedGrade)
		_isSigned = true;
	else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	os << b.getName() << ", signing status: " << std::boolalpha << b.getIsSigned()
       << ", signing grade: " << b.getSignedGrade()
       << ", grade to execute: " << b.getGradeToExecute() << ".\n";
	return os;
}