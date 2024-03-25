#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	(*this) = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	else
		this->grade++;
}

void Bureaucrat::signForm(Form &doc)
{
	try
	{
		doc.beSigned(*this);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << this->getName() << " couldn't sign " << doc.getName() 
			<< " because " << e.what() << std::endl; 
		return ;
	}
	std::cerr << this->getName() << " signed " << doc.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ex)
{
	os << ex.getName() << ", bureaucrat grade " << ex.getGrade();
	return (os);
}