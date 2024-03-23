#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"  
#define GREEN   "\033[32m"    
#define YELLOW  "\033[33m"     
#define BLUE    "\033[34m"   
#define MAGENTA "\033[35m" 
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"   
#define BOLD    "\033[1m"   

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &other);

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(Form &doc);
		void executeForm(Form const & form);

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ex);

#endif