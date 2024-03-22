#ifndef SHRUBBERY_FORM
#define SHRUBBERY_FORM

#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

		virtual void execute(Bureaucrat const & executor) const;
};

#endif