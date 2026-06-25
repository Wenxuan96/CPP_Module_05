#include "Bureaucrat.hpp"

Bureucrat::Bureucrat():name(""), grade(0){}

Bureucrat::Bureucrat(const std::string name, int grade):name(name), grade(grade){}

Bureucrat::Bureucrat(const Bureucrat& other):name(other.name),grade(other.grade){}

Bureucrat& Bureucrat::operator=(const Bureucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return *this;
}