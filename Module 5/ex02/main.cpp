#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // Create bureaucrats with different grades
    Bureaucrat Pro("PRO", 1);
    Bureaucrat Noob("Noob", 150);

    // Create forms
    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Robot");
    PresidentialPardonForm presidentialForm("Criminal");

    // Attempt to sign and execute forms with high grade bureaucrat
    std::cout << "\n--- High Grade Bureaucrat ---\n" << std::endl << std::endl;

	std::cout << "Attemting to execute a non signed Form, Result :" << std::endl;
	try {
    	Pro.executeForm(shrubberyForm);
	}
	catch (Form::FormIsNotSignedException& e)
	{
		std::cout << "Form Wasn't executed because :\n\t" << e.what() << std::endl;
	}

	std::cout << "Proceeding..." << std::endl;

	std::cout << std::endl;

    Pro.signForm(shrubberyForm);
    Pro.executeForm(shrubberyForm);

	std::cout << std::endl;

    Pro.signForm(robotomyForm);
    Pro.executeForm(robotomyForm);

	std::cout << std::endl;

    Pro.signForm(presidentialForm);
    Pro.executeForm(presidentialForm);

	std::cout << std::endl;

    // Attempt to sign and execute forms with low grade bureaucrat
    std::cout << "\n--- Low Grade Bureaucrat ---\n" << std::endl << std::endl;
    Noob.signForm(shrubberyForm);
    Noob.executeForm(shrubberyForm);

	std::cout << std::endl;

    Noob.signForm(robotomyForm);
    Noob.executeForm(robotomyForm);

	std::cout << std::endl;

    Noob.signForm(presidentialForm);
    Noob.executeForm(presidentialForm);

	std::cout << std::endl;

    return 0;
}