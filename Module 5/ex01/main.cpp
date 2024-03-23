#include "Bureaucrat.hpp"
int main()
{
	// ----- TESTING EXCEPTIONS OF FORMS
		// Initializing for with a value outside of scope, 
		// Edit the Scope variable for x > 150 or x < 1 values to catch exceptions
		// For Normal Init, Value should be 1 <= x <= 150

	int scope;
	
	scope = 148;
	try
	{
		Bureaucrat joseph("Joseph", 67);
		Form frmA("1A", 65, scope);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// ----- TESTING << OPERATOR

	Form frmB("2A", 25, 10);

	std::cout << "Testing << operator : " << std::endl;

	std::cout << "	" << frmB << std::endl << std::endl;

	// ----- TESTING beSigned()

		// Declaring Bureaucrat

	Bureaucrat Noob("Noobie", 69);

		// Testing the Exception

	std::cout << "Testing beSigned() : " << std::endl;

	try
	{
		frmB.beSigned(Noob);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << "	Failure to sign due to the reason : \"" << e.what() << "\"" << std::endl << std::endl;;
	}

	// ----- TESTING 

		// Declaring New Bureaucrat

	Bureaucrat Pro("Chinwi", 2);

		// Testing in case of Success

	std::cout << "Testing signForm() in both case of success and failure : " << std::endl  << std::endl;;

	Pro.signForm(frmB);

		// Testing in case of failure

	Noob.signForm(frmB);

    return 0;
}