#ifndef SHRUBBERY_FORM
#define SHRUBBERY_FORM

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string name, const int reqSign, const int reqExec);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, const int reqSign,
	const int reqExec) : name(name), reqSignGrade(reqSign), reqExecGrade(reqExec);
{

}

#endif