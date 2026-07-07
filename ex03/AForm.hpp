#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
	public:
		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		void beSigned(const Bureaucrat& member);
		const int& getGradeToSign() const;
		const int& getGradeToExecute() const;
		const std::string& getName() const;
		const bool& getIsSigned() const;
		void execute(const Bureaucrat& executor) const;
	
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

		class FormUnsignedException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

	protected:
    	virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);