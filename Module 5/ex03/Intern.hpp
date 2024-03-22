#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern &operator=(const Intern &copy);

		Form *makeForm(std::string name, std::string target);
};

#endif