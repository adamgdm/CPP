#include "Bureaucrat.hpp"
int main()
{
	// ----- TESTING EXCEPTIONS OF AFormS
		// Initializing for with a value outside of scope, 
		// Edit the Scope variable for x > 150 or x < 1 values to catch exceptions
		// For Normal Init, Value should be 1 <= x <= 150

	int scope;
	
	scope = 157;
	try
	{
		Bureaucrat joseph("Joseph", 67);
		AForm frmA("1A", 65, scope);
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// ----- TESTING << OPERATOR

	AForm frmB("2A", 25, 10);

	std::cout << frmB << std::endl;

	// ----- TESTING beSigned()

		// Declaring Bureaucrat

	Bureaucrat Noob("Noobie", 69);

		// Testing the Exception

	try
	{
		frmB.beSigned(Noob);
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cerr << "Failure to sign due to the reason : \"" << e.what() << "\"" << std::endl;
	}

	// ----- TESTING 

		// Declaring New Bureaucrat

	Bureaucrat Pro("Chinwi", 2);

		// Testing in case of Success

	Pro.signAForm(frmB);

		// Testing in case of failure

	Noob.signAForm(frmB);

    return 0;
}