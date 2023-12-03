#ifndef PHONEBOOK_PHONEBOOK_HPP
# define PHONEBOOK_PHONEBOOK_HPP

#include <iostream>
#include <string>

class Phonebook
{
	private:
		Contact contacts[8];
	public:
		void add_contact(int index, std::string first, std::string last, std::string nickname, std::string number, std::string secret);
		void search_contact();	
		std::string truncateToTen(std::string str);
		void print_contact();
};

#endif