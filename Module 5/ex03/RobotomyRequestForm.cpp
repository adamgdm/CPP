#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: Form("RobotomyRequestForm", 72, 45)
{
	if (getReqSignGrade() < 1 || getReqExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (getReqSignGrade() > 72 || getReqExecGrade() > 45)
		throw Form::GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: Form("RobotomyRequestForm", 72, 45), target(target)
{
	if (getReqSignGrade() < 1 || getReqExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (getReqSignGrade() > 72 || getReqExecGrade() > 45)
		throw Form::GradeTooLowException();
}

RobotomyRequestForm::~RobotomyRequestForm() 
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) 
	: Form(copy)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
		Form::operator=(copy);
	return (*this);	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{ 
	int i;

	if (!this->isFormSigned())
        throw Form::FormIsNotSignedException();
    if (executor.getGrade() > this->getReqExecGrade())
        throw Form::GradeTooLowException();

	std::cout << "BRRRRrrrrRRRRRrrrrr BBRRrrrrrrrRRRrrRRRRRrrrrr" << std::endl;
	i = rand() % 2;
	if (i == 0)
		std::cout << this->target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "Womp Womp, " << this->target << " robotomization has failed" << std::endl;
}
