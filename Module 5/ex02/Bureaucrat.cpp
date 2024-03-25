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
		std::cerr << this->getName() << RED << " couldn't sign " << RESET << doc.getName()
			<< RED << " because " << BOLD << RED << e.what() << RESET << std::endl; 
		return ;
	}
	std::cerr << this->getName() << " signed " << doc.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const & form)
{
	if (form.getReqExecGrade() >= this->grade)
	{
		std::cout << YELLOW << "Bureaucrat \"" << RESET << this->name << YELLOW << "\" is executing \"" 
			<< RESET << form.getName() << "\"." << std::endl;
		form.execute(*this);
		std::cout << this->name << GREEN << " Executed " << RESET << form.getName() << std::endl;
	}
	else
		std::cout << RED << "Bureaucrat \"" << RESET << this->name << RED << "\" cannot execute \"" 
			<< RESET << form.getName() << BOLD << RED << "\" due to their low grade!." << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ex)
{
	os << ex.getName() << ", bureaucrat grade " << ex.getGrade();
	return (os);
}