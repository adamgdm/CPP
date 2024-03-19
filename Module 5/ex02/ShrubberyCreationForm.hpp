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

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, const int reqSign, const int reqExec) 
	: AForm(name, reqSign, reqExec)
{
	if (reqSign < 1 || reqExec < 1)
		throw AForm::GradeTooHighException();
	else if (reqSign > 145 || reqExec > 137)
		throw AForm::GradeTooLowException();
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) 
	: AForm(copy)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{

}

#endif