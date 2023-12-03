#include "main.hpp"

void displayContent(int i, std::string info[5])
{
	if (info[0] == "")
	{
		if (i == 0)
			std::cout << "Error: TABLO KHAWI!" << std::endl;
		return ;
	}
	if (i == 0)
	{
		std::cout << "+----------+----------+----------+----------+" << std::endl;
		std::cout << "|  Index   |First Name|Last  Name| Nickname |" << std::endl;
		std::cout << "+----------+----------+----------+----------+" << std::endl;
	}
	std::cout << "|         " << i + 1 << "|"
    << std::setw(10) << std::setfill(' ') << info[0] << "|"
	<< std::setw(10) << std::setfill(' ') << info[1] << "|"
	<< std::setw(10) << std::setfill(' ') << info[2] << "|"
	<< std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void Phonebook::add_contact(int index, std::string first, std::string last, std::string nickname, std::string number, std::string secret)
{
	contacts[index] = Contact(first, last, nickname, number, secret);
}

std::string Phonebook::truncateToTen(std::string str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str.append(".");
	}
	return (str);
}


void Phonebook::search_contact()
{
	std::string info[5];
	int i = 0;

	for (int i = 0; i < 8; i++)
	{
		info[0] = truncateToTen(contacts[i].retrieve_first());
		info[1] = truncateToTen(contacts[i].retrieve_last());
		info[2] = truncateToTen(contacts[i].retrieve_nickname());
		displayContent(i, info);
		if (i == 0 && info[0] == "")
			return ;
	}
	while (1)
	{
		std::string line;
		i = -1;
		std::cout << " -> Enter index (PRESS 0 TO GO BACK): ";
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exit..." << std::endl;
			exit(0);
		}
		i = std::atoi(line.c_str());
		if (i == 0)
			break ;
		if (i > 0 && i < 9)
		{
			if (contacts[i - 1].retrieve_is_full() == 0)
			{
				std::cout << "ERROR : Contact is empty!" << std::endl;
				continue ;
			}
			std::cout << "\033[37m" << "+----------------------------------------------------------------------------+" << std::endl;
			std::cout << "| " << contacts[i - 1].retrieve_first() << contacts[i - 1].retrieve_last() << "'s Contact Informations"  <<  std::endl;
			std::cout << "\033[37m" << "+----------------------------------------------------------------------------+" << std::endl;
			std::cout << "| * Index : " << "\033[32m" << i << std::endl;
			std::cout << "\033[37m" << "+----------------------------------------------------------------------------+" << std::endl;
			i = i - 1;
			std::cout << "| * First Name : " << "\033[32m" << contacts[i].retrieve_first() << std::endl;
			std::cout << "\033[37m" << "+----------------------------------------------------------------------------+" << std::endl;
			std::cout << "| * Last Name : " << "\033[32m" << contacts[i].retrieve_last() << std::endl;
			std::cout << "\033[37m" << "+----------------------------------------------------------------------------+" << std::endl;
			std::cout << "| * Number : " << "\033[32m" << contacts[i].retrieve_number() << std::endl;
			std::cout << "\033[37m" << "+----------------------------------------------------------------------------+" << std::endl;
			std::cout << "| * NickName : " << "\033[32m" << contacts[i].retrieve_nickname() << std::endl;
			std::cout << "\033[37m" << "+----------------------------------------------------------------------------+" << std::endl;
			std::cout << "| * Darkest Secret : " << "\033[32m" << contacts[i].retrieve_secret() << std::endl;
			std::cout << "\033[37m" << "+----------------------------------------------------------------------------+" << std::endl;
			break ;
		}
		else
			std::cout << "ERROR : Invalid Index!" << std::endl;
	}
}
