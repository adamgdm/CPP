#ifndef ROOBOTOMY_FORM
#define ROOBOTOMY_FORM

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

		virtual void execute(Bureaucrat const & executor) const;
};

#endif