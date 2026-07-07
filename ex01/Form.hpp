#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signedGrade;
		const int			_gradeToExecute;
	
	public:
		Form();
		Form(const std::string name, const int signGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		void beSigned(const Bureaucrat& member);
		const int& getSignedGrade() const;
		const int& getGradeToExecute() const;
		const std::string& getName() const;
		const bool& getIsSigned() const;
	
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const Form& b);