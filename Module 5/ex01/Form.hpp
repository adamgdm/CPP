#ifndef _FORM_HPP
#define _FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form 
{
	private:
		const std::string name;
		bool isSigned;
		const int reqSignGrade;
		const int reqExecGrade;
	public:
		Form(std::string name, const int reqSign, const int reqExec);
		Form(const Form &other);
		~Form();
		Form &operator=(const Form &other); 

		std::string getName();
		bool isFormSigned();
		int getReqSignGrade();
		int getReqExecGrade();

		void beSigned(const Bureaucrat &p);
		void signForm();

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Error: Your Grade is Too Low!");
				}
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Error: Your Grade is Too High!");
				}
		};
};

std::ostream &operator<<(std::ostream& os, Form &doc);

#endif