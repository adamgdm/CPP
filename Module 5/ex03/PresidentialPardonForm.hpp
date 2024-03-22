#ifndef PRESIDENTIAL_FORM
#define PRESIDENTIAL_FORM

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

		virtual void execute(Bureaucrat const & executor) const;
};

#endif