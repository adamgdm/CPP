#ifndef _Form_HPP
#define _Form_HPP

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
		Form();
		Form(std::string name, const int reqSign, const int reqExec);
		Form(const Form &other);
		~Form();
		Form &operator=(const Form &other); 

		std::string getName() const;
		bool isFormSigned() const;
		int getReqSignGrade() const;
		int getReqExecGrade() const;

		void beSigned(const Bureaucrat &p);
		void signForm();

		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("\033[31m\033[1mError: Your Grade is Too Low!\033[0m");
				}
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("\033[31m\033[1mError: Your Grade is Too High!\033[0m");
				}
		};
		class FormIsNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("\033[31m\033[1mError: Attempting to execute a Form that was not signed Yet!\033[0m");
				}
		};
};

std::ostream &operator<<(std::ostream& os, Form &doc);

#endif