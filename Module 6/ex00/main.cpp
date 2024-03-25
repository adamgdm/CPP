#include "ScalarConverter.hpp"

void printingMachine(char* c, int* i, float* f, double* d)
{
    if (c && *c > 31 && *c != 127)
        std::cout << "char: '" << *c << "\'" << std::endl;
    else if (c)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    if (i)
        std::cout << "int: " << *i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    if (f)
        std::cout << std::fixed << std::setprecision(1) << "float: " << *f << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;

    if (d)
        std::cout << std::fixed << std::setprecision(1) << "double: " << *d << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

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