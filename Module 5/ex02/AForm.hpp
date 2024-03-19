#ifndef _AForm_HPP
#define _AForm_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm 
{
	private:
		const std::string name;
		bool isSigned;
		const int reqSignGrade;
		const int reqExecGrade;
	public:
		AForm(std::string name, const int reqSign, const int reqExec);
		AForm(const AForm &other);
		~AForm();
		AForm &operator=(const AForm &other); 

		std::string getName();
		bool isAFormSigned();
		int getReqSignGrade();
		int getReqExecGrade();

		void beSigned(const Bureaucrat &p);
		void signAForm();

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

std::ostream &operator<<(std::ostream& os, AForm &doc);

#endif