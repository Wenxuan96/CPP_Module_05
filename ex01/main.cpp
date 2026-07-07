#include "Bureaucrat.hpp"
#include "Form.hpp"

static void prtLine(std::string s)
{
	std::cout << BLUE << "\n========== " << s << " ==========\n" << RESET << std::endl;
}

static void testDefaultConstructor()
{
	prtLine("Test Default Constructor");
	try
	{
		Form a;
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
		Form a("Abbey", 26);
		std::cout << a;
		Form b("Brian", 68);
		std::cout << b;
		Form c("Carry", 150);
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
		Form a("Abbey", 26);
		std::cout << a;
		Form b(a);
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
		Form a("Abbey", 26);
		std::cout << a;
		Form b("Brian", 68);
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
		Form a("Abbey", 260);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	try
	{
		Form b("Brian", 0);
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

static void testSignForm()
{
	prtLine("Test Sign Form");
	try
	{
		Bureaucrat a("Abbey", 1);
		std::cout << a;
		Form b("Blair", 1);
		std::cout << b;
		Form c("Charlie", 40);
		std::cout << c;
		a.signForm(b);
		a.signForm(c);
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
	testSignForm();

	return 0;
}