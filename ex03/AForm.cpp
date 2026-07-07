#include "AForm.hpp"

AForm::AForm():_name(""), _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
	std::cout << "AForm: Default constructor called. Grade is neither signed nor executed, grade set to 0." << std::endl;
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute):_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm: Parameterized constructor called." << std::endl;
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "AForm: Bureacrat destructor called." << std::endl;
}

AForm::AForm(const AForm& other):_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm: Copy constructor called." << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm: Copy assignment operator called." << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

const int& AForm:: getGradeToSign() const
{
	return _gradeToSign;
}

const std::string& AForm:: getName() const
{
	return _name;
}

const bool& AForm:: getIsSigned() const
{
	return _isSigned;
}

const int& AForm:: getGradeToExecute() const
{
	return _gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const noexcept
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "Grade too low";
}

const char* AForm::FormUnsignedException::what() const noexcept
{
	return "Form Unsigned.";
}

void AForm::beSigned(const Bureaucrat& member)
{
	if (member.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
        throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (_isSigned == false)
		throw FormUnsignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	
	executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
	os << b.getName() << ", signing status: " << std::boolalpha << b.getIsSigned()
       << ", signing grade: " << b.getGradeToSign()
       << ", grade to execute: " << b.getGradeToExecute() << ".\n";
	return os;
}