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
		std::cout << a.getName() << ": " << a.getGrade() << std::endl;
		Bureaucrat b("Brian", 68);
		std::cout << b.getName() << ": " << b.getGrade() << std::endl;
		Bureaucrat c("Carry", 150);
		std::cout << c.getName() << ": " << c.getGrade() << std::endl;
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
		std::cout << a.getName() << ": " << a.getGrade() << std::endl;
		Bureaucrat b(a);
		std::cout << b.getName() << ": " << b.getGrade() << std::endl;
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
		std::cout << a.getName() << ": " << a.getGrade() << std::endl;
		Bureaucrat b("Brian", 68);
		std::cout << b.getName() << ": " << b.getGrade() << std::endl;
		a = b;
		std::cout << a.getName() << ": " << a.getGrade() << std::endl;
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
		std::cout << a.getName() << ": " << a.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	try
	{
		Bureaucrat b("Brian", 0);
		std::cout << b.getName() << ": " << b.getGrade() << std::endl;
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

	return 0;
}