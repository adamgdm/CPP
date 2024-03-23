#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{
	
}

Intern::Intern(const Intern& copy)
{
	*this = copy; 
}

Intern &Intern::operator=(const Intern &copy)
{
	if (this != &copy)
		(*this) = (copy);
	return (*this);
}

Form *MakeShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *MakeRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *MakePresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string name, std::string target)
{
	int i;

	i = 0;
	std::string names[3] = {
		"Shrrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon"
	};

	Form* (*Form[3])(std::string target) = {
		&MakeShrubberyForm,
		&MakeRobotomyForm,
		&MakePresidentialForm		
	};
	
	while (i < 3)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << " Form" << std::endl;
			return Form[i](target);
		}
		i++;
	}
	std::cout << RED << "Invalid Form Name!" << RESET << std::endl;
	return (NULL);
}
