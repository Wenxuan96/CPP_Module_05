#pragma once
#include <iostream>
#include <string>

class Bureucrat
{
	private:
		const std::string name;
		int				  grade;
	
	public:
		Bureucrat();
		Bureucrat(const std::string name, int grade);
		Bureucrat(const Bureucrat& other);
		Bureucrat& operator=(const Bureucrat& other);
		~Bureucrat();
		const std::string getName();
		const int getGrade();
};