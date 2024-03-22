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
            std::cout << "Successfully created " << validNames[i] << std::endl;
			delete form;
        }
        else
        {
            std::cout << RED << "Failed to create " << validNames[i] << RESET << std::endl;
        }
    }

    // Test with invalid form name
    Form* form = intern.makeForm("Invalid Form Name", "target");
    if (form != NULL)
    {
        std::cout << "Successfully created Invalid Form Name" << std::endl;
        delete form;
    }
    else
    {
        std::cout << RED << "Failed to create Invalid Form Name" << RESET << std::endl;
    }
    return 0;
}