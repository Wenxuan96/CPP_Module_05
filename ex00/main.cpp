#include "Bureaucrat.hpp"

static void prtLine(std::string s)
{
	std::cout << BLUE << "\n========== " << s << " ==========\n" << RESET << std::endl;
}

static void testDefaultConstructor()
{
	prtLine("Test Default Constructor");
	try
	{
		Bureaucrat a;
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET <<'\n';
	}
}

static void testParamConstructor()
{
	prtLine("Test Param Constructor");
	try
	{
		Bureaucrat a("Abbey", 26);
		std::cout << a;
		Bureaucrat b("Brian", 68);
		std::cout << b;
		Bureaucrat c("Carry", 150);
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
		Bureaucrat a("Abbey", 26);
		std::cout << a;
		Bureaucrat b(a);
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
		Bureaucrat a("Abbey", 26);
		std::cout << a;
		Bureaucrat b("Brian", 68);
		std::cout << b;
		a = b;
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}	
}

static void testInvalidGrades()
{
	prtLine("Test Invalid Grades");
	try
	{
		Bureaucrat a("Abbey", 260);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	try
	{
		Bureaucrat b("Brian", 0);
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

static void testIncremantGrades()
{
	prtLine("Test Incremant Grades");
	try
	{
		Bureaucrat a("Abbey", 12);
		for (int i = 0; i < 12; i++)
		{
			a.incrementGrade();
			std::cout << a;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}


static void testDecremantGrades()
{
	prtLine("Test Decremant Grades");
	try
	{
		Bureaucrat a("Abbey", 135);
		for (int i = 0; i < 20; i++)
		{
			a.decrementGrade();
			std::cout << a;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

int main(void)
{
	testDefaultConstructor();
    testParamConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testInvalidGrades();
	testIncremantGrades();
	testDecremantGrades();

	return 0;
}