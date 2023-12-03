#include "main.hpp"

std::string replace_tabs_with_spaces(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}

int IsStringWhiteSpaces(std::string Ctring)
{
	const char *ptr = Ctring.c_str();
	int index;

	index = 0;
	while (ptr[index])
	{
		if (ptr[index] <= ' ' || ptr[index] == 127)
			index++;
		else
			break ;
	}
	if (ptr[index] == '\0')
		return (1);
	return (0);
}

int ft_add_infos(std::string &str, std::string typainfo)
{
	std::cout << "\033[33mEnter " << typainfo << ": \033[37m";
	str.clear();
	while (str == "")
	{
		std::getline(std::cin, str);
		str = replace_tabs_with_spaces(str);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exit..." << std::endl;
			return (-1);
		}
		if (str == "" || IsStringWhiteSpaces(str) == 1)
		{
			std::cout << "\033[31mError: " << typainfo << " cannot be empty !\n" << "\033[33mEnter " << typainfo << ": \033[37m";
			str.clear();
		}
	}
	return (0);
}

int main()
{
	Phonebook phonebook;
	std::string command;
	std::string info[5];
	int i = 0;

	while (1)
	{
		std::cout << "Phonebook > ";
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
		{
			if (command == "")
				std::cout << std::endl;
			std::cout << "Exit..." << std::endl;
			break ;
		}
		else if (command == "ADD")
		{
			if (ft_add_infos(info[0], "first name") == -1)
				break ;
			if (ft_add_infos(info[1], "last name") == -1)
				break ;
			if (ft_add_infos(info[2], "nickname") == -1)
				break ;
			if (ft_add_infos(info[3], "phone number") == -1)
				break ;
			if (ft_add_infos(info[4], "darkest secret") == -1)
				break ;
			phonebook.add_contact(i, info[0], info[1], info[2] , info[3], info[4]);
			i = (i + 1) % 8;
		}
		else if (command == "SEARCH")
			phonebook.search_contact();
		else
			std::cout << "\033[31mError: Invalid command!\033[37m" << std::endl;
	}
}