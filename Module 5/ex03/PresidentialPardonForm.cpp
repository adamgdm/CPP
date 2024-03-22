#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: Form("PresidentialPardonForm", 25, 5)
{
	if (getReqSignGrade() < 1 || getReqExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (getReqSignGrade() > 25 || getReqExecGrade() > 5)
		throw Form::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
	: Form("PresidentialPardonForm", 25, 5), target(target)
{
	if (getReqSignGrade() < 1 || getReqExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (getReqSignGrade() > 25 || getReqExecGrade() > 5)
		throw Form::GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm() 
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) 
	: Form(copy)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
		Form::operator=(copy);
	return (*this);	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{    
	if (!this->isFormSigned())
        throw Form::FormIsNotSignedException();
    if (executor.getGrade() > this->getReqExecGrade())
        throw Form::GradeTooLowException();

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}