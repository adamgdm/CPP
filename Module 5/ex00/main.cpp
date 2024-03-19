#include "Bureaucrat.hpp"

int main()
{
	// testing too high grade
    try
    {
        Bureaucrat b1("John Doe", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	// testing too low grade
    try
    {
        Bureaucrat b2("Jane Doe", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


	// testing implementation of the increment and decrement
    try
    {
        Bureaucrat b3("Average Joe", 75);
        std::cout << b3 << std::endl;

        b3.incrementGrade();
        std::cout << b3 << std::endl;

        b3.decrementGrade();
        std::cout << b3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}