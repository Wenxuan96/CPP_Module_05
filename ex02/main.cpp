#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void prtLine(std::string s)
{
	std::cout << BLUE << "\n========== " << s << " ==========\n" 
	          << RESET << std::endl;
}

static void testFormConstructors()
{
	prtLine("Test Form Constructors");

	try
	{
		ShrubberyCreationForm a("home");
		RobotomyRequestForm b("Bender");
		PresidentialPardonForm c("Arthur");

		std::cout << a;
		std::cout << b;
		std::cout << c;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

static void testCopyConstructor()
{
	prtLine("Test Copy Constructor");

	try
	{
		ShrubberyCreationForm a("garden");
		ShrubberyCreationForm b(a);

		std::cout << a;
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

static void testAssignmentOperator()
{
	prtLine("Test Assignment Operator");

	try
	{
		ShrubberyCreationForm a("home");
		ShrubberyCreationForm b("office");

		std::cout << a;
		std::cout << b;

		a = b;

		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

static void testSigning()
{
	prtLine("Test Signing Forms");

	try
	{
		Bureaucrat high("High Grade", 1);
		Bureaucrat low("Low Grade", 150);

		ShrubberyCreationForm shrub("tree");
		RobotomyRequestForm robot("Robot");
		PresidentialPardonForm pardon("Arthur");

		std::cout << high;
		std::cout << low;

		high.signForm(shrub);
		high.signForm(robot);
		high.signForm(pardon);

		std::cout << shrub;
		std::cout << robot;
		std::cout << pardon;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

static void testFailedSigning()
{
	prtLine("Test Failed Signing");

	try
	{
		Bureaucrat low("Low Grade", 150);

		PresidentialPardonForm pardon("Arthur");

		std::cout << low;
		low.signForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

static void testExecution()
{
	prtLine("Test Execution");

	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat worker("Worker", 100);

		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Marvin");
		PresidentialPardonForm pardon("Ford");

		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);

		boss.executeForm(shrub);
		boss.executeForm(robot);
		boss.executeForm(pardon);

		worker.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

int main(void)
{
	testFormConstructors();
	testCopyConstructor();
	testAssignmentOperator();
	testSigning();
	testFailedSigning();
	testExecution();

	return 0;
}