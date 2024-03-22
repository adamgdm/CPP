#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		std::cerr << RED << BOLD << "Error: " << RESET 
			<< RED << "Please Provide an argument!" << std::endl;
	else if (ac > 2)
		std::cerr << RED << BOLD << "Error: " << RESET 
			<< RED << "Only one argument required!" << std::endl;
	else
		ScalarConverter::convert(av[1]);
}