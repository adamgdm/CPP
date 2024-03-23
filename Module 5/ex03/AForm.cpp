#include "AForm.hpp"

Form::Form(std::string name, const int reqSign, const int reqExec) : name(name), reqSignGrade(reqSign), reqExecGrade(reqExec)
{
	this->isSigned = false;
	if (reqExecGrade < 1 || reqSignGrade < 1)
		throw Form::GradeTooHighException();
	if (reqExecGrade > 150 || reqSignGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), 
	reqSignGrade(other.reqSignGrade), reqExecGrade(other.reqExecGrade)
{

}

Form::~Form()
{

}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::isFormSigned() const
{
	return (this->isSigned);
}

int Form::getReqSignGrade() const
{
	return (this->reqSignGrade);
}

int Form::getReqExecGrade() const
{
	return (this->reqExecGrade);
}

void Form::beSigned(const Bureaucrat &p)
{
	int gradeOfBureaucrat;

	gradeOfBureaucrat = p.getGrade();
	if (gradeOfBureaucrat <= this->reqSignGrade)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream& os, Form &doc)
{
	std::string boolVal;

	if (doc.isFormSigned() == true)
		boolVal = "Signed";
	else
		boolVal = "Not Signed Yet";
	os << "Doc Name: \"" << doc.getName() << "\", Status: \"" << boolVal 
		<< "\", Required Grade to Sign : \"" << doc.getReqSignGrade()
		<< "\", Required Grade to Execute : \"" << doc.getReqExecGrade();
	return (os);
}
