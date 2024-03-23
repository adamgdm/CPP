#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp" 

int main()
{
	Intern intern;

    // Test with valid form names
    std::string validNames[3] = {
        "Shrrubbery Creation",
        "Robotomy Request",
        "Presidential Pardon"
    };

    for (int i = 0; i < 3; i++)
    {
        Form* form = intern.makeForm(validNames[i], "target");
        if (form != NULL)
        {
            std::cout << "Successfully created " << validNames[i] << std::endl << std::endl;
			delete form;
        }
        else
        {
            std::cout << RED << "Failed to create " << validNames[i] << RESET << std::endl << std::endl;
        }
    }

    // Test with invalid form name
    std::string invalidName = "Unknown";
    Form* form = intern.makeForm(invalidName, "target");
    if (form != NULL)
    {
        std::cout << GREEN << "Successfully created " << RESET << invalidName << std::endl << std::endl;
        delete form;
    }
    else
    {
        std::cout << RED << "Failed to create " << RESET << invalidName << std::endl << std::endl;
    }
    return 0;
}