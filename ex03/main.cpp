#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	AForm* form;

	form = someRandomIntern.makeForm("robotomy request", "Bender");

	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	return 0;
}