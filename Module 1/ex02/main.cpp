#include <iostream>
#include <string>

int main()
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = var;

	std::cout << "-> Memory Addresses: " << std::endl;
	std::cout << std::endl;

	std::cout << &var << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "-> Content: " << std::endl;
	std::cout << std::endl;
	
	std::cout << var << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}