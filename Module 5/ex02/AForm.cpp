#include "AForm.hpp"

AForm::AForm(std::string name, const int reqSign, const int reqExec) : name(name), reqSignGrade(reqSign), reqExecGrade(reqExec)
{
	if (reqExecGrade < 1 || reqSignGrade < 1)
		throw AForm::GradeTooHighException();
	if (reqExecGrade > 150 || reqSignGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), 
	reqSignGrade(other.reqSignGrade), reqExecGrade(other.reqExecGrade)
{

}

AForm::~AForm()
{

}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

std::string AForm::getName()
{
	return (this->name);
}

bool AForm::isAFormSigned()
{
	return (this->isSigned);
}

int AForm::getReqSignGrade()
{
	return (this->reqSignGrade);
}

int AForm::getReqExecGrade()
{
	return (this->reqExecGrade);
}

void AForm::beSigned(const Bureaucrat &p)
{
	int gradeOfBureaucrat;

	gradeOfBureaucrat = p.getGrade();
	if (gradeOfBureaucrat <= this->reqSignGrade)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream& os, AForm &doc)
{
	std::string boolVal;

	if (doc.isAFormSigned() == true)
		boolVal = "Signed";
	else
		boolVal = "Not Signed Yet";
	os << "Doc Name: \"" << doc.getName() << "\", Status: \"" << boolVal 
		<< "\", Required Grade to Sign : \"" << doc.getReqSignGrade()
		<< "\", Required Grade to Execute : \"" << doc.getReqExecGrade();
	return (os);
}
